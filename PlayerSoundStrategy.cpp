#include "PlayerSoundStrategy.h"


PlayerSoundStrategy::PlayerSoundStrategy(GameEngine::GameDataRef data)
    :m_data(data)
{
    m_sound.setBuffer(m_data->assets.GetSound(AssetManager::Sound::kPlayerDeath));
    m_sound.setVolume(m_data->jukebox.GetMasterVolume());
}

void PlayerSoundStrategy::MakeSound()
{
    m_sound.play();
}
