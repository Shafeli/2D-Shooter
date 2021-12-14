#include "PlayerSoundStrategy.h"

PlayerSoundStrategy::PlayerSoundStrategy(GameEngine::GameDataRef data)
    :m_data(data)
{
    m_sound.setBuffer(m_data->assets.GetSound("PlayerDeath Sound"));
}

void PlayerSoundStrategy::MakeSound()
{
    m_sound.play();
}
