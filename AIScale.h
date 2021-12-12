#pragma once
#include "IScaleStrategy.h"
class AIScale :
    public IScaleStrategy
{
public:
    virtual void Scale(sf::Sprite* toScale) override final;
};

