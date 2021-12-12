#pragma once
#include "GameManager.h"
#include "IAppearanceStrategy.h"
class PlayerAppearanceStrategy : public IAppearanceStrategy
{
    GameDataRef m_data;
public:
    PlayerAppearanceStrategy(GameDataRef data);
    virtual void SetAppearance(sf::Sprite* toChange) override final;

};


