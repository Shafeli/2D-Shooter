#include "GameState.h"
#include "memory"
#include "GameOverState.h"
#include "GameObject.h"


GameState::GameState(GameEngine::GameDataRef data)
	: m_data(data)
    ,m_player(nullptr)
{
	m_factory = std::make_unique<ObjectFactory>(data);
}

//unloads data from the maps that are no longger in use
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

// loads texture to asset manager & sets textures plus builds first AI list & init UI
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
	m_data->GameUI.InitGameUI(&m_data->window, m_data->assets.GetFont(AssetManager::Font::kGame), UIDisplay::UI::kPlayGameUI);

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
	//checks list of AI to see if any touch the widnow bottom
	for (const auto& i : m_pTargetList)
	{
		if (m_data->collisionDection.DoesObjectTouchWindowBottom(i, &m_data->window))
	    {
			loss.play();
			sleep(time);
			m_data->machine.AddState(std::make_unique<GameOverState>(m_data), true);
	    }
	}
	//if AI list is empty
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
		MarkedTargetCleanUp();
		//////////////////////////////////

		//reset player to Spawn
		m_data->Spawner.PlayerSpawn(m_player,&m_data->window);

		//make more AI
		for (size_t i = 0; i < m_amountOfAI; ++i)
		{
			m_pTargetList.push_back(m_factory->MakeAI(i));
		}
		//Updata UI
		m_data->GameUI.UpdateRound();
		//changes about of AI to Spawn next round 
        m_amountOfAI += m_data->GameUI.GetRoundCounter();

		//sets new AI to Spawn locations
		m_data->Spawner.AISpawnLocationReset();
	}
	//if player live is less then 0 end game
	if (m_data->GameUI.GetLifeCounter() == -1)
	{
		//do player noise 
		m_player->MakeSound();
		//sleep thred for noise to play
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
		MarkedTargetCleanUp();
		//////////////////////////////////

		//push score to file system 
		m_data->FilingCabinet.SaveHighScore(m_data->GameUI.GetScore());
		//move to game over state
		m_data->machine.AddState(std::make_unique<GameOverState>(m_data), true);
	}
	//if player has lifes always make sure it is created
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
	//runs every AI's Update 
	for (const auto& i : m_pTargetList)
	{
		i->Update(dt);
	}
	//checks for AI's fire flag and if time is > then thier Rate of Fire make new projectile 
	for (const auto& i : m_pTargetList)
	{
		GameEngine::Time time = m_rateOfFire.getElapsedTime();
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
	//runs ever projectiles update
	if (!m_pPlayerBulletList.empty())
	{
		for (const auto& i : m_pPlayerBulletList)
		{
			i->Update(dt);
		}
	}
	//runs ever projectiles update
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
	//checks sends to collisionDection & if true update UI
	if (m_data->collisionDection.DoesObjectOverlap(m_pPlayerBulletList, m_pTargetList))
		m_data->GameUI.UpdateScore();

	MarkedTargetCleanUp();
	//check sends to collisionDection & if true move player to spawn take a life from UI
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
	//Marked target clean up calls 
	m_data->grabage.MarkedObjectCleaner(m_pTargetList, &m_data->window, ObjectCleaner::Type::kEnemy);
	m_data->grabage.MarkedObjectCleaner(m_pAIBulletList, &m_data->window, ObjectCleaner::Type::kEnemyBullet);
	m_data->grabage.MarkedObjectCleaner(m_pPlayerBulletList, &m_data->window, ObjectCleaner::Type::kPlayerBullet);
	
}

void GameState::ProjectileCleanUp()
{
	//projectile cleaner calls
	m_data->grabage.Cleaner(m_pPlayerBulletList, &m_data->window, ObjectCleaner::Type::kPlayerBullet);
	m_data->grabage.Cleaner(m_pAIBulletList, &m_data->window, ObjectCleaner::Type::kEnemyBullet);
}

// Draw UI calls
////////////////////////////////////////////////////////
void GameState::DrawUI()
{
	//draws UI for game
	m_data->GameUI.Draw(&m_data->window, UIDisplay::UI::kPlayGameUI);
}

//Player Update calls
////////////////////////////////////////////////////////
void GameState::PlayerUpdate(float dt)
{
	//if round ! mods 10 giveLife = true 
	if (m_data->GameUI.GetRoundCounter() % 10 != 0)
		m_giveLife = true;
	//if giveLive = true and round mods 10 update UI
	if(m_giveLife == true)
	if (m_data->GameUI.GetRoundCounter() % 10 == 0)
	{
		m_giveLife = false;
	    m_data->GameUI.UpdatePlayerLives(UIDisplay::UI::kGiveExtraLife);
	}
	//if player is not null run update
    if (m_player != nullptr)
		m_player->Update(dt);
	//if player is not null & player on use flag is true make projectiles
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

