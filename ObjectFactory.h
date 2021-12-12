#pragma once
#include "GameManager.h"

class GameObject;
class AISpawnStragey;
class ISpawnStragey;

class ObjectFactory : std::enable_shared_from_this<ObjectFactory>
{
    int m_counter;
    GameDataRef m_data;
public:
    ObjectFactory(GameDataRef data);
    void CounterReseter();

    std::shared_ptr<GameObject> MakeAI();
    std::shared_ptr<GameObject> MakePlayer();
    std::shared_ptr<GameObject> MakeProjectile(const sf::Vector2f& pos, float direction);
};

