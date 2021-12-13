#pragma once
#include <SFML/Graphics/Sprite.hpp>
#include <SFML/System/Clock.hpp>

#include "GameManager.h"


class IControls
{
public:
    virtual ~IControls() = default;
    virtual void Execute(sf::Sprite& m_sprite, float dt) = 0;
    virtual bool FireShot() = 0;
    virtual bool MoveDown() { return false; }
};

///////////////////////////////////
//Movement Controls for a Player
///////////////////////////////////
class PlayerControls : public IControls
{
    GameDataRef m_data;
    sf::Clock m_rateOfFire;
    bool m_fireShot = false;
   
public:
    PlayerControls(GameDataRef data);
    virtual void Execute(sf::Sprite& m_sprite, float dt) override final;
    virtual bool FireShot() override final;
};

/////////////////////////////////////
//Movement Controls for a AI Enemy
/////////////////////////////////////
class AIControls : public IControls
{
    GameDataRef m_data;
    sf::Clock m_rateOfFire;
    bool m_movementSwitch = false;
    bool m_fireShot = false;
    static inline sf::Clock m_moveTimer;
   static inline bool s_moveSwitch = false;
   static inline bool s_moveDown = false;
public:
    AIControls(GameDataRef data);
   virtual void Execute(sf::Sprite& m_sprite, float dt) override final;
   virtual bool FireShot()override final;
   virtual bool MoveDown()override final;
};

//////////////////////////////////////
//Movement Controls for a Projectile
/////////////////////////////////////
class ProjectileControls : public IControls
{
    GameDataRef m_data;
    float m_direction;
public:
    ProjectileControls(GameDataRef data, float direction);
    virtual void Execute(sf::Sprite& m_sprite, float dt) override final;
    virtual bool FireShot()override final;
};