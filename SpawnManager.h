#pragma once
#include <SFML/Graphics/RenderWindow.hpp>
class GameObject;

class SpawnManager
{
    int m_ticker = 0;
    float m_yAxis = 50.f;
public:
    void PlayerSpawn(GameObject* toSpawn, const sf::RenderWindow* window);
    void AISpawnPosition(GameObject* toSpawn, sf::RenderWindow* window, int spawnCounter);
    void ProjectileSpawn(const sf::Vector2f& pos, GameObject* spawner);
    void AISpawnLocationReset() { m_yAxis = 50.f; m_ticker = 0; }

private:
    int SpawnReset(int spawnCounter);
    void YAxiesAdjustment(int spawnCounter);
};

