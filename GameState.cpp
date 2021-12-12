#include "GameState.h"
#include <iostream>
#include "memory"
#include "Definition.h"
#include "GameOverState.h"
#include "GameObject.h"


GameState::GameState(GameDataRef data)
	: m_data(data)
{
	m_factory = std::make_shared<ObjectFactory>(data);
}

// loads texture to asset manager
void GameState::Init()
{
	std::cout << "Entered Game State\n";

	m_background.setTexture(this->m_data->assets.GetTexture("Game State Background"));
	for (size_t i = 0; i < 5; ++i)
	{
		m_player.push_back(m_factory->MakePlayer());
	}
	m_roundCounter++;

	for (size_t i = 0; i < 10; ++i)
	{
		m_pTargetList.push_back(m_factory->MakeAI());
	}
	m_scoreText.setFont(m_data->assets.GetFont("Game Font"));
	m_scoreText.setCharacterSize(80);
	m_scoreText.setPosition((m_data->window.getSize().x / 2) - 10, 0);

	m_roundText.setFont(m_data->assets.GetFont("Game Font"));
	m_roundText.setCharacterSize(80);
	m_roundText.setPosition((m_data->window.getSize().x) - 80, 0);

	m_livesText.setFont(m_data->assets.GetFont("Game Font"));
	m_livesText.setCharacterSize(80);
	m_livesText.setPosition(40, 0);

	InGameMusic();
}


void GameState::HandleInput()
{
	sf::Event event;

	while (this->m_data->window.pollEvent(event))
	{
		if (sf::Event::Closed == event.type)
		{
			this->m_data->window.close();
		}
	}
}


void GameState::Update(float dt)
{
	//end game check
	////////////////////////////////////////////////////////
	EndGameCheck();
	////////////////////////////////////////////////////////

	//Player Update calls
	////////////////////////////////////////////////////////
    PlayerUpdate(dt);
	////////////////////////////////////////////////////////

	//AI Update calls
	////////////////////////////////////////////////////////
	AIUpdate(dt);
	////////////////////////////////////////////////////////

	//Projectile Update calls
	////////////////////////////////////////////////////////
	ProjectileUpdate(dt);
	////////////////////////////////////////////////////////

	//Collision Dection 
	////////////////////////////////////////////////////////
	CollisionDetection();
	//CollisionDetection_Prototype();
	////////////////////////////////////////////////////////
	
	// Projectile delete Manager
	////////////////////////////////////////////////////////
	ProjectileCleaner();
	////////////////////////////////////////////////////////
	
	//Text
    ////////////////////////////////////////////////////////
	m_playerLives = static_cast<sf::Int32>(m_player.size());
	m_livesText.setString(toString(m_playerLives));
	m_scoreText.setString(toString(m_playerScore));
	m_roundText.setString(toString(m_roundCounter));

	//Music
    ////////////////////////////////////////////////////////
	if (m_musicTimer.getElapsedTime().asSeconds() > 234)
	{
		InGameMusic();
		m_musicTimer.restart();
	}
}

//renders state 
void GameState::Draw()
{
	//Error color
	this->m_data->window.clear(sf::Color::Red);
	//Background layer
	this->m_data->window.draw(this->m_background);

	//player bullet layer
	if (!m_pPlayerBulletList.empty())
	{
		for (auto i : m_pPlayerBulletList)
		{
			if (i == nullptr)
			{
				continue;
			}
			i->Draw();
		}
	}
	//Player layer
	if (!m_player.empty())
		m_player.at(0)->Draw();

	//AI bullet layer
	if (!m_pAIBulletList.empty())
	{
		for (auto i : m_pAIBulletList)
		{
			if (i == nullptr)
			{
				continue;
			}
			i->Draw();
		}
	}
	//AI layer
	for (auto i : m_pTargetList)
	{
		if (i == nullptr)
			continue;

		i->Draw();
	}
	this->m_data->window.draw(m_scoreText);
	this->m_data->window.draw(m_livesText);
	this->m_data->window.draw(m_roundText);
	//Display Window
	this->m_data->window.display();

	/*sf::String score = static_cast<sf::String>(m_playerScore);*/

	

	
}


//end game check
////////////////////////////////////////////////////////
void GameState::EndGameCheck()
{
    if (m_pTargetList.empty())
	{
		//////////////////////////////////
		//Temp Clean up for projectiles
		m_pAIBulletList.clear();
		m_pPlayerBulletList.clear();
		//////////////////////////////////

       
        std::cout << "Round Count is: " << m_roundCounter << '\n';
		for (size_t i = 0; i < 10; ++i)
		{
			m_pTargetList.push_back(m_factory->MakeAI());
		}
		m_roundCounter++;
	}

	if (m_player.empty())
	{
		sf::Sound loss;
		loss.setBuffer(m_data->assets.GetSound("PlayerDeath Sound"));
		loss.play();

		//////////////////////////////////
        //Temp Clean up for projectiles
		m_pAIBulletList.clear();
		m_pPlayerBulletList.clear();
		//////////////////////////////////
		
		
		//boot leg way to sleep the thread and allow the deathsound to play 
		sf::Time time = sf::seconds(1.f);
		sleep(time);

		m_data->machine.AddState(std::make_unique<GameOverState>(m_data), true);
	}
}


//AI Update calls
////////////////////////////////////////////////////////
void GameState::AIUpdate(float dt)
{
	for (auto i : m_pTargetList)
	{
		i->Update(dt);
	}

	for (auto i : m_pTargetList)
	{
		sf::Time time = m_rateOfFire.getElapsedTime();
		if (i->OnUse())
		{
			if (time > sf::seconds(gAIRateOfFireInSeconds))
			{
				//std::cout << "AI Shot!\n";
				m_pAIBulletList.push_back(std::shared_ptr<GameObject>(m_factory->MakeProjectile(i->GetPOS(), gAIBulletYAxisAmount)));
				m_pAIBulletList.at(0)->MakeSound();
				m_rateOfFire.restart();
			}

		}
	}
}

//Projectile Update calls
////////////////////////////////////////////////////////
void GameState::ProjectileUpdate(float dt)
{
	if (!m_pPlayerBulletList.empty())
	{
		for (auto i : m_pPlayerBulletList)
		{
			i->Update(dt);
		}
	}
	if (!m_pAIBulletList.empty())
	{
		for (auto i : m_pAIBulletList)
		{
			i->Update(dt);
		}
	}
}

//Collision Dection 
////////////////////////////////////////////////////////
void GameState::CollisionDetection()
{	//TODO: Clean up
	for (auto& target : m_pAIBulletList)
	{
		for (auto& bullet : m_pPlayerBulletList)
		{
			const auto TargetNewEnd = std::remove_if
			(
				m_pTargetList.begin(), m_pTargetList.end(),
				[bullet, this](const std::shared_ptr<GameObject>& tar)
				{
					if (tar->GetSprite().getGlobalBounds().intersects(bullet->GetSprite().getGlobalBounds()))
					{
						m_playerScore += m_roundCounter;
						return true;
					}
					return false;
				}
			);

			const auto PlayerLivesNewEnd = std::remove_if
			(
				m_player.begin(), m_player.end(),
				[target, this](const std::shared_ptr<GameObject>& tar)
				{
					sf::Time time = m_spawnTimer.getElapsedTime();
					if (time > sf::seconds(1))
					{
						if (tar->GetSprite().getGlobalBounds().intersects(target->GetSprite().getGlobalBounds()))
						{
							std::cout << "Player Life Count is: " << (m_player.size() - 1) << '\n';
							m_spawnTimer.restart();
							return true;
						}
					}
					return false;
				}
			);
		
			m_player.erase(PlayerLivesNewEnd, m_player.end());

			m_pTargetList.erase(TargetNewEnd, m_pTargetList.end());

			if (!m_pTargetList.empty())
			{
				//m_pTargetList.at(0)->MakeSound();
				//boot leg way to sleep the thread and allow the deathsound to play 
				//sf::Time time = sf::seconds(0.01f);
				//sleep(time);
			}
		}
	}
}

//Collision Dection _prototype
////////////////////////////////////////////////////////
void GameState::CollisionDetection_Prototype()
{
	for (auto& i: m_pPlayerBulletList)
	{
		for (auto& j : m_pTargetList)
		{
			if (i->GetSprite().getGlobalBounds().intersects(j->GetSprite().getGlobalBounds()))
			{
				m_pRemovalPile.push_back(std::move(i));
				m_pRemovalPile.push_back(std::move(j));
			}

		}
	}
	m_pRemovalPile.clear();
}

void GameState::ProjectileCleaner()
{
	for (auto& bullet : m_pPlayerBulletList)
	{
		const auto PlayerBulletsNewEnd = std::remove_if
		(
			m_pPlayerBulletList.begin(), m_pPlayerBulletList.end(),
			[bullet, this](const std::shared_ptr<GameObject>& tar)
			{
				if (tar->GetSprite().getPosition().y < m_data->window.getSize().y / m_data->window.getSize().y)
				{
					//std::cout << "Player Bullet removed \n";
					return true;
				}
				return false;
			}
		);

		m_pPlayerBulletList.erase(PlayerBulletsNewEnd, m_pPlayerBulletList.end());
	}

	for (auto& bullet : m_pAIBulletList)
	{
		const auto PlayerBulletsNewEnd = std::remove_if
		(
			m_pAIBulletList.begin(), m_pAIBulletList.end(),
			[bullet, this](const std::shared_ptr<GameObject>& tar)
			{
				if (tar->GetSprite().getPosition().y > static_cast<float>(m_data->window.getSize().y))
				{
					//std::cout << "AI Bullet removed \n";
					return true;
				}
				return false;
			}
		);

		m_pAIBulletList.erase(PlayerBulletsNewEnd, m_pAIBulletList.end());
	}
}

//In-Game Music Player
////////////////////////////////////////////////////////
void GameState::InGameMusic()
{
	m_gameMusic.openFromFile("Resources/res/GameStateMusic.wav");
	m_gameMusic.play();
}

//Player Update calls
////////////////////////////////////////////////////////
void GameState::PlayerUpdate(float dt)
{
	if (!m_player.empty())
		m_player.at(0)->Update(dt);

	if (!m_player.empty())
		if (m_player.at(0)->OnUse())
		{
			m_pPlayerBulletList.push_back(std::shared_ptr<GameObject>(m_factory->MakeProjectile(m_player.at(0)->GetPOS(), -gPlayerBulletYAxisAmount)));
			m_pPlayerBulletList.at(0)->MakeSound();

		}
}

