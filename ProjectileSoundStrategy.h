#pragma once
#include "GameManager.h"
#include "ISoundStrategy.h"
class ProjectileSoundStrategy : public ISoundStrategy
{
    GameDataRef m_data;
    sf::Sound m_sound;
public:
    ProjectileSoundStrategy(GameDataRef data);
    virtual void MakeSound() override final;
};

