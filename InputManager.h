#pragma once
#include <SFML/Graphics.hpp>

/////////////////////////////////////////////////
//TODO: add more inputs controls / general inputs esc for closing the window
/////////////////////////////////////////////////

/////////////////////////////////////////////////
//           InputManager
// TODO: documentation
/////////////////////////////////////////////////
class InputManager
{
public:

    bool IsSpriteClicked(sf::Sprite& object, sf::Mouse::Button button, sf::RenderWindow& window);
    sf::Vector2i GetMousePosition(sf::RenderWindow& window);

    bool AIsPressed();
    bool DIsPressed();
    bool SpaceIsPressed();

};

