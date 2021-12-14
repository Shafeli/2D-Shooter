#pragma once

#include <memory>
#include <string>
#include <SFML/Graphics.hpp>
#include "AssetManager.h"
#include "State.h"
#include "InputManager.h"
#include "MusicManager.h"
#include "ObjectCleaner.h"
#include "SizeManager.h"
#include "SpawnManager.h"
#include "StateMachine.h"


/////////////////////////////////////////////////
//           GameManager & GameData
// TODO: documentation
/////////////////////////////////////////////////




struct GameData
{
    StateMachine machine;
    sf::RenderWindow window;
    AssetManager assets;
    InputManager input;
    ObjectCleaner grabage;
    SpawnManager Spawner;
    SizeManager Resizer;
    MusicManager jukebox;
};


namespace GameEngine
{

    using GameDataRef = std::shared_ptr<GameData>;
    using Clock = sf::Clock;
    using Sprite = sf::Sprite;
    using Text = sf::Text;
    using Music = sf::Music;
    using Int32 = sf::Int32;
    using Int64 = sf::Int64;
    using String = sf::String;
    using Vector2i = sf::Vector2i;

}

class GameManager
{
    //double Time = 0.0;
    //const float DeltaTime = 0.01;
    const float DeltaTime = 1.0f / 60.0f;
    sf::Clock m_clock;
    GameEngine::GameDataRef m_data = std::make_shared<GameData>();

public:
    GameManager(int width, int height, std::string title);


private:

    void Run();
};
