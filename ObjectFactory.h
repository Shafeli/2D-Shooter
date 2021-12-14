#pragma once
#include "GameManager.h"

class GameObject;

class ObjectFactory : std::enable_shared_from_this<ObjectFactory>
{
    GameEngine::GameDataRef m_data;
public:
    ObjectFactory(GameEngine::GameDataRef data);
    void CounterReseter();

    GameObject* MakeAI(int spawnCounter);
    GameObject* MakePlayer();
    GameObject* MakeProjectile(const sf::Vector2f& pos, float direction);
};

