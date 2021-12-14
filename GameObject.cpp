#include "GameObject.h"

#include <iostream>
#include <memory>
#include "IControls.h"
#include "IAppearanceStrategy.h"
#include "ISoundStrategy.h"

///////////////////////////////////////////
// Create Object
///////////////////////////////////////////
GameObject::GameObject(GameEngine::GameDataRef data)
    :m_data(data)
{
}

void GameObject::GameObjectInit()
{
    SetStartAppearance();
}


///////////////////////////////////////////
// Appearance Startegy
///////////////////////////////////////////

void GameObject::SetAppearanceStrategy(std::shared_ptr<IAppearanceStrategy> pAppearanceStrategy)
{
    m_pAppearanceStrategy.push_back(std::move(pAppearanceStrategy));
}
void GameObject::SetStartAppearance()
{
    m_pAppearanceStrategy.at(0)->SetAppearance(&m_sprite);
}
void GameObject::SetDeathAppearance()
{
    if (m_pAppearanceStrategy.capacity() > 1)
    {
        m_pAppearanceStrategy.at(1)->SetAppearance(&m_sprite);
        return;
    }
    std::cout << "NO Death Appearance set\n";
}
///////////////////////////////////////////
// Controls
///////////////////////////////////////////
void GameObject::SetControls(std::shared_ptr<IControls> controls)
{
    m_pControlType = std::move(controls);
}
void GameObject::Update(float dt)
{
    //if(m_isAlive)
    m_pControlType->Execute(m_sprite, dt);
}

///////////////////////////////////////////
// Draws Sprite to Window 
///////////////////////////////////////////
void GameObject::Draw()
{
    if (m_isAlive)
    {
        m_data->window.draw(m_sprite);
    }
    if (m_pAppearanceStrategy.capacity() > 1)
    {
        m_data->window.draw(m_sprite);
    }
   
}

///////////////////////////////////////////
// Sound
///////////////////////////////////////////

void GameObject::SetSound(std::shared_ptr<ISoundStrategy> sound)
{
    m_pSoundStrategy.push_back(std::move(sound));
}
void GameObject::MakeSound()
{
    for (auto& i : m_pSoundStrategy)
    {
        i->MakeSound();
    }
}

///////////////////////////////////////////
// returns if pControl has used action button
///////////////////////////////////////////
bool GameObject::OnUse()
{
    if (!m_isAlive)
    {
        return false;
    }
   return m_pControlType->FireShot();
}

bool GameObject::TargetMoveFlag()
{
    return m_pControlType->MoveDown();
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
sf::Sprite& GameObject::GetSprite()
{
    return m_sprite;
}

void GameObject::MarkedForDeath()
{
    m_isAlive = false;
}
//
//////////////////////////////////////////////////////////////////////////////////////