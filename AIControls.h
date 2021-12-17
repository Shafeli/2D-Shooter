#pragma once
#include "IControls.h"


/////////////////////////////////////
//Movement Controls for a AI Enemy
/////////////////////////////////////
class AIControls : public IControls
{
    GameEngine::GameDataRef m_data;

    //Clock for timing rate of fire
    GameEngine::Clock m_rateOfFire;
    //movement switch bool
    bool m_movementSwitch = false;
    //fire shot bool
    bool m_fireShot = false;
    //Clock for timer allowing every object alive to update
    static sf::Clock m_moveTimer;
    //static move switch bool works with timer to move all AI
    static bool s_moveSwitch;
    //static move down bool helps moveing AI
    static bool s_moveDown;
public:
    AIControls(GameEngine::GameDataRef data);
    virtual void Execute(GameObject* object, float dt) override final;
    virtual bool FireShot()override final;

};

