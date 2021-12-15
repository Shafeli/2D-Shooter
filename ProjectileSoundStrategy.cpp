#include "ProjectileSoundStrategy.h"

#include "Definition.h"

ProjectileSoundStrategy::ProjectileSoundStrategy(GameEngine::GameDataRef data)
    :m_data(data)
{
    m_sound.setBuffer(m_data->assets.GetSound("Lazer Sound"));
    m_sound.setVolume(gBulletSoundLevel);
}

void ProjectileSoundStrategy::MakeSound()
{
    m_sound.play();
}