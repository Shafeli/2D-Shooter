#pragma once
#include "GameManager.h"
#include  <SFML/Graphics.hpp>

class Target
{
    GameDataRef m_data;
    sf::Sprite m_sprite;

  
public:
    Target(GameDataRef data);

    void Draw();

    void Update(float dt);
};

