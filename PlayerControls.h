#pragma once
#include "IControls.h"

///////////////////////////////////
//Movement Controls for a Player
///////////////////////////////////
class PlayerControls : public IControls
{
GameEngine::GameDataRef m_data;
GameEngine::Clock m_rateOfFire;
bool m_fireShot = false;

public:
    PlayerControls(GameEngine::GameDataRef data);
    virtual void Execute(GameObject* object, float dt) override final;
    virtual bool FireShot() override final;
};

