
#include "SplashState.h"
#include "Definition.h"
#include "MainMenuState.h"
#include <iostream>


	SplashState::SplashState(GameEngine::GameDataRef data)
        : m_data(data)
	{
	}

	SplashState::~SplashState()
	{
		m_data->assets.Unload(AssetManager::Sound::kSplashScreenLoad);
	}

    // loads texture to asset manager
	void SplashState::Init()
	{
		m_data->assets.Load(AssetManager::Texture::kGameTitle, m_data->FilingCabinet.GetFilePath(FileManager::FileData::kGameTitleTexture));
		m_data->assets.Load(AssetManager::Sound::kSplashScreenLoad, gSplashSoundFile);
	    m_data->assets.Load(AssetManager::Texture::kBackground, gGameBackgroundFile);

		m_title.setTexture(this->m_data->assets.GetTexture(AssetManager::Texture::kGameTitle));
		m_title.setPosition((gScreenWidth / 2) - (m_title.getGlobalBounds().width / 2), m_title.getGlobalBounds().height / 2);
		m_sound.setBuffer(m_data->assets.GetSound(AssetManager::Sound::kSplashScreenLoad));
		m_background.setTexture(this->m_data->assets.GetTexture(AssetManager::Texture::kBackground));
	}

	
	void SplashState::HandleInput()
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

    //checks show time and after "show time go to main menu"
	void SplashState::Update(float dt)
	{
		if (soundSwitch)
		{
			m_sound.setVolume(m_data->jukebox.GetMasterVolume());
			m_sound.play();
			soundSwitch = false;
		}

		if (this->m_clock.getElapsedTime().asSeconds() > gSplashShowTime)
		{
			m_data->machine.AddState(std::make_unique<MainMenuState>(m_data), true);
		}
	}

    //renders state 
	void SplashState::Draw()
	{
		//If you see this consider it a error
		this->m_data->window.clear(sf::Color::Red);
		this->m_data->window.draw(this->m_background);
		this->m_data->window.draw(this->m_title);
		this->m_data->window.display();
	}

