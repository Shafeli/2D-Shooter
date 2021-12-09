#include "Target.h"
#include <iostream>
#include "Definition.h"
Target::Target(GameDataRef data, size_t targetNum)
    :m_data(data)
{
    m_sprite.setTexture(m_data->assets.GetTexture("Target Sprite"));
    m_sprite.setScale(sf::Vector2f(0.2f, 0.2f));
   // m_sprite.setPosition((m_data->window.getSize().x / 2 ) - (m_sprite.getGlobalBounds().width / 2), 0 + (m_sprite.getGlobalBounds().height / 2));
    // 5ths .2 .6 .8 
    switch (targetNum)
    {
    case 0:
        m_sprite.setPosition((m_data->window.getSize().x - 725) - (m_sprite.getGlobalBounds().width / 2), 0 + (m_sprite.getGlobalBounds().height / 2));
        break;
    case 1:
        m_sprite.setPosition((m_data->window.getSize().x - 650) - (m_sprite.getGlobalBounds().width / 2), 0 + (m_sprite.getGlobalBounds().height / 2));
        break;
    case 2:
        m_sprite.setPosition((m_data->window.getSize().x - 50) - (m_sprite.getGlobalBounds().width / 2), 0 + (m_sprite.getGlobalBounds().height / 2));
        break;
    case 3:
        m_sprite.setPosition((m_data->window.getSize().x - 125) - (m_sprite.getGlobalBounds().width / 2), 0 + (m_sprite.getGlobalBounds().height / 2));
        break;
    case 4:
        m_sprite.setPosition((m_data->window.getSize().x - 200) - (m_sprite.getGlobalBounds().width / 2), 0 + (m_sprite.getGlobalBounds().height / 2));
        break;
    case 5:
        m_sprite.setPosition((m_data->window.getSize().x - 275) - (m_sprite.getGlobalBounds().width / 2), 0 + (m_sprite.getGlobalBounds().height / 2));
        break;
    case 6:
        m_sprite.setPosition((m_data->window.getSize().x - 350) - (m_sprite.getGlobalBounds().width / 2), 0 + (m_sprite.getGlobalBounds().height / 2));
        break;
    case 7:
        m_sprite.setPosition((m_data->window.getSize().x - 425) - (m_sprite.getGlobalBounds().width / 2), 0 + (m_sprite.getGlobalBounds().height / 2));
        break;
    case 8:
        m_sprite.setPosition((m_data->window.getSize().x - 500) - (m_sprite.getGlobalBounds().width / 2), 0 + (m_sprite.getGlobalBounds().height / 2));
        break;
    case 9:
        m_sprite.setPosition((m_data->window.getSize().x - 575) - (m_sprite.getGlobalBounds().width / 2), 0 + (m_sprite.getGlobalBounds().height / 2));
        break;
    }

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
            //std::cout << "Target has touched left\n";
            m_sprite.move(0, gTargetYAxisDecreaseAmount);
            m_movementSwitch = true;
            return;
        }
    }
    if (m_movementSwitch == true)
    {
        m_sprite.move(+gTargetSpeed, 0.f);
        if (m_sprite.getGlobalBounds().left + m_sprite.getGlobalBounds().width >= m_data->window.getSize().x)
        {
            m_sprite.move(0, gTargetYAxisDecreaseAmount);
           // std::cout << "Target has touched right\n";
            m_movementSwitch = false;
        }
    }
}

const sf::Vector2f& Target::GetPOS()
{
    // TODO: insert return statement here
    return m_sprite.getPosition();
}

const sf::Sprite& Target::GetSprite()
{
    // TODO: insert return statement here
    return m_sprite;
}
