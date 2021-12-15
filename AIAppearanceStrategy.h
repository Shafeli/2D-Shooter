#pragma once
#include "GameManager.h"
#include "IAppearanceStrategy.h"

class AIAppearanceStrategy : public IAppearanceStrategy
{
    GameEngine::GameDataRef m_data;
public:
    AIAppearanceStrategy(GameEngine::GameDataRef data);
    void SetAppearance(GameEngine::Sprite* toChange) override;
 
};

