#pragma once
#include "GameManager.h"
#include "ISoundStrategy.h"

class AISoundStrategy : public ISoundStrategy
{
    GameEngine::GameDataRef m_data;
    sf::Sound m_sound;
public:
    AISoundStrategy(GameEngine::GameDataRef data);
    virtual void MakeSound() override final;
};

