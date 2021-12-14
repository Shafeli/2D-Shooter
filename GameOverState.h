#pragma once
#include "GameManager.h"
#include "State.h"
class GameOverState : public State
{
	//Ref to Game data local
    GameEngine::GameDataRef m_data;

	/////////////////////////////////////////////////
	//clock to keep track of how much time has passed
	//TODO: after n time switch to main menu state & restart game
	/////////////////////////////////////////////////
	sf::Clock m_clock;

	sf::Sprite m_background;
	sf::Clock m_screenClock;
	sf::Music m_gameOverMusic;
	sf::Sound m_MenuSound;
	//sprites
	sf::Sprite m_button;

public:
	//c'tor takes in reference to Game Data struct
	GameOverState(GameEngine::GameDataRef data);

	virtual void Init()override final;
	virtual void HandleInput()override final;
	virtual void Update(float dt)override final;
	virtual void Draw()override final;
	void EndGameMusic();


};

