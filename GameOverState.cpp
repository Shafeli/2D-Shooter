#include "GameOverState.h"

#include <iostream>

#include "Definition.h"

GameOverState::GameOverState(GameDataRef data)
	: m_data(data)
{

}

// loads texture to asset manager
void GameOverState::Init()
{
	std::cout << "Entered Game Over State\n";
	this->m_data->assets.LoadTexture("Game Over State Background", Game_OVER_FILEPATH);

	m_background.setTexture(this->m_data->assets.GetTexture("Game Over State Background"));
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

}

//renders state 
void GameOverState::Draw(float dt)
{
	this->m_data->window.clear(sf::Color::Red);

	this->m_data->window.draw(this->m_background);

	this->m_data->window.display();
}

