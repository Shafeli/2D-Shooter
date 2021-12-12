#pragma once
#include "GameManager.h"
#include <SFML/Graphics.hpp>

class IAppearanceStrategy : std::enable_shared_from_this<IAppearanceStrategy>
{
public:
    virtual ~IAppearanceStrategy() = default;
    virtual void SetAppearance(sf::Sprite* toChange) = 0;
 
};
