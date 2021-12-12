#include "PlayerAppearanceStrategy.h"

PlayerAppearanceStrategy::PlayerAppearanceStrategy(GameDataRef data)
    :m_data(data)
{
}

void PlayerAppearanceStrategy::SetAppearance(sf::Sprite* toChange)
{
    toChange->setTexture(m_data->assets.GetTexture("Player Sprite"));
}
