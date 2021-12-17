#include "AIControls.h"

#include <chrono>
#include <random>

#include "Definition.h"
#include "GameObject.h"


/////////////////////////////////////
//Movement Controls for a AI Enemy
/////////////////////////////////////
AIControls::AIControls(GameEngine::GameDataRef data)
    :m_data(data)
{
}
// SFML doesnt compile on c++ 17 sad 
 sf::Clock AIControls::m_moveTimer;
 bool AIControls::s_moveSwitch = false;
 bool AIControls::s_moveDown = false;

void AIControls::Execute(GameObject* object, float dt)
{
    //if true move down x amount in y axis
    if (s_moveDown)
    {
        object->GetSprite().move(0, m_data->FilingCabinet.GetConfigFloat(FileManager::FileData::kAIDecressTimer));
    }
    // Check left side of the window
    if (m_data->collisionDection.DoesObjectTouchWindowLeft(object))
        object->GetSprite().move(object->GetSprite().getGlobalBounds().width / 9, 0.f);

    //check right side of the window 
    if (m_data->collisionDection.DoesObjectTouchWindowRight(object, &m_data->window))
        object->GetSprite().move(-object->GetSprite().getGlobalBounds().width / 9, 0.f);

    //if switch is false move left
    if (s_moveSwitch == false)
    {
#pragma warning(disable : 4804)

        // move to left then tell window edge then move right tell window edge repeat
        if (!m_data->collisionDection.DoesObjectTouchWindowLeft(object))
#pragma warning(default : 4804)
        {
            object->GetSprite().move(-m_data->FilingCabinet.GetConfigFloat(FileManager::FileData::kAISpeed) * dt, 0.f);
        }
        if (m_data->collisionDection.DoesObjectTouchWindowLeft(object))
        {
            //std::cout << "Target has touched left\n";

            object->GetSprite().move(object->GetSprite().getGlobalBounds().width / 9, 0.f);
            m_movementSwitch = true;
            s_moveSwitch = true;
            s_moveDown = true;
            m_moveTimer.restart();
            return;
        }
    }
    //if switch is true move right
    if (s_moveSwitch == true)
    {
        object->GetSprite().move(+m_data->FilingCabinet.GetConfigFloat(FileManager::FileData::kAISpeed) * dt, 0.f);
        if (object->GetSprite().getGlobalBounds().left + object->GetSprite().getGlobalBounds().width >= m_data->window.getSize().x)
        {

            // std::cout << "Target has touched right\n";
            object->GetSprite().move(-object->GetSprite().getGlobalBounds().width / 9, 0.f);
            m_movementSwitch = false;
            s_moveSwitch = false;
            s_moveDown = true;
            m_moveTimer.restart();
        }
    }
    //timer resets move bool
    if (m_moveTimer.getElapsedTime().asSeconds() > .3f)
    {
        s_moveDown = false;
    }
}

#pragma warning(disable : 4244)
//fire shot works by useing a distribution sends down a flag true or false to game where a timer is for rate of fire that either allows the AI to shoot or not
//the result is all AI randomly get to shoot and game blocks them if they have shot to soon so they "should not" be able to spam shots down
bool AIControls::FireShot()
{
    const GameEngine::Time time = m_rateOfFire.getElapsedTime();
    const unsigned seed = std::chrono::steady_clock::now().time_since_epoch().count();
    std::default_random_engine engine(seed);
    const std::uniform_int_distribution<int>distro(0, m_data->FilingCabinet.GetConfigInt(FileManager::FileData::kAIRandomFireDistro));
    if (!m_fireShot && time > sf::seconds(distro(engine)))
    {
        m_fireShot = true;
        return true;
    }
    m_fireShot = false;
    return false;
}
#pragma warning(default : 4244)