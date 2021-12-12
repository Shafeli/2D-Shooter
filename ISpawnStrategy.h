#pragma once
#include <SFML/Graphics/Sprite.hpp>

#include "GameManager.h"

class ISpawnStrategy
{
public:
    virtual ~ISpawnStrategy() = default;
    virtual void Spawn(sf::Sprite* toSpawn) = 0;

};

