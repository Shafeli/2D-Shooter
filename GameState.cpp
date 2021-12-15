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
	m_factory = std::make_unique<ObjectFactory>(data);
}

// loads texture to asset manager
void GameState::Init()
{
	m_data->GameUI.Init(&m_data->window, m_data->assets.GetFont("Game Font"), 80);
	m_background.setTexture(this->m_data->assets.GetTexture("Game State Background"));
	m_roundCounter++;

	for (size_t i = 0; i < m_amountOfAI; ++i)
	{
		m_pTargetList.push_back(m_factory->MakeAI(static_cast<int>(i)));
	}
}


void GameState::HandleInput()
{
	GameEngine::Event event;

	while (this->m_data->window.pollEvent(event))
	{
		if (GameEngine::Event::Closed == event.type)
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
	
	// Projectile clearner calls TODO: move to function
	////////////////////////////////////////////////////////
	m_data->grabage.Cleaner(m_pPlayerBulletList, &m_data->window, ObjectCleaner::Type::kPlayerBullet);
	m_data->grabage.Cleaner(m_pAIBulletList, &m_data->window, ObjectCleaner::Type::kEnemyBullet);
	m_data->grabage.Cleaner(m_pTargetList, &m_data->window, ObjectCleaner::Type::kEnemy);
	////////////////////////////////////////////////////////

	//TODO: UI move to function
	m_data->GameUI.UpdatePlayerLivesText(m_playerLives);
	m_data->GameUI.UpdateScoreText(m_playerScore);
	m_data->GameUI.UpdateRoundText(m_roundCounter);
	m_data->jukebox.CheckMusic();
}

//renders state 
void GameState::Draw()
{
	//Error color
	this->m_data->window.clear(GameEngine::Color::Red);
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

	//TODO: UI move to function
	this->m_data->window.draw(m_data->GameUI.GetScoreText());
	this->m_data->window.draw(m_data->GameUI.GetLiveCountText());
	this->m_data->window.draw(m_data->GameUI.GetRoundText());

	//Display Window
	this->m_data->window.display();
}


//end game check
////////////////////////////////////////////////////////
void GameState::EndGameCheck()
{	//boot leg way to sleep the thread and allow the deathsound to play 
	GameEngine::Time time = sf::seconds(1.5f);
	for(auto& i : m_pTargetList)
	{
	    if(i->GetSprite().getPosition().y == static_cast<float>(m_data->window.getSize().y))
	    {
			GameEngine::Sound loss;
			loss.setBuffer(m_data->assets.GetSound("PlayerDeath Sound"));
			loss.play();

			m_data->machine.AddState(std::make_unique<GameOverState>(m_data), true);
	    }
	}
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
		m_data->grabage.MarkedObjectCleaner(m_pAIBulletList, &m_data->window, ObjectCleaner::Type::kEnemyBullet);
		m_data->grabage.MarkedObjectCleaner(m_pPlayerBulletList, &m_data->window, ObjectCleaner::Type::kPlayerBullet);
		m_data->Spawner.PlayerSpawn(m_player,&m_data->window);
		
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
		m_player->MakeSound();
		sleep(time);
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
				m_pAIBulletList.push_back(m_factory->MakeProjectile(i->GetPOS(), gAIBulletYAxisAmount,ProjetileAppearanceStrategy::ProjectileColor::kEmey));
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
				m_data->Spawner.PlayerSpawn(m_player,&m_data->window);
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
			if (m_player->OnUse())
			{
				//left side gun
				m_pPlayerBulletList.push_back(m_factory->MakeProjectile(m_player->GetPOS(), -gPlayerBulletYAxisAmount,ProjetileAppearanceStrategy::ProjectileColor::kPlayer));
				//right side gun
				GameEngine::Vector2f newBulletPos;
				newBulletPos.x = m_player->GetSprite().getGlobalBounds().width + (m_player->GetPOS().x - 20);
				newBulletPos.y = m_player->GetPOS().y;
				m_pPlayerBulletList.push_back(m_factory->MakeProjectile(newBulletPos, -gPlayerBulletYAxisAmount,ProjetileAppearanceStrategy::ProjectileColor::kPlayer));
				m_pPlayerBulletList.at(0)->MakeSound();
			
			}
	}
}

