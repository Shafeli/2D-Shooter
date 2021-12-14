#include "PlayerAppearanceStrategy.h"

#include <utility>

PlayerAppearanceStrategy::PlayerAppearanceStrategy(GameEngine::GameDataRef data)
    :m_data(std::move(data))
{
}

void PlayerAppearanceStrategy::SetAppearance(sf::Sprite* toChange)
{
    toChange->setTexture(m_data->assets.GetTexture("Player Sprite"));
}
