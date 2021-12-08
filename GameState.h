#pragma once
#include "GameManager.h"
#include "State.h"
#include "Player.h"
#include "Target.h"

class GameState : public State
{

	//Ref to Game data local
	GameDataRef m_data;


	/////////////////////////////////////////////////
	//clock to keep track of how much time has passed
	// temp for testing moving to end game state
	// sf::Clock m_clock;
	/////////////////////////////////////////////////


    //sprites
	sf::Sprite m_background;

	Player* m_player;
	//Target* m_target;
	std::vector<Target*> m_pTargetList;

public:

	//c'tor takes in reference to Game Data struct
	GameState(GameDataRef data);


	virtual void Init() override final;
	virtual void HandleInput()override final;
	virtual void Update(float dt)override final;
	virtual void Draw(float interpolation)override final;


};

