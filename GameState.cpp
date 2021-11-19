#include "GameState.h"

#include <iostream>

#include "Definition.h"
#include "GameOverState.h"


GameState::GameState(GameDataRef data)
	: m_data(data)
{

}

// loads texture to asset manager
void GameState::Init()
{
	std::cout << "Entered Game State\n";
	this->m_data->assets.LoadTexture("Game State Background", Game_BACKGROUND_FILEPATH);

	m_background.setTexture(this->m_data->assets.GetTexture("Game State Background"));
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
	if (this->m_clock.getElapsedTime().asSeconds() > SPLASH_STATE_SHOW_TIME)
	{
		m_data->machine.AddState(StateRef(new GameOverState(m_data)), true);
	}
}

//renders state 
void GameState::Draw(float dt)
{
	this->m_data->window.clear(sf::Color::Red);

	this->m_data->window.draw(this->m_background);

	this->m_data->window.display();
}