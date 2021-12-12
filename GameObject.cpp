#include "GameObject.h"

#include <iostream>
#include <memory>
#include "IControls.h"
#include "IScaleStrategy.h"
#include "ISpawnStrategy.h"
#include "IAppearanceStrategy.h"
#include "ISoundStrategy.h"

///////////////////////////////////////////
// Create Object
///////////////////////////////////////////
GameObject::GameObject(GameDataRef data)
    :m_data(data)
    ,m_direction(0)
{
  
}

void GameObject::GameObjectInit()
{
    SetAppearance();
    Scale();
    Spawn();
}

///////////////////////////////////////////
// Spawn Startegy
///////////////////////////////////////////
void GameObject::SetSpawn(std::shared_ptr<ISpawnStrategy> pSpawnStrategy)
{
    m_pSpawnStrategy.push_back(std::move(pSpawnStrategy));
}

void GameObject::Spawn()
{
    for(auto&i : m_pSpawnStrategy)
    {
        i->Spawn(&m_sprite);
    }
}

///////////////////////////////////////////
// Spawn Startegy
///////////////////////////////////////////
void GameObject::SetScale(std::shared_ptr<IScaleStrategy>pSacleStrategy)
{
    m_pSacleStrategy.push_back(pSacleStrategy);
}
void GameObject::Scale()
{
    for (auto& i : m_pSacleStrategy)
    {
        i->Scale(&m_sprite);
    }
}


///////////////////////////////////////////
// Appearance Startegy
///////////////////////////////////////////

void GameObject::SetAppearanceStrategy(std::shared_ptr<IAppearanceStrategy> pAppearanceStrategy)
{
    m_pAppearanceStrategy.push_back(pAppearanceStrategy);
}
void GameObject::SetAppearance()
{
    for (auto& i : m_pAppearanceStrategy)
    {
        i->SetAppearance(&m_sprite);
    }
}

///////////////////////////////////////////
// Controls
///////////////////////////////////////////
void GameObject::SetControls(std::shared_ptr<IControls> controls)
{
    m_pControlType = controls;
}
void GameObject::Update(float dt)
{
    m_pControlType->Execute(m_sprite, dt);
}



///////////////////////////////////////////
// Draws Sprite to Window 
///////////////////////////////////////////
void GameObject::Draw()
{
    m_data->window.draw(m_sprite);
}


///////////////////////////////////////////
// Sound
///////////////////////////////////////////

void GameObject::SetSound(std::shared_ptr<ISoundStrategy> sound)
{
    m_pSoundStrategy.push_back(sound);
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