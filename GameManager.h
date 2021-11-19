#pragma once

#include <memory>
#include <string>
#include <SFML/Graphics.hpp>
#include "AssetManager.h"
#include "State.h"
#include "InputManager.h"
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

};

using GameDataRef = std::shared_ptr<GameData>;



class GameManager
{
    const float DeltaTime = 1.0f / 60.0f;
    sf::Clock m_clock;

public:
    GameManager(int width, int height, std::string title);


private:
    GameDataRef m_data = std::make_shared<GameData>();

    void Run();
};

