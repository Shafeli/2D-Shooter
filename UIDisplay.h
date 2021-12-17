#pragma once
#include <SFML/Graphics/Text.hpp>
#include <SFML/Graphics/RenderWindow.hpp>
#include <sstream>

class UIDisplay
{
	bool m_inGameUI = false;
	bool m_endGameUI = false;

	sf::Text m_scoreText;
	sf::Text m_livesText;
	sf::Text m_roundText;

	sf::Int32 m_playerScore = 0;
	sf::Int32 m_playerLives = 5;
	sf::Int32 m_roundCounter = 0;

public:
	//just in case i can get to power ups, this could help
	enum class UI{ kTakeLife, kGiveExtraLife, kEndGameUI, kPlayGameUI};

	sf::Int32 GetScore() { return m_playerScore; }

	void InitGameUI(const sf::RenderWindow* window, sf::Font& font, UI display);

	void UpdateRound();
	void UpdatePlayerLives(UI update);
	void UpdateScore();
	void Draw(sf::RenderWindow* window, UI display);
	void SetEndGameUIUp(int fileHighScore);
	int GetRoundCounter() { return static_cast<int>(m_roundCounter); }
	int GetLifeCounter() { return static_cast<int>(m_playerLives); }


	static sf::String toString(sf::Int64 integer)
	{
		std::ostringstream os;
		os << integer;
		return os.str();
	}
};

