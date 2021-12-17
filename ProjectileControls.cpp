#include "ProjectileControls.h"

#include "GameObject.h"

//////////////////////////////////////
//Movement Controls for a Projectile
/////////////////////////////////////
ProjectileControls::ProjectileControls(GameEngine::GameDataRef data, float direction)
    :m_data(data)
    , m_direction(direction)
{
}

//once spawning move m_direction * delta time
void ProjectileControls::Execute(GameObject* object, float dt)
{
    object->GetSprite().move(0, m_direction * dt);
}

bool ProjectileControls::FireShot()
{
    return false;
}