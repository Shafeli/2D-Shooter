#pragma once
#include "IScaleStrategy.h"
class PlayerScale :
    public IScaleStrategy
{
public:
    virtual void Scale(sf::Sprite* toScale) override final;
};

