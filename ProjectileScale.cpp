#include "ProjectileScale.h"

void ProjectileScale::Scale(sf::Sprite* toScale)
{
    toScale->setScale(sf::Vector2f(0.1f, 0.2f));
}
