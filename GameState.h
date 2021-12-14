#pragma once
#include <sstream>

#include "GameManager.h"
#include "ObjectFactory.h"

#include "State.h"


class GameObject;


class GameState : public State
{

	//Ref to Game data local
	////////////////////////////////////////////////
    GameEngine::GameDataRef m_data;
	////////////////////////////////////////////////


	//Primitives
    ////////////////////////////////////////////////
	bool m_isRespawning = false;
	bool m_giveLife = false;
	////////////////////////////////////////////////

	//Clocks
	////////////////////////////////////////////////
	//second timer for AI shots without this only the one in the
    //top of the list shoots
	sf::Clock m_rateOfFire;
	sf::Clock m_spawnTimer;

	
	////////////////////////////////////////////////
	
	//Sprites
	////////////////////////////////////////////////
	sf::Sprite m_background;
	////////////////////////////////////////////////

	//Fonts
	////////////////////////////////////////////////
	sf::Text m_scoreText;
	sf::Text m_livesText;
	sf::Text m_roundText;
	sf::Text m_spawnShieldTimer;
	////////////////////////////////////////////////

	//Objects
	////////////////////////////////////////////////
    std::shared_ptr<ObjectFactory> m_factory;
	GameObject* m_player;
	size_t m_amountOfAI = 1;
	std::vector<GameObject*> m_pTargetList;
	std::vector<GameObject*> m_pPlayerBulletList;
	std::vector<GameObject*> m_pAIBulletList;
	////////////////////////////////////////////////

	//Object Garbage
	////////////////////////////////////////////////
	//std::vector<std::shared_ptr<GameObject>> m_pRemovalPile;
	////////////////////////////////////////////////


    sf::Int32 m_playerScore = 0;
	sf::Int32 m_playerLives = 5;
	sf::Int32 m_roundCounter = 0;
public:

	//c'tor takes in reference to Game Data struct
	GameState(GameEngine::GameDataRef data);

	virtual void Init() override final;
	virtual void HandleInput()override final;
	virtual void Update(float dt)override final;
	virtual void Draw()override final;

private:
	void EndGameCheck();
	void PlayerUpdate(float dt);
	void AIUpdate(float dt);
	void ProjectileUpdate(float dt);
	void CollisionDetection();

	static sf::String toString(sf::Int64 integer)
	{
		std::ostringstream os;
		os << integer;
		return os.str();
	}



	/////////////////////////////////////////////////////////////////////
	//TODO: come back to these still not happy with it 
	//void CollisionDetection_Prototype();
	//void CollisionDetection_Prototype_Two();
	/////////////////////////////////////////////////////////////////////

};

