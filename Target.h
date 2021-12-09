#pragma once
#include "GameManager.h"
#include  <SFML/Graphics.hpp>
//#include "Definition.h"

class Target
{
    GameDataRef m_data;
    sf::Sprite m_sprite;
    sf::Clock m_rateOfFire;

    bool m_movementSwitch = false;
    bool m_fireShot = false;

public:
    Target(GameDataRef data, size_t targetNum );

    void Draw();

    void Update(float dt);

    const sf::Vector2f& GetPOS();

    const sf::Sprite& GetSprite();

    bool FireShot();
};

