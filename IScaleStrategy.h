#pragma once
#include "GameManager.h"
#include <SFML/Graphics.hpp>

class IScaleStrategy : std::enable_shared_from_this<IScaleStrategy>
{
 
public:
    virtual ~IScaleStrategy() = default;
    virtual void Scale(sf::Sprite* toScale) = 0;
};

