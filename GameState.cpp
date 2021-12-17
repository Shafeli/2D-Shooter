#include "GameState.h"
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

GameState::~GameState()
{
	m_data->assets.Unload(AssetManager::Texture::kPlayer);
	m_data->assets.Unload(AssetManager::Texture::kEnemy);
	m_data->assets.Unload(AssetManager::Texture::kLazer);
	m_data->assets.Unload(AssetManager::Sound::kLazer);
	m_data->assets.Unload(AssetManager::Sound::kEnemyDeath);
	m_data->assets.Unload(AssetManager::Sound::kPlayerDeath);
	m_data->assets.Unload(AssetManager::Texture::kDeath);
	delete m_player;
	m_player = nullptr;
	
}

// loads texture to asset manager
void GameState::Init()
{
	m_data->assets.Load(AssetManager::Texture::kPlayer, m_data->FilingCabinet.GetFilePath(FileManager::FileData::kPlayerTexture));
	m_data->assets.Load(AssetManager::Texture::kEnemy, m_data->FilingCabinet.GetFilePath(FileManager::FileData::kEnemyTexture));
	m_data->assets.Load(AssetManager::Texture::kLazer, m_data->FilingCabinet.GetFilePath(FileManager::FileData::kLazerTexture));
	m_data->assets.Load(AssetManager::Sound::kLazer, m_data->FilingCabinet.GetFilePath(FileManager::FileData::kLazerSound));
	m_data->assets.Load(AssetManager::Sound::kEnemyDeath, m_data->FilingCabinet.GetFilePath(FileManager::FileData::kEnemyDeathSound));
	m_data->assets.Load(AssetManager::Sound::kPlayerDeath, m_data->FilingCabinet.GetFilePath(FileManager::FileData::kPlayerDeathSound));
	m_data->assets.Load(AssetManager::Texture::kDeath, m_data->FilingCabinet.GetFilePath(FileManager::FileData::kDeathTexture));

	m_data->assets.Load(AssetManager::Font::kGame, m_data->FilingCabinet.GetFilePath(FileManager::FileData::kGameFont));

	m_data->GameUI.Init(&m_data->window, m_data->assets.GetFont(AssetManager::Font::kGame), 80);
	m_background.setTexture(this->m_data->assets.GetTexture(AssetManager::Texture::kBackground));
	m_data->GameUI.UpdateRound();

	for (size_t i = 0; i < m_amountOfAI; ++i)
	{
		m_pTargetList.push_back(m_factory->MakeAI(static_cast<int>(i)));
	}
}

// window closing
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
	//End Game Check
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
	
	// Projectile clearner calls
	////////////////////////////////////////////////////////
	ProjectileCleanUp();
	////////////////////////////////////////////////////////
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


	DrawUI();

	//Display Window
	this->m_data->window.display();
}

//End game check
////////////////////////////////////////////////////////
void GameState::EndGameCheck()
{	//boot leg way to sleep the thread and allow the deathsound to play 
	GameEngine::Time time = sf::seconds(1.5f);
	GameEngine::Sound loss;
	loss.setBuffer(m_data->assets.GetSound(AssetManager::Sound::kPlayerDeath));
	loss.setVolume(m_data->jukebox.GetMasterVolume());
	for (const auto& i : m_pTargetList)
	{
		if (m_data->collisionDection.DoesObjectTouchWindowBottom(i, &m_data->window))
	    {
			loss.play();
			sleep(time);
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
		MarkedTargetCleanUp();
		m_data->Spawner.PlayerSpawn(m_player,&m_data->window);
		
		for (size_t i = 0; i < m_amountOfAI; ++i)
		{
			m_pTargetList.push_back(m_factory->MakeAI(i));
		}
		m_data->GameUI.UpdateRound();
		m_amountOfAI += m_data->GameUI.GetRoundCounter();
		m_data->Spawner.AISpawnLocationReset();
	}

	if (m_data->GameUI.GetLifeCounter() == -1)
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
	else if (m_data->GameUI.GetLifeCounter() > -1)
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
			if (time > sf::seconds(m_data->FilingCabinet.GetConfigFloat(FileManager::FileData::kAIRateOfFire)))
			{
				m_pAIBulletList.push_back(m_factory->MakeProjectile(i->GetPOS(),m_data->FilingCabinet.GetConfigFloat(FileManager::FileData::kAIProjectileSpeed), ProjetileAppearanceStrategy::ProjectileColor::kEmey));
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

//Collision Dection
////////////////////////////////////////////////////////
void GameState::CollisionDetection()
{

	if (m_data->collisionDection.DoesObjectOverlap(m_pPlayerBulletList, m_pTargetList))
		m_data->GameUI.UpdateScore();

	MarkedTargetCleanUp();

	if(m_data->collisionDection.IsPlayerHitDetection(m_pAIBulletList,m_player,m_spawnTimer))
	{
		m_data->Spawner.PlayerSpawn(m_player, &m_data->window);
		m_data->GameUI.UpdatePlayerLives(UIDisplay::UI::kTakeLife);
	}

}

// Projectile clearner calls
////////////////////////////////////////////////////////
void GameState::MarkedTargetCleanUp()
{
	m_data->grabage.MarkedObjectCleaner(m_pTargetList, &m_data->window, ObjectCleaner::Type::kEnemy);
	m_data->grabage.MarkedObjectCleaner(m_pAIBulletList, &m_data->window, ObjectCleaner::Type::kEnemyBullet);
	m_data->grabage.MarkedObjectCleaner(m_pPlayerBulletList, &m_data->window, ObjectCleaner::Type::kPlayerBullet);
	
}

void GameState::ProjectileCleanUp()
{
	
	m_data->grabage.Cleaner(m_pPlayerBulletList, &m_data->window, ObjectCleaner::Type::kPlayerBullet);
	m_data->grabage.Cleaner(m_pAIBulletList, &m_data->window, ObjectCleaner::Type::kEnemyBullet);
}

// Draw UI calls
////////////////////////////////////////////////////////
void GameState::DrawUI()
{
	m_data->GameUI.Draw(&m_data->window);
}

//Player Update calls
////////////////////////////////////////////////////////
void GameState::PlayerUpdate(float dt)
{
	if (m_data->GameUI.GetRoundCounter() % 10 != 0)
		m_giveLife = true;

	if(m_giveLife == true)
	if (m_data->GameUI.GetRoundCounter() % 10 == 0)
	{
		m_giveLife = false;
	    m_data->GameUI.UpdatePlayerLives(UIDisplay::UI::kGiveExtraLife);
	}
    if (m_player != nullptr)
		m_player->Update(dt);

	if (m_player != nullptr)
	{
			if (m_player->OnUse())
			{
				//left side gun
				m_pPlayerBulletList.push_back(m_factory->MakeProjectile(m_player->GetPOS(), -m_data->FilingCabinet.GetConfigFloat(FileManager::FileData::kPlayerProjectileSpeed),ProjetileAppearanceStrategy::ProjectileColor::kPlayer));
				//right side gun
				GameEngine::Vector2f newBulletPos;
				newBulletPos.x = m_player->GetSprite().getGlobalBounds().width + (m_player->GetPOS().x - 20);
				newBulletPos.y = m_player->GetPOS().y;
				m_pPlayerBulletList.push_back(m_factory->MakeProjectile(newBulletPos, -m_data->FilingCabinet.GetConfigFloat(FileManager::FileData::kPlayerProjectileSpeed), ProjetileAppearanceStrategy::ProjectileColor::kPlayer));
				m_pPlayerBulletList.at(0)->MakeSound();
			
			}
	}
}

