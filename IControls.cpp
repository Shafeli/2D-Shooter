#include "IControls.h"

#include <chrono>
#include <random>
#include <SFML/Window/Keyboard.hpp>

#include "Definition.h"




///////////////////////////////////
//Movement Controls for a Player
///////////////////////////////////
PlayerControls::PlayerControls(GameDataRef data)
    :m_data(data)
{

}

void PlayerControls::Execute(sf::Sprite& m_sprite, float dt)
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
void AIControls::Execute(sf::Sprite& m_sprite, float dt)
{
    if (s_moveDown)
    {
        m_sprite.move(0, gTargetYAxisDecreaseAmount);
    }
    // Check left side of the window
    if (m_sprite.getGlobalBounds().left <= 0.f)
        m_sprite.move(m_sprite.getGlobalBounds().width / 9, 0.f);

    //check right side of the window 
    if (m_sprite.getGlobalBounds().left + m_sprite.getGlobalBounds().width >= m_data->window.getSize().x)
        m_sprite.move(-m_sprite.getGlobalBounds().width / 9, 0.f);

    if (s_moveSwitch == false)
    {
        // move to left then tell window edge then move right tell window edge repeat
        if (!m_sprite.getGlobalBounds().left <= 0.f)
        {
            m_sprite.move(-gTargetSpeed * dt, 0.f);
        }
        if (m_sprite.getGlobalBounds().left <= 0.f)
        {
            //std::cout << "Target has touched left\n";
         
            m_sprite.move(m_sprite.getGlobalBounds().width / 9, 0.f);
            m_movementSwitch = true;
            s_moveSwitch = true;
            s_moveDown = true;
            m_moveTimer.restart();
            return;
        }
    }
    if (s_moveSwitch == true)
    {
        m_sprite.move(+gTargetSpeed * dt, 0.f);
        if (m_sprite.getGlobalBounds().left + m_sprite.getGlobalBounds().width >= m_data->window.getSize().x)
        {
     
            // std::cout << "Target has touched right\n";
            m_sprite.move(-m_sprite.getGlobalBounds().width / 9, 0.f);
            m_movementSwitch = false;
            s_moveSwitch = false;
            s_moveDown = true;
            m_moveTimer.restart();
        }
    }
    if(m_moveTimer.getElapsedTime().asSeconds() > .3f)
    {
        s_moveDown = false;
    }
}
//left the old rand way of firing its kind of crazy to see the differences visually
bool AIControls::FireShot()
{
    sf::Time time = m_rateOfFire.getElapsedTime();
    //if (!m_fireShot && time > sf::seconds(static_cast<float>(rand() % gAISpawnAmount)))
    //{
    //    m_fireShot = true;
    //    return true;
    //}
    unsigned seed;
    seed = std::chrono::steady_clock::now().time_since_epoch().count();
    std::default_random_engine engine(seed);
    std::uniform_int_distribution<int>distro(0, gAISpawnAmount);
    if (!m_fireShot && time > sf::seconds(distro(engine)))
    {
        m_fireShot = true;
        return true;
    }

    m_fireShot = false;
    return false;
}

bool AIControls::MoveDown()
{
    return m_movementSwitch;
}


//////////////////////////////////////
//Movement Controls for a Projectile
/////////////////////////////////////
ProjectileControls::ProjectileControls(GameDataRef data, float direction)
    :m_data(data)
    ,m_direction(direction)
{
}

void ProjectileControls::Execute(sf::Sprite& m_sprite, float dt)
{
    m_sprite.move(0, m_direction * dt);
}

bool ProjectileControls::FireShot()
{
    return false;
}
