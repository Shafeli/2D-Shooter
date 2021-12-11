
#include "SplashState.h"
#include "Definition.h"
#include "MainMenuState.h"
#include <iostream>


	SplashState::SplashState(GameDataRef data)
        : m_data(data)
	{
	}

    // loads texture to asset manager
	void SplashState::Init()
	{
		this->m_data->assets.LoadTexture("Game TItle", gGameTitleFile);
		this->m_data->assets.LoadSound("Splash Sound", gSplashSoundFile);
		this->m_data->assets.LoadTexture("Game Over State Background", gGameOverFile);
		this->m_data->assets.LoadFont("Game Font", gGameFontFile);
		this->m_data->assets.LoadTexture("Main menu Background", gMainMenuBackgroundFile);
		this->m_data->assets.LoadTexture("Play Button", gPlayButtonFile);
		m_data->assets.LoadSound("Click Sound", gClickSoundFile);
		m_title.setTexture(this->m_data->assets.GetTexture("Game TItle"));
		m_title.setPosition((gScreenWidth / 2) - (m_title.getGlobalBounds().width / 2), m_title.getGlobalBounds().height / 2);
		m_sound.setBuffer(m_data->assets.GetSound("Splash Sound"));
		std::cout << "Entered Splash State\n";
		this->m_data->assets.LoadTexture("Splash State Background", gSplahBackgroundFile);
		m_background.setTexture(this->m_data->assets.GetTexture("Splash State Background"));
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
			m_sound.setVolume(50);
			m_sound.play();
			soundSwitch = false;
		}

		if (this->m_clock.getElapsedTime().asSeconds() > gSplashShowTime)
		{
			std::cout << "Exiting Splash State\n";

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
