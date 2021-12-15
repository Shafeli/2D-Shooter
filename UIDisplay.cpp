#include "UIDisplay.h"

void UIDisplay::Init(const sf::RenderWindow* window, sf::Font& font, int size)
{
	m_scoreText.setCharacterSize(size);
	m_roundText.setCharacterSize(size);
	m_livesText.setCharacterSize(size);
	m_scoreText.setFont(font);
	m_roundText.setFont(font);
	m_livesText.setFont(font);
	m_scoreText.setPosition(static_cast<float>(window->getSize().x) / static_cast<float>(2) - 10, 0);
	m_roundText.setPosition(static_cast<float>(window->getSize().x) - static_cast<float>(80), 0);
	m_livesText.setPosition(40, 0);
}

void UIDisplay::UpdateRound()
{	
	m_roundCounter++;
}

void UIDisplay::UpdatePlayerLives(UI update)
{
	switch (static_cast<int>(update))
	{
	case 0:m_playerLives -= 1; return;

	case 1:m_playerLives += 2; break;
	}
}

void UIDisplay::UpdateScore()
{
	m_playerScore += m_roundCounter;
}

void UIDisplay::Draw(sf::RenderWindow* window)
{
	m_roundText.setString(toString(m_roundCounter));
	m_scoreText.setString(toString(m_playerScore));
    m_livesText.setString(toString(m_playerLives));

	window->draw(m_roundText);
	window->draw(m_scoreText);
	window->draw(m_livesText);
}
