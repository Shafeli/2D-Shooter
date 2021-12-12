#include "PlayerSpawnStrategy.h"

PlayerSpawnStrategy::PlayerSpawnStrategy(GameDataRef data)
    :m_data(data)
{
}

void PlayerSpawnStrategy::Spawn(sf::Sprite* toSpawn)
{
    toSpawn->setPosition((m_data->window.getSize().x / 2) - (toSpawn->getGlobalBounds().width / 2),
        m_data->window.getSize().y - toSpawn->getGlobalBounds().height);
}
