#pragma once
#include "GameManager.h"
#include "ISpawnStrategy.h"

class AISpawnStrategy : public ISpawnStrategy
{
    int m_spawnCount;
    GameDataRef m_data;
    float m_yAxis = 30.f;
public:

    AISpawnStrategy(GameDataRef data ,int spawnCount);
    virtual void Spawn( sf::Sprite* toSpawn) override final;
    void SpawnReset();
    void YAxiesAdfustment();
    void SpawnPositionSetter(sf::Sprite* toSpawn);
};


