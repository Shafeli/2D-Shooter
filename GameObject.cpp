#include "GameObject.h"

#include <iostream>
#include <memory>
#include "IControls.h"


///////////////////////////////////////////
// Create Player
///////////////////////////////////////////
GameObject::GameObject(GameDataRef data)
    :m_data(data)
    ,m_direction(0)
{
    m_sprite.setTexture(m_data->assets.GetTexture("Player Sprite"));
    m_sound.setBuffer(m_data->assets.GetSound("PlayerDeath Sound"));
    m_sprite.setScale(sf::Vector2f(0.2f, 0.2f));
    m_sprite.setPosition((m_data->window.getSize().x / 2) - (m_sprite.getGlobalBounds().width / 2),
    m_data->window.getSize().y - m_sprite.getGlobalBounds().height);
    m_pControlType = std::make_shared<PlayerControls>(m_data);
}

///////////////////////////////////////////
// Create AI
///////////////////////////////////////////
GameObject::GameObject(GameDataRef data, size_t targetNum)
    :m_data(data)
    ,m_direction(0)
{
    m_sprite.setTexture(m_data->assets.GetTexture("Target Sprite"));
    m_sprite.setScale(sf::Vector2f(0.2f, 0.2f));
   
    m_pControlType = std::make_shared<AIControls>(m_data);
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
    default: std::cout << "Failed AI Spawn\n";
    }
}


///////////////////////////////////////////
// Create Projectile 
///////////////////////////////////////////
GameObject::GameObject(GameDataRef data, const sf::Vector2f& pos, float Direction)
    :m_data(data)
    , m_direction(Direction)
{
    m_sprite.setTexture(m_data->assets.GetTexture("Bullet Sprite"));
    m_sound.setBuffer(m_data->assets.GetSound("Lazer Sound"));
    m_sprite.setScale(sf::Vector2f(0.1f, 0.2f));
    m_pControlType = std::make_shared<ProjectileControls>(m_data);
    m_sprite.setPosition(pos);
}


///////////////////////////////////////////
// pControl -> Exicute
///////////////////////////////////////////
void GameObject::Update(float dt)
{
    m_pControlType->Execute(m_sprite, m_direction, dt);
}


///////////////////////////////////////////
// Draws Sprite to Window 
///////////////////////////////////////////
void GameObject::Draw()
{
    m_data->window.draw(m_sprite);
}


///////////////////////////////////////////
// m_sound -> Play
///////////////////////////////////////////
void GameObject::MakeSound()
{
    m_sound.play();
}

///////////////////////////////////////////
// returns if pControl has used action button
///////////////////////////////////////////
bool GameObject::OnUse()
{
   return m_pControlType->FireShot();
}


//////////////////////////////////////////////////////////////////////////////////////
//
///////////////////////////////////////////
// Current Hit dectection 
///////////////////////////////////////////
const sf::Vector2f& GameObject::GetPOS()
{
    return m_sprite.getPosition();
}
//
const sf::Sprite& GameObject::GetSprite()
{
    return m_sprite;
}
//
//////////////////////////////////////////////////////////////////////////////////////