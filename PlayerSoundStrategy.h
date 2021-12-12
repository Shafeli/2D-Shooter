#pragma once
#include "GameManager.h"
#include "ISoundStrategy.h"

class PlayerSoundStrategy : public ISoundStrategy
{
    GameDataRef m_data;
    sf::Sound m_sound;
public:
    PlayerSoundStrategy(GameDataRef data);
    virtual void MakeSound() override final;
};

