#include "UIDisplay.h"

UIDisplay::UIDisplay()
{

}

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

void UIDisplay::UpdateRoundText(sf::Int32 roundCounter)
{	
	m_roundText.setString(toString(roundCounter));
}

void UIDisplay::UpdatePlayerLivesText(sf::Int32 playerLives)
{
	m_livesText.setString(toString(playerLives));
}

void UIDisplay::UpdateScoreText(sf::Int32 playerScore)
{
	m_scoreText.setString(toString(playerScore));
}
