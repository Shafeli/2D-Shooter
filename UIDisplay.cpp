#include "UIDisplay.h"

#include "Definition.h"

void UIDisplay::InitGameUI(const sf::RenderWindow* window, sf::Font& font, UI display)
{
	//if UI = game do case 3 if UI = end game do case 2
	switch (static_cast<int>(display))
	{
	case 3:
		//setting Text size
		m_scoreText.setCharacterSize(80);
		m_roundText.setCharacterSize(80);
		m_livesText.setCharacterSize(80);
		//setting font
		m_scoreText.setFont(font);
		m_roundText.setFont(font);
		m_livesText.setFont(font);
		//setting pos
		m_scoreText.setPosition(static_cast<float>(window->getSize().x) / static_cast<float>(2) - 10, 0);
		m_roundText.setPosition(static_cast<float>(window->getSize().x) - static_cast<float>(80), 0);
		m_livesText.setPosition(40, 0);
		break;

	case 2:
		//setting Text size
		m_scoreText.setCharacterSize(80);
		m_roundText.setCharacterSize(80);
		m_highScore.setCharacterSize(80);
		//setting font
		m_scoreText.setFont(font);
		m_roundText.setFont(font);
		m_highScore.setFont(font);
		//setting pos
		m_scoreText.setPosition(static_cast<float>(window->getSize().x) / static_cast<float>(2) - 10, 0);
		m_roundText.setPosition(static_cast<float>(window->getSize().x) / static_cast<float>(2) - 10, 0);
		m_highScore.setPosition((sf::Vector2f(gScreenWidth / 1.59f, gScreenHeight / 1.59f)));
		m_highScore.setOrigin(m_highScore.getGlobalBounds().width / 2, m_highScore.getGlobalBounds().height / 2);
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
    //if UI = game do case 3 if UI = end game do case 2
	switch (static_cast<int>(display))
	{
	case 3:
		//call over load to String ints for UI
		m_roundText.setString(toString(m_roundCounter));
		m_scoreText.setString(toString(m_playerScore));
		m_livesText.setString(toString(m_playerLives));
		//draws UI
		window->draw(m_roundText);
		window->draw(m_scoreText);
		window->draw(m_livesText);

	case 2:
		//call over load to String ints for UI
		m_roundText.setString(toString(m_roundCounter));
		m_scoreText.setString(toString(m_playerScore));
		m_highScore.setString("High Score");
		//draws UI
		window->draw(m_roundText);
		window->draw(m_scoreText);
		window->draw(m_highScore);
	}
}

void UIDisplay::SetEndGameUIUp(int fileHighScore)
{
	//receiver for high score
	m_roundCounter = fileHighScore;
}



