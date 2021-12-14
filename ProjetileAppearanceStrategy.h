#pragma once
#include "GameManager.h"
#include "IAppearanceStrategy.h"
class ProjetileAppearanceStrategy : public IAppearanceStrategy
{
    GameEngine::GameDataRef m_data;
  sf::Sprite* m_sprite;
public:
    ProjetileAppearanceStrategy(GameEngine::GameDataRef data);
    void SetAppearance(sf::Sprite* toChange) override;

};

