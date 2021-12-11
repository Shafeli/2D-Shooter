#include "GameOverState.h"
#include <iostream>
#include "Definition.h"
#include "MainMenuState.h"


GameOverState::GameOverState(GameDataRef data)
	: m_data(data)
{
	EndGameMusic();
}

// loads texture to asset manager
void GameOverState::Init()
{
	std::cout << "Entered Game Over State\n";
	this->m_data->assets.LoadTexture("Game Over State Background", gGameOverFile);
	m_MenuSound.setBuffer(m_data->assets.GetSound("Click Sound"));
	m_background.setTexture(this->m_data->assets.GetTexture("Game Over State Background"));
	m_button.setTexture(this->m_data->assets.GetTexture("Play Button"));
	m_button.setScale(sf::Vector2f(0.2f, 0.2f));
	m_button.setPosition((gScreenWidth / 2) - (m_button.getGlobalBounds().width / 2), (gScreenHeight / 2) - (m_button.getGlobalBounds().height / 2));


}


void GameOverState::HandleInput()
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


void GameOverState::Update(float dt)
{
	
	if (this->m_clock.getElapsedTime().asSeconds() > 234)
	{
		std::cout << "Exiting Splash State\n";
		m_data->machine.AddState(std::make_unique<MainMenuState>(m_data), true);
	}


	if (m_data->input.IsSpriteClicked(m_button, sf::Mouse::Left, m_data->window))
	{
		std::cout << "Button CLicked :: Moving TO Game State\n";

		//plays click sound 
		m_MenuSound.play();

		//wait time for sound to go off boot leg but it works 
		sf::Time time = sf::seconds(0.1f);
		sleep(time);

		//after sleep move state
		m_data->machine.AddState(std::make_unique<MainMenuState>(m_data), true);
	}
}

//renders state 
void GameOverState::Draw()
{
	this->m_data->window.clear(sf::Color::Red);

	this->m_data->window.draw(this->m_background);
	this->m_data->window.draw(this->m_button);

	this->m_data->window.display();
}

void GameOverState::EndGameMusic()
{


	m_gameOverMusic.openFromFile("Resources/res/EndGameMusic.wav");
	m_gameOverMusic.play();
}