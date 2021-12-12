#pragma once
#include "GameManager.h"
#include "ISpawnStrategy.h"

class AISpawnStrategy : public ISpawnStrategy
{
    int m_spawnCount;
    GameDataRef m_data;
public:

    AISpawnStrategy(GameDataRef data ,int spawnCount);
    virtual void Spawn( sf::Sprite* toSpawn) override final;
};


