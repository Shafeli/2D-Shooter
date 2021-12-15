#include "PlayerSoundStrategy.h"

#include "Definition.h"

PlayerSoundStrategy::PlayerSoundStrategy(GameEngine::GameDataRef data)
    :m_data(data)
{
    m_sound.setBuffer(m_data->assets.GetSound("PlayerDeath Sound"));
    m_sound.setVolume(gBulletSoundLevel);
}

void PlayerSoundStrategy::MakeSound()
{
    m_sound.play();
}
