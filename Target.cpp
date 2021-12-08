#include "Target.h"
#include <iostream>
#include "Definition.h"
Target::Target(GameDataRef data)
    :m_data(data)
{
    m_sprite.setTexture(m_data->assets.GetTexture("Target Sprite"));
    m_sprite.setScale(sf::Vector2f(0.2f, 0.2f));
    m_sprite.setPosition((m_data->window.getSize().x / 2 ) - (m_sprite.getGlobalBounds().width / 2), 0 + (m_sprite.getGlobalBounds().height / 2));
}

void Target::Draw()
{
    m_data->window.draw(m_sprite);
}

void Target::Update(float dt)
{
  
        // Check left side of the window
    if (m_sprite.getGlobalBounds().left <= 0.f)
        m_sprite.move(m_sprite.getGlobalBounds().width / 9 ,0.f);

    //check right side of the window 
    if (m_sprite.getGlobalBounds().left + m_sprite.getGlobalBounds().width >= m_data->window.getSize().x)
        m_sprite.move(-m_sprite.getGlobalBounds().width / 9, 0.f);

    if (m_movementSwitch == false)
    {
        // move to left then tell window edge then move right tell window edge repeat
        if (!m_sprite.getGlobalBounds().left <= 0.f)
        {
            m_sprite.move(-gTargetSpeed, 0.f);
        }
        if (m_sprite.getGlobalBounds().left <= 0.f)
        {
            std::cout << "Target has touched left\n";
            m_sprite.move(0, gTargetYAxisAmount);
            m_movementSwitch = true;
            return;
        }
    }
    if (m_movementSwitch == true)
    {
        m_sprite.move(+gTargetSpeed, 0.f);
        if (m_sprite.getGlobalBounds().left + m_sprite.getGlobalBounds().width >= m_data->window.getSize().x)
        {
            m_sprite.move(0, gTargetYAxisAmount);
            std::cout << "Target has touched right\n";
            m_movementSwitch = false;
        }
    }
}
