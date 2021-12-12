#include "DeathAppearanceStrategy.h"

DeathAppearanceStrategy::DeathAppearanceStrategy(GameDataRef data)
    :m_data(data)
{
}

void DeathAppearanceStrategy::SetAppearance(sf::Sprite* toChange)
{
    toChange->setTexture(m_data->assets.GetTexture("Death Sprite"));
}
