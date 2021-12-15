#include "DeathAppearanceStrategy.h"

DeathAppearanceStrategy::DeathAppearanceStrategy(GameEngine::GameDataRef data)
    :m_data(data)
{
}

void DeathAppearanceStrategy::SetAppearance(GameEngine::Sprite* toChange)
{
    toChange->setTexture(m_data->assets.GetTexture("Death Sprite"));
}
