#include "PlayerControls.h"

#include "Definition.h"
#include "GameObject.h"


///////////////////////////////////
//Movement Controls for a Player
///////////////////////////////////
PlayerControls::PlayerControls(GameEngine::GameDataRef data)
    :m_data(data)
{

}

void PlayerControls::Execute(GameObject* object, float dt)
{
    // Check left side of the window
    if (m_data->collisionDection.DoesObjectTouchWindowLeft(object))
        object->GetSprite().move(object->GetSprite().getGlobalBounds().width / 9, 0.f);

    //check right side of the window 
    if (m_data->collisionDection.DoesObjectTouchWindowRight(object,&m_data->window))
        object->GetSprite().move(-object->GetSprite().getGlobalBounds().width / 9, 0.f);


    if (m_data->input.AIsPressed())
    {
        object->GetSprite().move(-gPlayerSpeed * dt, 0.f);
    }
    else if (m_data->input.DIsPressed())
    {
        object->GetSprite().move(+gPlayerSpeed * dt, 0.f);
    }
    if (m_data->input.SpaceIsPressed())
    {
        if (m_rateOfFire.getElapsedTime().asSeconds() > gRateOfFire)
        {
            m_fireShot = true;
            m_rateOfFire.restart();
        }
    }
}

bool PlayerControls::FireShot()
{
    bool isShot = false;

    if (m_fireShot)
    {
        isShot = true;
    }

    m_fireShot = false;

    return isShot;
}