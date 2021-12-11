#include "MainMenuState.h"

#include <iostream>

#include "Definition.h"
#include "GameState.h"


MainMenuState::MainMenuState(GameDataRef data)
	: m_data(data)
{
	InMenuMusic();
}

// loads texture to asset manager
void MainMenuState::Init()
{

	m_MenuSound.setBuffer(m_data->assets.GetSound("Click Sound"));
	m_background.setTexture(this->m_data->assets.GetTexture("Main menu Background"));
	m_title.setTexture(this->m_data->assets.GetTexture("Game TItle"));

	m_playButton.setTexture(this->m_data->assets.GetTexture("Play Button"));
	m_playButton.setScale(sf::Vector2f(0.2f, 0.2f));

	m_title.setPosition((gScreenWidth / 2) -(m_title.getGlobalBounds().width / 2), m_title.getGlobalBounds().height / 2 );
	m_playButton.setPosition((gScreenWidth / 2) - (m_playButton.getGlobalBounds().width / 2), (gScreenHeight / 2) - (m_playButton.getGlobalBounds().height / 2));
}

void MainMenuState::HandleInput()
{
	sf::Event event;

	while (this->m_data->window.pollEvent(event))
	{
		if (sf::Event::Closed == event.type)
		{
			this->m_data->window.close();
		}
		if (m_data->input.IsSpriteClicked(m_playButton, sf::Mouse::Left, m_data->window))
        {
			std::cout << "Button CLicked :: Moving TO Game State\n";

			//plays click sound 
			m_MenuSound.play();

			//wait time for sound to go off boot leg but it works 
			sf::Time time = sf::seconds(0.1f);
			sleep(time);

			//after sleep move state
			m_data->machine.AddState(std::make_unique<GameState>(m_data), true);
		}
	}
}


void MainMenuState::Update(float dt)
{

}

//renders state 
void MainMenuState::Draw()
{
	this->m_data->window.clear();

	this->m_data->window.draw(this->m_background);

	this->m_data->window.draw(this->m_title);

	this->m_data->window.draw(this->m_playButton);

	this->m_data->window.display();
}

void MainMenuState::InMenuMusic()
{
	m_menuMusic.openFromFile("Resources/res/MainMenuMusic.wav");
	m_menuMusic.play();
}
