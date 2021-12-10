#include "GameState.h"

#include <iostream>
#include "memory"
#include "Definition.h"
#include "GameOverState.h"
//#include "Bullet.h"
//#include "Player.h"
//#include "Target.h"
#include "GameObject.h"
GameState::GameState(GameDataRef data)
	: m_data(data)
{

}

// loads texture to asset manager
void GameState::Init()
{
	std::cout << "Entered Game State\n";
	this->m_data->assets.LoadTexture("Game State Background", gGameBackgroundFile);

	m_background.setTexture(this->m_data->assets.GetTexture("Game State Background"));

	m_data->assets.LoadTexture("Player Sprite", gPlayerSpriteFile);
	m_data->assets.LoadTexture("Target Sprite", gTargetSpriteFile);
	m_data->assets.LoadTexture("Bullet Sprite", gBulletSpriteFile);
	m_data->assets.LoadSound("Lazer Sound", gBulletSoundFile);
	m_data->assets.LoadSound("Boom Sound", gDeathSoundFile);
	m_data->assets.LoadSound("PlayerDeath Sound", gPlayerSoundFile);

	for (size_t i = 0; i < 5; ++i)
	{
		m_playerLives.push_back(std::make_shared<GameObject>(m_data));
	}

	m_roundCounter++;
	for (size_t i = 0; i < 10; ++i)
	{
		
		m_pTargetList.push_back(std::make_shared<GameObject>(m_data, i));
	}
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



	////////////////////////////////////////////////////////
}

//renders state 
void GameState::Draw(float interpolation)
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
	if (!m_playerLives.empty())
	m_playerLives.at(0)->Draw();

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
	//Display Window
	this->m_data->window.display();
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
			m_pTargetList.push_back(std::make_shared<GameObject>(m_data, i));
		}
		m_roundCounter++;
	}

	if (m_playerLives.empty())
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
			if (time > sf::seconds(1))
			{
				//std::cout << "AI Shot!\n";
				m_pAIBulletList.push_back(std::make_shared<GameObject>(m_data, i->GetPOS(), gAIBulletYAxisAmount));
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
						m_pTargetList.at(0)->MakeSound();

						//boot leg way to sleep the thread and allow the deathsound to play 
						sf::Time time = sf::seconds(0.01f);
						sleep(time);

						m_playerScore += m_roundCounter;
						std::cout << "Player Score is: " << m_playerScore << '\n';
						return true;
					}
					return false;
				}
			);

			const auto PlayerLivesNewEnd = std::remove_if
			(
				m_playerLives.begin(), m_playerLives.end(),
				[target, this](const std::shared_ptr<GameObject>& tar)
				{
					sf::Time time = m_spawnTimer.getElapsedTime();
					if (time > sf::seconds(1))
					{
						if (tar->GetSprite().getGlobalBounds().intersects(target->GetSprite().getGlobalBounds()))
						{
							std::cout << "Player Life Count is: " << m_playerLives.size() << '\n';
							m_spawnTimer.restart();
							return true;
						}
					}
					return false;
				}
			);
			m_playerLives.erase(PlayerLivesNewEnd, m_playerLives.end());

			m_pTargetList.erase(TargetNewEnd, m_pTargetList.end());
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

//Player Update calls
////////////////////////////////////////////////////////
void GameState::PlayerUpdate(float dt)
{
	if (!m_playerLives.empty())
		m_playerLives.at(0)->Update(dt);

	if (!m_playerLives.empty())
		if (m_playerLives.at(0)->OnUse())
		{
			m_pPlayerBulletList.push_back(std::make_shared<GameObject>(m_data, m_playerLives.at(0)->GetPOS(), -gPlayerBulletYAxisAmount));
			m_pPlayerBulletList.at(0)->MakeSound();

		}
}

