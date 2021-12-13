#include "AISoundStrategy.h"

AISoundStrategy::AISoundStrategy(GameDataRef data)
    :m_data(data)
{
    m_sound.setBuffer(m_data->assets.GetSound("Boom Sound"));
}

void AISoundStrategy::MakeSound()
{
    m_sound.play();
}
