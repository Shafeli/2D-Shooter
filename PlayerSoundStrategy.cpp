#include "PlayerSoundStrategy.h"

#include "Definition.h"

PlayerSoundStrategy::PlayerSoundStrategy(GameEngine::GameDataRef data)
    :m_data(data)
{
    m_sound.setBuffer(m_data->assets.GetSound(AssetManager::Sound::kPlayerDeath));
    m_sound.setVolume(gBulletSoundLevel);
}

void PlayerSoundStrategy::MakeSound()
{
    m_sound.play();
}
