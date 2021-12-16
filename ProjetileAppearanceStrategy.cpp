#include "ProjetileAppearanceStrategy.h"

ProjetileAppearanceStrategy::ProjetileAppearanceStrategy(GameEngine::GameDataRef data, ProjectileColor color)
    :m_data(data)
    ,m_sprite(nullptr)
    ,m_color(color)
{
}

void ProjetileAppearanceStrategy::SetAppearance(GameEngine::Sprite* toChange)
{
    toChange->setTexture(m_data->assets.GetTexture(AssetManager::Texture::kLazer));
    m_sprite = toChange;
    switch(static_cast<int>(m_color))
    {
    case 0: toChange->setColor(GameEngine::Color::Red); break;
    case 1: toChange->setColor(GameEngine::Color::Green); break;
    }
}

