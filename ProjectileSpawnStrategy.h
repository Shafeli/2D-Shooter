#pragma once
#include "ISpawnStrategy.h"
class ProjectileSpawnStrategy :
    public ISpawnStrategy
{
    const sf::Vector2f& m_pos;
public:
    ProjectileSpawnStrategy(const sf::Vector2f& pos);
    virtual void Spawn(sf::Sprite* toSpawn) override final;
};

