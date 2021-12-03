#include "GameManager.h"
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
            this->m_data->machine.GetActiveState()->HandleInput();
            this->m_data->machine.GetActiveState()->Update(DeltaTime);

            accumulator -= DeltaTime;
        }

        const float interpolation = accumulator / DeltaTime;
        this->m_data->machine.GetActiveState()->Draw(interpolation);
    }
}
