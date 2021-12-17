#pragma once
#include "GameManager.h"
#include "ProjetileAppearanceStrategy.h"

class GameObject;

class ObjectFactory : std::enable_shared_from_this<ObjectFactory>
{
    GameEngine::GameDataRef m_data;
public:
    ObjectFactory(GameEngine::GameDataRef data);

    void CounterReseter();

    // Object builder functions
    ///////////////////////////////////////////////////////////////////
    GameObject* MakeAI(int spawnCounter);
    GameObject* MakePlayer();
    GameObject* MakeProjectile(const sf::Vector2f& pos, float direction, ProjetileAppearanceStrategy::ProjectileColor color);
};

