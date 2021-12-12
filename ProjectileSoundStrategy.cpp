#include "ProjectileSoundStrategy.h"

ProjectileSoundStrategy::ProjectileSoundStrategy(GameDataRef data)
    :m_data(data)
{
    m_sound.setBuffer(m_data->assets.GetSound("Lazer Sound"));
}

void ProjectileSoundStrategy::MakeSound()
{
    m_sound.play();
}
