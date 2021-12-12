#include "ProjetileAppearanceStrategy.h"

ProjetileAppearanceStrategy::ProjetileAppearanceStrategy(GameDataRef data)
    :m_data(data)
    ,m_sprite(nullptr)
{
}

void ProjetileAppearanceStrategy::SetAppearance(sf::Sprite* toChange)
{
    toChange->setTexture(m_data->assets.GetTexture("Bullet Sprite"));
    m_sprite = toChange;
}

