#include "AISpawnStrategy.h"

#include <iostream>

AISpawnStrategy::AISpawnStrategy(GameDataRef data, int spawnCount)
    :m_data(data)
    ,m_spawnCount(spawnCount)
{
}

//TODO : improve spawning logic AI
void AISpawnStrategy::Spawn(sf::Sprite* toSpawn)
{

    switch (m_spawnCount)
    {
    case 0:
        toSpawn->setPosition((m_data->window.getSize().x - 725) - (toSpawn->getGlobalBounds().width / 2), 0 + (toSpawn->getGlobalBounds().height / 2));
        break;
    case 1:
        toSpawn->setPosition((m_data->window.getSize().x - 650) - (toSpawn->getGlobalBounds().width / 2), 0 + (toSpawn->getGlobalBounds().height / 2));
        break;
    case 2:
        toSpawn->setPosition((m_data->window.getSize().x - 50) - (toSpawn->getGlobalBounds().width / 2), 0 + (toSpawn->getGlobalBounds().height / 2));
        break;
    case 3:
        toSpawn->setPosition((m_data->window.getSize().x - 125) - (toSpawn->getGlobalBounds().width / 2), 0 + (toSpawn->getGlobalBounds().height / 2));
        break;
    case 4:
        toSpawn->setPosition((m_data->window.getSize().x - 200) - (toSpawn->getGlobalBounds().width / 2), 0 + (toSpawn->getGlobalBounds().height / 2));
        break;
    case 5:
        toSpawn->setPosition((m_data->window.getSize().x - 275) - (toSpawn->getGlobalBounds().width / 2), 0 + (toSpawn->getGlobalBounds().height / 2));
        break;
    case 6:
        toSpawn->setPosition((m_data->window.getSize().x - 350) - (toSpawn->getGlobalBounds().width / 2), 0 + (toSpawn->getGlobalBounds().height / 2));
        break;
    case 7:
        toSpawn->setPosition((m_data->window.getSize().x - 425) - (toSpawn->getGlobalBounds().width / 2), 0 + (toSpawn->getGlobalBounds().height / 2));
        break;
    case 8:
        toSpawn->setPosition((m_data->window.getSize().x - 500) - (toSpawn->getGlobalBounds().width / 2), 0 + (toSpawn->getGlobalBounds().height / 2));
        break;
    case 9:
        toSpawn->setPosition((m_data->window.getSize().x - 575) - (toSpawn->getGlobalBounds().width / 2), 0 + (toSpawn->getGlobalBounds().height / 2));
        break;
    default: std::cout << "Failed AI Spawn\n";
    }
}


