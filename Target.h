#pragma once
#include "GameManager.h"
#include  <SFML/Graphics.hpp>

class Target
{
    GameDataRef m_data;
    sf::Sprite m_sprite;
    float m_movementSpeed = 5.f;
    bool m_left = false;
  
public:
    Target(GameDataRef data);

    void Draw();

    void Update(float dt);
};

