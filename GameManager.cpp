#include "GameManager.h"

//#include <iostream>

#include "SplashState.h"

GameManager::GameManager(int width, int height, std::string title)
{
    m_data->window.create(sf::VideoMode(width, height), title, sf::Style::Close | sf::Style::Titlebar);
    m_data->machine.AddState(std::make_unique<SplashState>(this->m_data));
    this->Run();
}

void GameManager::Run()
{
    float currentTime = this->m_clock.getElapsedTime().asSeconds();
    float accumulator = 0.0f;


    while (this->m_data->window.isOpen())
    {
        
        this->m_data->machine.ProcessStateChanges();

        float newTime = this->m_clock.getElapsedTime().asSeconds();
        float frameTime = newTime - currentTime;

        if(frameTime > 0.25f)
        {
            frameTime = 0.25f;

        }

        currentTime = newTime;
        accumulator += frameTime;

        while (accumulator>= DeltaTime)
        {
            accumulator -= DeltaTime;
            this->m_data->machine.GetActiveState()->HandleInput();
            this->m_data->machine.GetActiveState()->Update(DeltaTime);

            
        }

        const float interpolation = accumulator / DeltaTime;
        this->m_data->machine.GetActiveState()->Draw();
    }
}


//void GameManager::Run()
//{
//    double CurrentTime;
//    double Accumulator;
//    double NewTime = m_clock.getElapsedTime().asSeconds();
//    double FrameTime = NewTime - CurrentTime;
//    CurrentTime = NewTime;
//    
//    Accumulator += FrameTime;
//    
//    while (Accumulator >= DeltaTime)
//    {
//        // Game Loop
//           this->m_data->machine.GetActiveState()->HandleInput();
//           this->m_data->machine.GetActiveState()->Update(DeltaTime);
//    
//        // AI
//        // Physics
//    
//        Accumulator -= DeltaTime;
//        Time += DeltaTime;
//    }
//    
//    // Render Graphics
//    this->m_data->machine.GetActiveState()->Draw();
//    
//    // FPS - Shows in Console Window
//    std::cout << "FPS: " << 1.0f / FrameTime << std::endl;
//}
