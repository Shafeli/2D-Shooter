#include "SpawnManager.h"

#include <iostream>
#include "GameObject.h"

void SpawnManager::PlayerSpawn(GameObject* toSpawn, const sf::RenderWindow* window)
{
    toSpawn->GetSprite().setPosition((window->getSize().x / static_cast<float>(2)) - (toSpawn->GetSprite().getGlobalBounds().width / 2),
        window->getSize().y - toSpawn->GetSprite().getGlobalBounds().height);
}

int SpawnManager::SpawnReset(int spawnCounter)
{
    int counter = spawnCounter;
    if (spawnCounter % 8 == 0)
    {
        return 0;
    }
    if (spawnCounter < 8)
    {
        counter = spawnCounter;
        return counter;
    }
    if (spawnCounter == 10)
        return 2;
    if (spawnCounter > 10)

        if (spawnCounter == 8)
            counter = 0;
        if (spawnCounter == 9)
            counter = 1;

    std::cout << spawnCounter << " : counter was " << counter << '\n';
        return counter;
}

void SpawnManager::YAxiesAdjustment(int spawnCounter)
{

    //if spawnCounter % 8 then reset to 0
    //if spawnCounter is > 8 then
    // spawnCounter - 8 / 10 * 30 = yAxis
    //if spawnCounter < yAxis = 30
    if (spawnCounter < 8)
    {
        return;
    }
    if (spawnCounter % 8 == 0)
    {
        m_yAxis += 30.f;
    }
}

void SpawnManager::AISpawnPosition(GameObject* toSpawn, sf::RenderWindow* window, int spawnCounter)
{

    if (spawnCounter %  8 == 0)
        m_ticker = 0;

    YAxiesAdjustment(spawnCounter);
    int checkint = spawnCounter;
    switch (SpawnReset(m_ticker))
    {
    case 0:
        toSpawn->GetSprite().setPosition((window->getSize().x - 125) - (toSpawn->GetSprite().getGlobalBounds().width / 2), m_yAxis +(toSpawn->GetSprite().getGlobalBounds().height / 2));
        break;
    case 1:
        toSpawn->GetSprite().setPosition((window->getSize().x - 200) - (toSpawn->GetSprite().getGlobalBounds().width / 2), m_yAxis + (toSpawn->GetSprite().getGlobalBounds().height / 2));
        break;                                  
    case 2:                                     
        toSpawn->GetSprite().setPosition((window->getSize().x - 275) - (toSpawn->GetSprite().getGlobalBounds().width / 2), m_yAxis + (toSpawn->GetSprite().getGlobalBounds().height / 2));
        break;                                  
    case 3:                                     
        toSpawn->GetSprite().setPosition((window->getSize().x - 350) - (toSpawn->GetSprite().getGlobalBounds().width / 2), m_yAxis + (toSpawn->GetSprite().getGlobalBounds().height / 2));
        break;                                  
    case 4:                                     
        toSpawn->GetSprite().setPosition((window->getSize().x - 425) - (toSpawn->GetSprite().getGlobalBounds().width / 2), m_yAxis + (toSpawn->GetSprite().getGlobalBounds().height / 2));
        break;                                  
    case 5:                                     
        toSpawn->GetSprite().setPosition((window->getSize().x - 500) - (toSpawn->GetSprite().getGlobalBounds().width / 2), m_yAxis + (toSpawn->GetSprite().getGlobalBounds().height / 2));
        break;                                  
    case 6:                                     
        toSpawn->GetSprite().setPosition((window->getSize().x - 575) - (toSpawn->GetSprite().getGlobalBounds().width / 2), m_yAxis + (toSpawn->GetSprite().getGlobalBounds().height / 2));
        break;                                 
    case 7:                                     
        toSpawn->GetSprite().setPosition((window->getSize().x - 650) - (toSpawn->GetSprite().getGlobalBounds().width / 2), m_yAxis + (toSpawn->GetSprite().getGlobalBounds().height / 2));
        break;
    default:
        std::cout << "Failed loading " << checkint << '\n';
        toSpawn->MarkedForDeath();
    }

    ++m_ticker;
}

void SpawnManager::ProjectileSpawn(const sf::Vector2f& pos, GameObject* newObject)
{
    newObject->GetSprite().setPosition(pos);
}
