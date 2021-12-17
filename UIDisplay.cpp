#include "UIDisplay.h"

#include "Definition.h"

void UIDisplay::InitGameUI(const sf::RenderWindow* window, sf::Font& font, UI display)
{
	switch (static_cast<int>(display))
	{
	case 3:
		m_scoreText.setCharacterSize(80);
		m_roundText.setCharacterSize(80);
		m_livesText.setCharacterSize(80);
		m_scoreText.setFont(font);
		m_roundText.setFont(font);
		m_livesText.setFont(font);
		m_scoreText.setPosition(static_cast<float>(window->getSize().x) / static_cast<float>(2) - 10, 0);
		m_roundText.setPosition(static_cast<float>(window->getSize().x) - static_cast<float>(80), 0);
		m_livesText.setPosition(40, 0);
		break;

	case 2:
		m_scoreText.setCharacterSize(80);
		m_roundText.setCharacterSize(80);
		m_scoreText.setFont(font);
		m_roundText.setFont(font);
		m_scoreText.setPosition(static_cast<float>(window->getSize().x) / static_cast<float>(2) - 10, 0);
		m_roundText.setPosition(static_cast<float>(window->getSize().x) / static_cast<float>(2) - 10, 0);
		m_roundText.setOrigin(m_roundText.getGlobalBounds().width / 2, m_roundText.getGlobalBounds().height / 2);
		m_roundText.setPosition(sf::Vector2f(gScreenWidth / 2.0f, gScreenHeight / 1.5f));
		
	}
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

void UIDisplay::Draw(sf::RenderWindow* window, UI display)
{
	switch (static_cast<int>(display))
	{
	case 3:
		m_roundText.setString(toString(m_roundCounter));
		m_scoreText.setString(toString(m_playerScore));
		m_livesText.setString(toString(m_playerLives));
		window->draw(m_roundText);
		window->draw(m_scoreText);
		window->draw(m_livesText);

	case 2:
		m_roundText.setString(toString(m_roundCounter));
		m_scoreText.setString(toString(m_playerScore));
		m_livesText.setString(toString(m_playerLives));
		window->draw(m_roundText);
		window->draw(m_scoreText);
	}
}

void UIDisplay::SetEndGameUIUp(int fileHighScore)
{
	m_roundCounter = fileHighScore;
}
