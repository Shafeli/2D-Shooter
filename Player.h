#pragma once

#include  <SFML/Graphics.hpp>
#include "Definition.h"
#include "GameManager.h"


class Player
{
    GameDataRef m_data;
    sf::Sprite m_sprite;
    sf::Clock m_rateOfFire;
    float m_movementSpeed = 5.f;
    bool m_fireShot = false;

public:
    Player(GameDataRef data);

    void Draw();

    void Update(float dt);

    bool FireShot();

    const sf::Vector2f& GetPOS();
};
