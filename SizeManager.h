#pragma once
#include <SFML/System/Vector2.hpp>

class GameObject;

class SizeManager
{
    sf::Vector2f m_normalSize{ 0.2f, 0.2f };
    sf::Vector2f m_rectangleSize{ 0.1f, 0.2f };
public:
    void normalScale(GameObject* toScale);
    void RectangleScale(GameObject* toScale);
};

