#pragma once
#include "GameManager.h"
#include  <SFML/Graphics.hpp>
//#include "Definition.h"

class Target : std::enable_shared_from_this<Target>
{
    GameDataRef m_data;
    sf::Sprite m_sprite;
    sf::Clock m_rateOfFire;
    sf::Sound m_DeathSound;
    bool m_movementSwitch = false;
    bool m_fireShot = false;

public:
    Target(GameDataRef data, size_t targetNum );
    ~Target();
    void Draw();
    void DeathSound();
    void Update(float dt);

    const sf::Vector2f& GetPOS();

    const sf::Sprite& GetSprite();

    bool FireShot();


};

