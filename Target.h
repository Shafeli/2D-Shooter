#pragma once
#include "GameManager.h"
#include  <SFML/Graphics.hpp>
//#include "Definition.h"

class Target
{
    GameDataRef m_data;
    sf::Sprite m_sprite;
    
    bool m_movementSwitch = false;
  
public:
    Target(GameDataRef data);

    void Draw();

    void Update(float dt);
};

