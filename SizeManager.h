#pragma once
#include <SFML/System/Vector2.hpp>

class GameObject;

class SizeManager
{
    sf::Vector2f m_playerSize{ 0.07f, 0.07f };
    sf::Vector2f m_lazerSize{ 0.1f, 0.2f };
    sf::Vector2f m_tieSize{ 0.08f, 0.05f };
public:
    void normalScale(GameObject* toScale);
    void RectangleScale(GameObject* toScale);
    void TieSize(GameObject* toScale);
};

