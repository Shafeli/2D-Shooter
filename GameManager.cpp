#include "GameManager.h"
#include "SplashState.h"

GameManager::GameManager(int width, int height, std::string title)
{
    m_data->window.create(sf::VideoMode(width, height), title, sf::Style::Close | sf::Style::Titlebar);
    m_data->machine.AddState(std::make_unique<SplashState>(this->m_data));
}

//delta time is the time between the last frame
// so to move n amount of units for x amount of time * by the time between frames
void GameManager::Run()
{
    //sets last frame time
    m_lastFrameTime = this->m_clock.getElapsedTime().asSeconds();
    //while window is open ->
    while (this->m_data->window.isOpen())
    {
        //Process State Changes
        this->m_data->machine.ProcessStateChanges();
        //New Time
        const float time = m_clock.getElapsedTime().asSeconds();
        //New Time - Last Frame Time
        m_data->deltaTime.SetTime(time - m_lastFrameTime);
        //Last Frame Time = New Frame Time 
        m_lastFrameTime = time;
        //Inputs
        this->m_data->machine.GetActiveState()->HandleInput();
        //Update Calls -> Takes in Master Delta Time 
        this->m_data->machine.GetActiveState()->Update(m_data->deltaTime.GetSeconds());
        //Draw Calls
        this->m_data->machine.GetActiveState()->Draw();
    }
}

