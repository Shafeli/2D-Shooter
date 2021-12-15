#include "AIAppearanceStrategy.h"
#include "GameObject.h"

AIAppearanceStrategy::AIAppearanceStrategy(GameEngine::GameDataRef data)
    :m_data(data)
{
}

void AIAppearanceStrategy::SetAppearance(GameEngine::Sprite* toChange)
{
    toChange->setTexture(m_data->assets.GetTexture("Target Sprite"));
}
