#pragma once
#include "GameManager.h"

class Bullet
{
    GameDataRef m_data;
    sf::Sprite m_sprite;

    bool m_movementSwitch = false;

public:
    Bullet(GameDataRef data,const sf::Vector2f&);

    void Draw();

    void Update(float dt);

    const sf::Vector2f& GetPOS();

    const sf::Sprite& GetSprite();
};

