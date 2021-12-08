#include "GameState.h"

#include <iostream>

#include "Definition.h"
#include "GameOverState.h"
#include "Bullet.h"
#include "Player.h"
#include "Target.h"

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

	m_data->assets.LoadTexture("Player Sprite", PLAYER_SPRITE);
	m_data->assets.LoadTexture("Target Sprite", TARGET_SPRITE);
	m_data->assets.LoadTexture("Bullet Sprite", BULLET_SPRITE);

	m_player = new Player(m_data);
	//m_target = new Target(m_data);
	
	for (size_t i = 0; i < 10; ++i)
	{
		m_pTargetList.push_back(new Target(m_data, i));
	}
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
	//if (this->m_clock.getElapsedTime().asSeconds() > SPLASH_STATE_SHOW_TIME)
	//{
	//	m_data->machine.AddState(std::make_unique<GameOverState>(m_data), true);
	//}
	m_player->Update(dt);

	if(m_player->FireShot())
	{
		m_bulletList.push_back(new Bullet(m_data, m_player->GetPOS()));
	}

	for (auto i : m_pTargetList)
	{
		i->Update(dt);
	}

	if (!m_bulletList.empty())
	{
		for (auto i : m_bulletList)
		{
			i->Update(dt);
		}
	}
}

//renders state 
void GameState::Draw(float interpolation)
{
	this->m_data->window.clear(sf::Color::Red);

	this->m_data->window.draw(this->m_background);

	m_player->Draw();

	if (!m_bulletList.empty())
	{
		for (auto i : m_bulletList)
		{
			i->Draw();
		}
	}

	for (auto i : m_pTargetList)
	{
		i->Draw();
	}
	this->m_data->window.display();
}