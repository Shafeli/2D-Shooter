#pragma once
#include "GameManager.h"

class Bullet : std::enable_shared_from_this<Bullet>
{
    GameDataRef m_data;
    sf::Sprite m_sprite;
    sf::Sound m_fireSound;
    float m_direction;
public:
    Bullet(GameDataRef data,const sf::Vector2f&, float Direction);

    void Draw();
    void Lazer();

    void Update(float dt);

    const sf::Vector2f& GetPOS();

    const sf::Sprite& GetSprite();
};

