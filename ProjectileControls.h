#pragma once
#include "GameManager.h"
#include "IControls.h"

class GameObject;

//////////////////////////////////////
//Movement Controls for a Projectile
/////////////////////////////////////
class ProjectileControls : public IControls
{
    GameEngine::GameDataRef m_data;
    float m_direction;
public:
    ProjectileControls(GameEngine::GameDataRef data, float direction);

    virtual void Execute(GameObject* object, float dt) override final;
    virtual bool FireShot()override final;
};

