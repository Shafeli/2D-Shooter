#pragma once
#include "IControls.h"


/////////////////////////////////////
//Movement Controls for a AI Enemy
/////////////////////////////////////
class AIControls : public IControls
{
    GameEngine::GameDataRef m_data;
    GameEngine::Clock m_rateOfFire;
    bool m_movementSwitch = false;
    bool m_fireShot = false;
    static inline sf::Clock m_moveTimer;
    static inline bool s_moveSwitch = false;
    static inline bool s_moveDown = false;
public:
    AIControls(GameEngine::GameDataRef data);
    virtual void Execute(GameObject* object, float dt) override final;
    virtual bool FireShot()override final;

};

