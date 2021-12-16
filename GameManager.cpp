#include "GameManager.h"

//#include <iostream>

#include "SplashState.h"

GameManager::GameManager(int width, int height, std::string title)
{
    m_data->window.create(sf::VideoMode(width, height), title, sf::Style::Close | sf::Style::Titlebar);
    m_data->machine.AddState(std::make_unique<SplashState>(this->m_data));
   // this->Run();
}

void GameManager::Run()
{
    float currentTime = this->m_clock.getElapsedTime().asSeconds();
    float accumulator = 0.0f;

    while (this->m_data->window.isOpen())
    {
        this->m_data->machine.ProcessStateChanges();

        const float time = m_clock.getElapsedTime().asSeconds();
        const float frameTime = time - currentTime;
        currentTime = time;
        accumulator += frameTime;

        m_data->deltaTime.SetTime(time - m_lastFrameTime);
        m_lastFrameTime = time;

        while (accumulator >= m_data->deltaTime.GetSeconds())
        {
            accumulator -= m_data->deltaTime.GetSeconds();
            this->m_data->machine.GetActiveState()->HandleInput();
            this->m_data->machine.GetActiveState()->Update(m_data->deltaTime.GetSeconds());
        }
        this->m_data->machine.GetActiveState()->Draw();
    }
}


//delta tiem is the time between the last frame
// so to move n amount of units for x amount of time * by the time between frames
