#include "GameState.h"
#include <iostream>
#include "memory"
#include "Definition.h"
#include "GameOverState.h"
#include "GameObject.h"


GameState::GameState(GameEngine::GameDataRef data)
	: m_data(data)
    ,m_player(nullptr)
{
	m_factory = std::make_shared<ObjectFactory>(data);
}

// loads texture to asset manager
void GameState::Init()
{
	std::cout << "Entered Game State\n";
	
	m_background.setTexture(this->m_data->assets.GetTexture("Game State Background"));
	m_roundCounter++;

	for (size_t i = 0; i < m_amountOfAI; ++i)
	{
		m_pTargetList.push_back(m_factory->MakeAI(i));
	}
	
	//////////////////////////////////////////////////////////////////////////////////
	//TODO: Move to function
	m_scoreText.setFont(m_data->assets.GetFont("Game Font"));
	m_scoreText.setCharacterSize(80);
	m_scoreText.setPosition(static_cast<float>(m_data->window.getSize().x) / static_cast<float>(2) - 10, 0);

	m_roundText.setFont(m_data->assets.GetFont("Game Font"));
	m_roundText.setCharacterSize(80);
	m_roundText.setPosition(static_cast<float>(m_data->window.getSize().x) - static_cast<float>(80), 0);

	m_livesText.setFont(m_data->assets.GetFont("Game Font"));
	m_livesText.setCharacterSize(80);
	m_livesText.setPosition(40, 0);

	m_spawnShieldTimer.setFont(m_data->assets.GetFont("Game Font"));
	m_spawnShieldTimer.setCharacterSize(80);
	m_spawnShieldTimer.setPosition(static_cast<float>(m_data->window.getSize().x) / static_cast<float>(2) - 10, 30);
	//////////////////////////////////////////////////////////////////////////////////
	

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
	////////////////////////////////////////////////////////
	
	// Projectile delete Manager
	////////////////////////////////////////////////////////
	m_data->grabage.Cleaner(m_pPlayerBulletList, &m_data->window, ObjectCleaner::Type::kPlayerBullet);
	m_data->grabage.Cleaner(m_pAIBulletList, &m_data->window, ObjectCleaner::Type::kEnemyBullet);
	m_data->grabage.Cleaner(m_pTargetList, &m_data->window, ObjectCleaner::Type::kEnemy);
	////////////////////////////////////////////////////////

	//TODO: Move to function
	//Text
    ////////////////////////////////////////////////////////
	m_livesText.setString(toString(m_playerLives));
	m_scoreText.setString(toString(m_playerScore));
	m_roundText.setString(toString(m_roundCounter));

	m_data->jukebox.CheckMusic();
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
		for (const auto& i : m_pPlayerBulletList)
		{
			if (i == nullptr)
			{
				continue;
			}
			i->Draw();
		}
	}
	//Player layer
	if (m_player != nullptr)
		m_player->Draw();

	//AI bullet layer
	if (!m_pAIBulletList.empty())
	{
		for (const auto& i : m_pAIBulletList)
		{
			if (i == nullptr)
			{
				continue;
			}
			i->Draw();
		}
	}
	//AI layer
	for (const auto& i : m_pTargetList)
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
}


//end game check
////////////////////////////////////////////////////////
void GameState::EndGameCheck()
{
    if (m_pTargetList.empty())
	{
		//////////////////////////////////
		//Clean up for projectiles
		for (auto& i : m_pAIBulletList)
		{
			i->MarkedForDeath();
		}
		for (auto& i : m_pPlayerBulletList)
		{
			i->MarkedForDeath();
		}
		//////////////////////////////////
		m_data->grabage.MarkedObjectCleaner(m_pPlayerBulletList, &m_data->window, ObjectCleaner::Type::kPlayerBullet);
       
        std::cout << "Round Count is: " << m_roundCounter << '\n';
		for (size_t i = 0; i < m_amountOfAI; ++i)
		{
			m_pTargetList.push_back(m_factory->MakeAI(i));
		}
		m_roundCounter++;
		m_amountOfAI += m_roundCounter;
		m_data->Spawner.AISpawnLocationReset();
	}

	if (m_playerLives == -1)
	{
		sf::Sound loss;
		loss.setBuffer(m_data->assets.GetSound("PlayerDeath Sound"));
		loss.play();

		//////////////////////////////////
		//Temp Clean up for projectiles
		for (auto& i : m_pAIBulletList)
		{
			i->MarkedForDeath();
		}
		for (auto& i : m_pPlayerBulletList)
		{
			i->MarkedForDeath();
		}
		//////////////////////////////////


		//boot leg way to sleep the thread and allow the deathsound to play 
		sf::Time time = sf::seconds(1.f);
		sleep(time);

		m_data->machine.AddState(std::make_unique<GameOverState>(m_data), true);
	}
	else if (m_playerLives > -1)
	{
		if(m_player == nullptr)
		m_player = m_factory->MakePlayer();
	}
}


//AI Update calls
////////////////////////////////////////////////////////
void GameState::AIUpdate(float dt)
{
	for (const auto& i : m_pTargetList)
	{
		i->Update(dt);
	}

	for (const auto& i : m_pTargetList)
	{
		sf::Time time = m_rateOfFire.getElapsedTime();
		if (i->OnUse())
		{
			if (time > sf::seconds(gAIRateOfFireInSeconds))
			{
				//std::cout << "AI Shot!\n";
				m_pAIBulletList.push_back(m_factory->MakeProjectile(i->GetPOS(), gAIBulletYAxisAmount));
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
		for (const auto& i : m_pPlayerBulletList)
		{
			i->Update(dt);
		}
	}
	if (!m_pAIBulletList.empty())
	{
		for (const auto& i : m_pAIBulletList)
		{
			i->Update(dt);
		}
	}
}

//Collision Dection TODO: Clean up
////////////////////////////////////////////////////////
void GameState::CollisionDetection()
{
	//loops over sprites if two touch mark for death & sends to cleaner
	for (const auto& i : m_pPlayerBulletList)
	{
		for (const auto& j : m_pTargetList)
		{
			if (i->GetSprite().getGlobalBounds().intersects(j->GetSprite().getGlobalBounds()))
			{
				i->MarkedForDeath();
				j->MarkedForDeath();
				m_playerScore += m_roundCounter;
			}
		}
	}

	m_data->grabage.MarkedObjectCleaner(m_pTargetList, &m_data->window, ObjectCleaner::Type::kEnemy);
	m_data->grabage.MarkedObjectCleaner(m_pPlayerBulletList, &m_data->window, ObjectCleaner::Type::kPlayerBullet);

	//loops over sprites if two touch mark for death / deletion
	for (const auto& i : m_pAIBulletList)
	{
		if (i->GetSprite().getGlobalBounds().intersects(m_player->GetSprite().getGlobalBounds()))
		{
			i->MarkedForDeath();
		}
	}

	for(auto& i : m_pAIBulletList)
	{
	    if(i->GetSprite().getGlobalBounds().intersects(m_player->GetSprite().getGlobalBounds()))
	    {
				if (m_spawnTimer.getElapsedTime().asSeconds() < 1.5f)
				{

					return;
				}
				i->MarkedForDeath();
				m_playerLives -= 1;
				m_spawnTimer.restart();
				m_player->MakeSound();
	    }
	}
}


//Player Update calls
////////////////////////////////////////////////////////
void GameState::PlayerUpdate(float dt)
{
	if (m_roundCounter % 10 != 0)
		m_giveLife = true;

	if(m_giveLife == true)
	if (m_roundCounter % 10 == 0)
	{
		m_giveLife = false;
		m_playerLives += 2;
	}
    if (m_player != nullptr)
		m_player->Update(dt);

	if (m_player != nullptr)
	{
        //static bool s_playerHasShot;

       // if (s_playerHasShot)
		//{
			if (m_player->OnUse())
			{
				//left side gun
				m_pPlayerBulletList.push_back(m_factory->MakeProjectile(m_player->GetPOS(), -gPlayerBulletYAxisAmount));
				m_pPlayerBulletList.at(0)->MakeSound();

				//right side gun
				sf::Vector2f newBulletPos;
				newBulletPos.x = m_player->GetSprite().getGlobalBounds().width + (m_player->GetPOS().x - 20);
				newBulletPos.y = m_player->GetPOS().y;
				m_pPlayerBulletList.push_back(m_factory->MakeProjectile(newBulletPos, -gPlayerBulletYAxisAmount));
				m_pPlayerBulletList.at(0)->MakeSound();
				//s_playerHasShot = false;
			}
		//}
		//{
		//	if (!s_playerHasShot)
		//	{
		//		if (m_player.at(0)->OnUse())
		//		{
		//			
		//			s_playerHasShot = true;
		//		}
		//	}
		//}
	}
}

