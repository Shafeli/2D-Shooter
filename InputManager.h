#pragma once
#include <SFML/Graphics.hpp>

/////////////////////////////////////////////////
//           InputManager
// TODO: documentation
/////////////////////////////////////////////////
class InputManager
{
public:

    bool IsSpriteClicked(sf::Sprite& object, sf::Mouse::Button button, sf::RenderWindow& window);
    sf::Vector2i GetMousePosition(sf::RenderWindow& window);

    bool APressed();
    bool DPressed();
    bool SpacePressed();

};

