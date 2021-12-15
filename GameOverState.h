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
	GameEngine::Clock m_clock;

	GameEngine::Sprite m_background;
	GameEngine::Clock m_screenClock;
	GameEngine::Sound m_MenuSound;
	//sprites
	GameEngine::Sprite m_button;

public:
	//c'tor takes in reference to Game Data struct
	GameOverState(GameEngine::GameDataRef data);

	virtual void Init()override final;
	virtual void HandleInput()override final;
	virtual void Update(float dt)override final;
	virtual void Draw()override final;
	void EndGameMusic();


};

