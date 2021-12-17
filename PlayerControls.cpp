#include "PlayerControls.h"

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

    //if button is pressed A is press move left
    if (m_data->input.APressed())
    {
        object->GetSprite().move(-m_data->FilingCabinet.GetConfigFloat(FileManager::FileData::kPlayerSpeed) * dt, 0.f);
    }
    //if button is pressed D is press move right
    else if (m_data->input.DPressed())
    {
        object->GetSprite().move(+m_data->FilingCabinet.GetConfigFloat(FileManager::FileData::kPlayerSpeed) * dt, 0.f);
    }
    //if button is pressed Space is press and time is greater then n time turn bool on reset timer 
    if (m_data->input.SpacePressed())
    {
        if (m_rateOfFire.getElapsedTime().asSeconds() > m_data->FilingCabinet.GetConfigFloat(FileManager::FileData::kPlayerRateOfFire))
        {
            m_fireShot = true;
            m_rateOfFire.restart();
        }
    }
}

//flag to game if true make a projectile or x object / do task 
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