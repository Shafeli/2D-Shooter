#pragma once
#include "GameManager.h"
#include "ISoundStrategy.h"
class ProjectileSoundStrategy : public ISoundStrategy
{
    GameEngine::GameDataRef m_data;
    sf::Sound m_sound;
public:
    ProjectileSoundStrategy(GameEngine::GameDataRef data);
    virtual void MakeSound() override final;
};

