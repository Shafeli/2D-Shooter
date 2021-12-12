#pragma once
#include "GameManager.h"
#include "ISoundStrategy.h"

class AISoundStrategy : public ISoundStrategy
{
    GameDataRef m_data;
    sf::Sound m_sound;
public:
    AISoundStrategy(GameDataRef data);
    virtual void MakeSound() override final;
};

