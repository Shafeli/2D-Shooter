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
	GameDataRef m_data;
	////////////////////////////////////////////////

	//Clocks
	////////////////////////////////////////////////
	//second timer for AI shots without this only the one in the
    //top of the list shoots
	sf::Clock m_rateOfFire;
	sf::Clock m_spawnTimer;
	sf::Clock m_musicTimer;
	
	////////////////////////////////////////////////
	
	//Sprites
	////////////////////////////////////////////////
	sf::Sprite m_background;
	////////////////////////////////////////////////

	//Sounds & Fonts
	////////////////////////////////////////////////
	sf::Music m_gameMusic;
	sf::Text m_scoreText;
	sf::Text m_livesText;
	sf::Text m_roundText;
	////////////////////////////////////////////////

	//Objects
	////////////////////////////////////////////////
    std::shared_ptr<ObjectFactory> m_factory;
	std::vector<std::shared_ptr<GameObject>> m_player;
	std::vector<std::shared_ptr<GameObject>> m_pTargetList;
	std::vector<std::shared_ptr<GameObject>> m_pPlayerBulletList;
	std::vector<std::shared_ptr<GameObject>> m_pAIBulletList;
	////////////////////////////////////////////////

	//Object Garbage
	////////////////////////////////////////////////
	std::vector<std::shared_ptr<GameObject>> m_pRemovalPile;
	////////////////////////////////////////////////


    sf::Int32 m_playerScore = 0;
	sf::Int32 m_playerLives = 0;
	sf::Int32 m_roundCounter = 0;
public:

	//c'tor takes in reference to Game Data struct
	GameState(GameDataRef data);


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
	void CollisionDetection_Prototype();
	void CollisionDetection_Prototype_Two();
	void ProjectileOutOfBoundsCleaner();
	void InGameMusic();
	void KillMarkMachine();
	void TargetClearner();
	void PlayerBulletCleaner();
	void PlayerCleaner();
    static sf::String toString(sf::Int64 integer)
	{
		std::ostringstream os;
		os << integer;
		return os.str();
	}
};

