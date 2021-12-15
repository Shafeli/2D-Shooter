#pragma once
#include <SFML/Graphics/Text.hpp>
#include <SFML/Graphics/RenderWindow.hpp>
#include <sstream>
class UIDisplay
{	
	sf::Text m_scoreText;
	sf::Text m_livesText;
	sf::Text m_roundText;

public:
	UIDisplay();

	void Init(const sf::RenderWindow* window, sf::Font& font, int size);
	void UpdateRoundText(sf::Int32 roundCounter);
	void UpdatePlayerLivesText(sf::Int32 playerLives);
	void UpdateScoreText(sf::Int32 playerScore);

	sf::Text& GetScoreText() { return m_scoreText; }
	sf::Text& GetLiveCountText() { return m_livesText; }
	sf::Text& GetRoundText() { return m_roundText; }



	static sf::String toString(sf::Int64 integer)
	{
		std::ostringstream os;
		os << integer;
		return os.str();
	}
};

