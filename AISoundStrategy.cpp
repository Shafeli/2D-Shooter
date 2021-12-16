#include "AISoundStrategy.h"

AISoundStrategy::AISoundStrategy(GameEngine::GameDataRef data)
    :m_data(data)
{
    m_sound.setBuffer(m_data->assets.GetSound(AssetManager::Sound::kEnemyDeath));
}

void AISoundStrategy::MakeSound()
{
    m_sound.play();
}
