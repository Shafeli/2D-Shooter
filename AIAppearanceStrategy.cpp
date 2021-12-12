#include "AIAppearanceStrategy.h"
#include "GameObject.h"

AIAppearanceStrategy::AIAppearanceStrategy(GameDataRef data)
    :m_data(data)
{
}

void AIAppearanceStrategy::SetAppearance(sf::Sprite* toChange)
{
    toChange->setTexture(m_data->assets.GetTexture("Target Sprite"));
}
