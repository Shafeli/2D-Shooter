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
    YAxiesAdfustment();
    SpawnReset();
    SpawnPositionSetter(toSpawn);
}

void AISpawnStrategy::SpawnReset()
{
    if (m_spawnCount >= 38)
        m_spawnCount -= 38;
    if (m_spawnCount >= 28)
        m_spawnCount -= 28;
    if (m_spawnCount >= 18)
        m_spawnCount -= 18;
    if (m_spawnCount >= 8)
        m_spawnCount -= 8;

    if (m_spawnCount == -1)
        m_spawnCount = 0;


    //switch(m_spawnCount)
    //{
    //case 8: m_spawnCount = 0; break;
    //case 18: m_spawnCount = 0; break;
    //case 28: m_spawnCount = 0; break;
    //case 38: m_spawnCount = 0; break;
    //}
}

void AISpawnStrategy::YAxiesAdfustment()
{
    if (m_spawnCount >= 8)
    {
        m_yAxis += 30.f;
    }
    if (m_spawnCount >= 18)
    {
        m_yAxis += 30.f;
    }
    if (m_spawnCount >= 28)
    {
        m_yAxis += 30.f;
    }
    if (m_spawnCount >= 38)
    {
        m_yAxis += 30.f;
    }
    if (m_spawnCount >= 48)
    {
        m_yAxis += 30.f;
    }
    if (m_spawnCount >= 58)
    {
        m_yAxis += 30.f;
    }
    if (m_spawnCount >= 68)
    {
        m_yAxis += 30.f;
    }
    if (m_spawnCount >= 78)
    {
        m_yAxis += 30.f;
    }
}

void AISpawnStrategy::SpawnPositionSetter(sf::Sprite* toSpawn)
{
    switch (m_spawnCount)
    {
    case 0:
        toSpawn->setPosition((m_data->window.getSize().x - 125) - (toSpawn->getGlobalBounds().width / 2), m_yAxis + (toSpawn->getGlobalBounds().height / 2));
        break;
    case 1:
        toSpawn->setPosition((m_data->window.getSize().x - 200) - (toSpawn->getGlobalBounds().width / 2), m_yAxis + (toSpawn->getGlobalBounds().height / 2));
        break;
    case 2:
        toSpawn->setPosition((m_data->window.getSize().x - 275) - (toSpawn->getGlobalBounds().width / 2), m_yAxis + (toSpawn->getGlobalBounds().height / 2));
        break;
    case 3:
        toSpawn->setPosition((m_data->window.getSize().x - 350) - (toSpawn->getGlobalBounds().width / 2), m_yAxis + (toSpawn->getGlobalBounds().height / 2));
        break;
    case 4:
        toSpawn->setPosition((m_data->window.getSize().x - 425) - (toSpawn->getGlobalBounds().width / 2), m_yAxis + (toSpawn->getGlobalBounds().height / 2));
        break;
    case 5:
        toSpawn->setPosition((m_data->window.getSize().x - 500) - (toSpawn->getGlobalBounds().width / 2), m_yAxis + (toSpawn->getGlobalBounds().height / 2));
        break;
    case 6:
        toSpawn->setPosition((m_data->window.getSize().x - 575) - (toSpawn->getGlobalBounds().width / 2), m_yAxis + (toSpawn->getGlobalBounds().height / 2));
        break;
    case 7:
        toSpawn->setPosition((m_data->window.getSize().x - 650) - (toSpawn->getGlobalBounds().width / 2), m_yAxis + (toSpawn->getGlobalBounds().height / 2));
        break;
    default:
        //i do not know why this happens fought with it for to long soooooo.....
        //now they are stacked yay player get extra points i guess #defeated!
        toSpawn->setPosition((m_data->window.getSize().x - 125) - (toSpawn->getGlobalBounds().width / 2), m_yAxis + (toSpawn->getGlobalBounds().height / 2));
        std::cout << "Failed loading " << m_spawnCount << '\n';
    }
}



