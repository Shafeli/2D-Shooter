#pragma once

#include <memory>
#include <string>
#include <SFML/Graphics.hpp>
#include "AssetManager.h"
#include "DeltaTime.h"
#include "InputManager.h"
#include "MusicManager.h"
#include "ObjectCleaner.h"
#include "SizeManager.h"
#include "SpawnManager.h"
#include "StateMachine.h"
#include "UIDisplay.h"


/////////////////////////////////////////////////
//           GameManager & GameData
// TODO: documentation
/////////////////////////////////////////////////




struct GameData
{
    DeltaTime deltaTime;
    StateMachine machine;
    sf::RenderWindow window;
    AssetManager assets;
    InputManager input;
    ObjectCleaner grabage;
    SpawnManager Spawner;
    SizeManager Resizer;
    MusicManager jukebox;
    UIDisplay GameUI;
};


namespace GameEngine
{
    using RenderWindow = sf::RenderWindow;
    using GameDataRef = std::shared_ptr<GameData>;
    using Clock = sf::Clock;
    using Time = sf::Time;
    using Sprite = sf::Sprite;
    using Text = sf::Text;
    using Music = sf::Music;
    using Int32 = sf::Int32;
    using Int64 = sf::Int64;
    using String = sf::String;
    using Vector2i = sf::Vector2i;
    using Vector2f = sf::Vector2f;
    using Sound = sf::Sound;
    using Color = sf::Color;
    using Event = sf::Event;
}

class GameManager
{
    //double Time = 0.0;
    //const float DeltaTime = 0.01;
    //static constexpr float DeltaTime = 1.0f / 60.0f;
    GameEngine::Clock m_clock;
    GameEngine::GameDataRef m_data = std::make_shared<GameData>();
    float m_lastFrameTime = 0.f;

public:
    GameManager(int width, int height, std::string title);
    void Run();
};
