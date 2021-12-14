#pragma once
#include "GameManager.h"
#include "ISoundStrategy.h"

class PlayerSoundStrategy : public ISoundStrategy
{
    GameEngine::GameDataRef m_data;
    sf::Sound m_sound;
public:
    PlayerSoundStrategy(GameEngine::GameDataRef data);
    virtual void MakeSound() override final;
};

