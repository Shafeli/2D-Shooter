#include "ProjectileSpawnStrategy.h"

ProjectileSpawnStrategy::ProjectileSpawnStrategy(const sf::Vector2f& pos)
    :m_pos(pos)
{
}

void ProjectileSpawnStrategy::Spawn(sf::Sprite* toSpawn)
{
    toSpawn->setPosition(m_pos);
}
