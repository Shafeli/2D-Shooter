#pragma once
#include "ISpawnStrategy.h"
class PlayerSpawnStrategy :
    public ISpawnStrategy
{
    GameDataRef m_data;
public:
    PlayerSpawnStrategy(GameDataRef data);
    virtual void Spawn(sf::Sprite* toSpawn) override final;
};

