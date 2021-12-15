#pragma once
#include <SFML/Graphics/Text.hpp>
#include <SFML/Graphics/RenderWindow.hpp>
#include <sstream>

class UIDisplay
{	
	sf::Text m_scoreText;
	sf::Text m_livesText;
	sf::Text m_roundText;

	sf::Int32 m_playerScore = 0;
	sf::Int32 m_playerLives = 5;
	sf::Int32 m_roundCounter = 0;

public:
	//just in case i can get to power ups, this could help
	enum class UI{ kTakeLife, kGiveExtraLife};

	sf::Int32 GetScore() { return m_playerScore; }

	void Init(const sf::RenderWindow* window, sf::Font& font, int size);
	void UpdateRound();
	void UpdatePlayerLives(UI update);
	void UpdateScore();
	void Draw(sf::RenderWindow* window);

	int GetRoundCounter() { return static_cast<int>(m_roundCounter); }
	int GetLifeCounter() { return static_cast<int>(m_playerLives); }


	static sf::String toString(sf::Int64 integer)
	{
		std::ostringstream os;
		os << integer;
		return os.str();
	}
};

