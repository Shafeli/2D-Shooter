#pragma once
#include "GameManager.h"
#include "IAppearanceStrategy.h"
class PlayerAppearanceStrategy : public IAppearanceStrategy
{
    GameEngine::GameDataRef m_data;
public:
    PlayerAppearanceStrategy(GameEngine::GameDataRef data);
    virtual void SetAppearance(sf::Sprite* toChange) override final;

};


