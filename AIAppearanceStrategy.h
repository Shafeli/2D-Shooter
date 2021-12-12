#pragma once
#include "GameManager.h"
#include "IAppearanceStrategy.h"

class AIAppearanceStrategy : public IAppearanceStrategy
{
    GameDataRef m_data;
public:
    AIAppearanceStrategy(GameDataRef data);
    void SetAppearance(sf::Sprite* toChange) override;
 
};

