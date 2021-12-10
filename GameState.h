#pragma once
#include "GameManager.h"
#include "State.h"


class GameObject;
//class Target;
//class Player;
//class Bullet;

class GameState : public State
{

	//Ref to Game data local
	GameDataRef m_data;


	/////////////////////////////////////////////////
	//clock to keep track of how much time has passed
	// temp for testing moving to end game state
	// sf::Clock m_clock;
	/////////////////////////////////////////////////

	//second timer for AI shots with out this only the one in the top of the list shoots
	sf::Clock m_rateOfFire;

	sf::Clock m_spawnTimer;

	sf::Sprite m_background;
	std::vector<std::shared_ptr<GameObject>> m_playerLives;
	std::vector<std::shared_ptr<GameObject>> m_pTargetList;
	std::vector<std::shared_ptr<GameObject>> m_pPlayerBulletList;
	std::vector<std::shared_ptr<GameObject>> m_pAIBulletList;

public:

	//c'tor takes in reference to Game Data struct
	GameState(GameDataRef data);


	virtual void Init() override final;
	virtual void HandleInput()override final;
	virtual void Update(float dt)override final;
	virtual void Draw(float interpolation)override final;

private:
	void EndGameCheck();
	void PlayerUpdate(float dt);
	void AIUpdate(float dt);
	void ProjectileUpdate(float dt);
	void CollisionDetection();

};

