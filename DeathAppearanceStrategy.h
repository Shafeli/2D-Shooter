#pragma once
#include "IAppearanceStrategy.h"
class DeathAppearanceStrategy : public IAppearanceStrategy
{
    GameEngine::GameDataRef m_data;
public:
    DeathAppearanceStrategy(GameEngine::GameDataRef data);
    virtual void SetAppearance(GameEngine::Sprite* toChange) override final;
};

