
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
		if (this->m_clock.getElapsedTime().asSeconds() > gSplashShowTime)
		{
			std::cout << "Exiting Splash State\n";

			m_data->machine.AddState(std::make_unique<MainMenuState>(m_data), true);
		}
	}

    //renders state 
	void SplashState::Draw(float interpolation)
	{
		//If you see this consider it a error
		this->m_data->window.clear(sf::Color::Red);

		this->m_data->window.draw(this->m_background);

		this->m_data->window.display();
	}
