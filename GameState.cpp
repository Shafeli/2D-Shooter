#include "GameState.h"

#include <iostream>
#include "memory"
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
	this->m_data->assets.LoadTexture("Game State Background", gGameBackgroundFile);

	m_background.setTexture(this->m_data->assets.GetTexture("Game State Background"));

	m_data->assets.LoadTexture("Player Sprite", gPlayerSpriteFile);
	m_data->assets.LoadTexture("Target Sprite", gTargetSpriteFile);
	m_data->assets.LoadTexture("Bullet Sprite", gBulletSpriteFile);

	m_player = std::make_unique<Player>(m_data);

	
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
	if (m_pTargetList.empty())
	{
		m_data->machine.AddState(std::make_unique<GameOverState>(m_data), true);
	}

	m_player->Update(dt);
	if(m_player->FireShot())
	{
		m_pPlayerBulletList.push_back(new Bullet(m_data, m_player->GetPOS(), -gPlayerBulletYAxisAmount));
	}

	for (auto i : m_pTargetList)
	{
		i->Update(dt);
	}

	for (auto i : m_pTargetList)
	{
		sf::Time time = m_rateOfFire.getElapsedTime();
		if (i->FireShot())
		{
			if (time > sf::seconds(.5))
			{
				std::cout << "Bang!\n";
				m_pAIBulletList.push_back(new Bullet(m_data, i->GetPOS(), gAIBulletYAxisAmount));
				m_rateOfFire.restart();
			}
			
		}
	}

	if (!m_pPlayerBulletList.empty())
	{
		for (auto i : m_pPlayerBulletList)
		{
			i->Update(dt);
		}
	}
	if (!m_pAIBulletList.empty())
	{
		for (auto i : m_pAIBulletList)
		{
			i->Update(dt);
		}
	}

	////////////////////////////////////////////////////////
	//TODO: Clean up
	for (auto target : m_pTargetList)
	{
		for (auto bullet : m_pPlayerBulletList)
		{
			const auto TargetNewEnd = std::remove_if
		    (
				m_pTargetList.begin(), m_pTargetList.end(),
				[bullet](Target* tar)
				{
					if (tar->GetSprite().getGlobalBounds().intersects(bullet->GetSprite().getGlobalBounds()))
					{
						std::cout << "Hit!\n";
						return true;
					}
				    return false;
				}
			);
			const auto bulletNewEnd = std::remove_if
			(
				m_pPlayerBulletList.begin(), m_pPlayerBulletList.end(),
				[target](Bullet* tar)
				{
					if (tar->GetSprite().getGlobalBounds().intersects(target->GetSprite().getGlobalBounds()))
					{
						
						return true;
					}
					return false;
				}
			);
			m_pTargetList.erase(TargetNewEnd, m_pTargetList.end());
			m_pPlayerBulletList.erase(bulletNewEnd, m_pPlayerBulletList.end());
		}
	}
	////////////////////////////////////////////////////////
}

//renders state 
void GameState::Draw(float interpolation)
{
	this->m_data->window.clear(sf::Color::Red);

	this->m_data->window.draw(this->m_background);

	m_player->Draw();

	if (!m_pAIBulletList.empty())
	{
		for (auto i : m_pAIBulletList)
		{
			if (i == nullptr)
			{
				continue;
			}
			i->Draw();
		}
	}

	if (!m_pPlayerBulletList.empty())
	{
		for (auto i : m_pPlayerBulletList)
		{
			if (i == nullptr)
			{
				continue;
			}
			i->Draw();
		}
	}
	for (auto i : m_pTargetList)
	{
		if (i == nullptr)
			continue;

		i->Draw();
	}
	this->m_data->window.display();
}