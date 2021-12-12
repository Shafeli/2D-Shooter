#pragma once
#include "IAppearanceStrategy.h"
class DeathAppearanceStrategy : public IAppearanceStrategy
{
    GameDataRef m_data;
public:
    DeathAppearanceStrategy(GameDataRef data);
    virtual void SetAppearance(sf::Sprite* toChange) override final;
};

