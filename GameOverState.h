#pragma once
#include "GameManager.h"
#include "State.h"
class GameOverState : public State
{
	//Ref to Game data local
	GameDataRef m_data;

	/////////////////////////////////////////////////
	//clock to keep track of how much time has passed
	//TODO: after n time switch to main menu state & restart game
	/////////////////////////////////////////////////
	sf::Clock m_clock;

	//sprites
	sf::Sprite m_background;

public:
	//c'tor takes in reference to Game Data struct
	GameOverState(GameDataRef data);

	virtual void Init()override final;
	virtual void HandleInput()override final;
	virtual void Update(float dt)override final;
	virtual void Draw(float interpolation)override final;


};

