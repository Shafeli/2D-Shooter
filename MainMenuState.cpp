#include "MainMenuState.h"

#include <iostream>

#include "Definition.h"
#include "GameState.h"


MainMenuState::MainMenuState(GameDataRef data)
	: m_data(data)
{

}

// loads texture to asset manager
void MainMenuState::Init()
{
	this->m_data->assets.LoadTexture("Main menu Background", MAIN_MENU_BACKGROUND_FILEPATH);
	this->m_data->assets.LoadTexture("Game TItle", GAME_TITLE_FILEPATH);
	this->m_data->assets.LoadTexture("Play Button", PLAY_BUTTON_FILEPATH);

	m_background.setTexture(this->m_data->assets.GetTexture("Main menu Background"));
	m_title.setTexture(this->m_data->assets.GetTexture("Game TItle"));
	m_playButton.setTexture(this->m_data->assets.GetTexture("Play Button"));

	m_title.setPosition((SCREEN_WIDTH / 2) -(m_title.getGlobalBounds().width / 2), m_title.getGlobalBounds().height / 2 );
	m_playButton.setPosition((SCREEN_WIDTH / 2) - (m_playButton.getGlobalBounds().width / 2), (SCREEN_HEIGHT / 2) - (m_playButton.getGlobalBounds().height / 2));
}

//TODO clicking sprite
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
			m_data->machine.AddState(StateRef(new GameState(m_data)), true);
		}
	}
}

//blank feels bad man
void MainMenuState::Update(float dt)
{

}

//renders state 
void MainMenuState::Draw(float dt)
{
	this->m_data->window.clear();

	this->m_data->window.draw(this->m_background);

	this->m_data->window.draw(this->m_title);

	this->m_data->window.draw(this->m_playButton);


	this->m_data->window.display();
}