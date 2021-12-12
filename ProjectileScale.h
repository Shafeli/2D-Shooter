#pragma once
#include "IScaleStrategy.h"
class ProjectileScale : public IScaleStrategy
{
public:
    virtual void Scale(sf::Sprite* toScale) override final;
};

