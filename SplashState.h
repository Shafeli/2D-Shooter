#pragma once
#include <SFML/Graphics.hpp>

#include "GameManager.h"
#include "State.h"


class SplashState : public State
{
	//Ref to Game data local
	GameDataRef m_data;

	/////////////////////////////////////////////////
	//clock to keep track of how much time has passed
	//after n time move to main menu state
	/////////////////////////////////////////////////
	sf::Clock m_clock;

	//background sprite
	sf::Sprite m_background;

public:

	//c'tor takes in reference to Game Data struct
	SplashState(GameDataRef data);

	virtual void Init()override final;
	virtual void HandleInput()override final;
	virtual void Update(float dt)override final;
	virtual void Draw(float interpolation)override final;



};

