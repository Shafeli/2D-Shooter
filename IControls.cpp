#include "IControls.h"

#include <SFML/Window/Keyboard.hpp>

#include "Definition.h"




///////////////////////////////////
//Movement Controls for a Player
///////////////////////////////////
PlayerControls::PlayerControls(GameDataRef data)
    :m_data(data)
{

}

void PlayerControls::Execute(sf::Sprite& m_sprite, float Yaxis, float dt)
{
    // Check left side of the window
    if (m_sprite.getGlobalBounds().left <= 0.f)
        m_sprite.move(m_sprite.getGlobalBounds().width / 9, 0.f);

    //check right side of the window 
    if (m_sprite.getGlobalBounds().left + m_sprite.getGlobalBounds().width >= m_data->window.getSize().x)
        m_sprite.move(-m_sprite.getGlobalBounds().width / 9, 0.f);


    if (sf::Keyboard::isKeyPressed(sf::Keyboard::A))
    {
        m_sprite.move(-gPlayerSpeed * dt, 0.f);
    }
    else if (sf::Keyboard::isKeyPressed(sf::Keyboard::D))
    {
        m_sprite.move(+gPlayerSpeed * dt, 0.f);
    }
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Space))
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


/////////////////////////////////////
//Movement Controls for a AI Enemy
/////////////////////////////////////
AIControls::AIControls(GameDataRef data)
    :m_data(data)
{

}
void AIControls::Execute(sf::Sprite& m_sprite, float Yaxis ,float dt)
{
    // Check left side of the window
    if (m_sprite.getGlobalBounds().left <= 0.f)
        m_sprite.move(m_sprite.getGlobalBounds().width / 9, 0.f);

    //check right side of the window 
    if (m_sprite.getGlobalBounds().left + m_sprite.getGlobalBounds().width >= m_data->window.getSize().x)
        m_sprite.move(-m_sprite.getGlobalBounds().width / 9, 0.f);

    if (m_movementSwitch == false)
    {
        // move to left then tell window edge then move right tell window edge repeat
        if (!m_sprite.getGlobalBounds().left <= 0.f)
        {
            m_sprite.move(-gTargetSpeed * dt, 0.f);
        }
        if (m_sprite.getGlobalBounds().left <= 0.f)
        {
            //std::cout << "Target has touched left\n";
            m_sprite.move(0, gTargetYAxisDecreaseAmount);
            m_movementSwitch = true;
            return;
        }
    }
    if (m_movementSwitch == true)
    {
        m_sprite.move(+gTargetSpeed * dt, 0.f);
        if (m_sprite.getGlobalBounds().left + m_sprite.getGlobalBounds().width >= m_data->window.getSize().x)
        {
            m_sprite.move(0, gTargetYAxisDecreaseAmount);
            // std::cout << "Target has touched right\n";
            m_movementSwitch = false;
        }
    }
}

bool AIControls::FireShot()
{
    sf::Time time = m_rateOfFire.getElapsedTime();

    if (!m_fireShot && time > sf::seconds(static_cast<float>(rand() % 10)))
    {
        m_fireShot = true;
        return true;
    }

    m_fireShot = false;
    return false;
}


//////////////////////////////////////
//Movement Controls for a Projectile
/////////////////////////////////////
ProjectileControls::ProjectileControls(GameDataRef data)
    :m_data(data)
{
}

void ProjectileControls::Execute(sf::Sprite& m_sprite, float Yaxis, float dt)
{
    m_sprite.move(0, Yaxis * dt);
}

bool ProjectileControls::FireShot()
{
    return false;
}
