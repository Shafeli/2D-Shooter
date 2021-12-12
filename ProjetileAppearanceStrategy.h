#pragma once
#include "GameManager.h"
#include "IAppearanceStrategy.h"
class ProjetileAppearanceStrategy : public IAppearanceStrategy
{
    GameDataRef m_data;
  sf::Sprite* m_sprite;
public:
    ProjetileAppearanceStrategy(GameDataRef data);
    void SetAppearance(sf::Sprite* toChange) override;

};

