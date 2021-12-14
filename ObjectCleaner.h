#pragma once
#include <memory>
#include <vector>
#include <SFML/Graphics/RenderWindow.hpp>
#include <SFML/Graphics/Sprite.hpp>
class GameObject;

class ObjectCleaner
{
    using ObjectVector = std::vector<GameObject*>;
    using Object = GameObject;
public:
    enum class Type {kPlayerBullet, kEnemyBullet, kEnemy};

    void Cleaner(ObjectVector& list, sf::RenderWindow* window, Type type) const;
    void MarkedObjectCleaner(ObjectVector& list, sf::RenderWindow* window, Type type)const;
    void Sweeper(Object* object, sf::RenderWindow& window, Type type)const;
    void Sweeper(sf::Sprite* sprite, sf::RenderWindow& window, Type type)const;
};

