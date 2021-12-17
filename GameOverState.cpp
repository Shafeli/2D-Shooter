#include "GameOverState.h"
#include <iostream>
#include "Definition.h"
#include "MainMenuState.h"


GameOverState::GameOverState(GameEngine::GameDataRef data)
	: m_data(data)
{

}

GameOverState::~GameOverState()
{
	m_data->assets.Unload(AssetManager::Texture::kStartButton);
	m_data->assets.Unload(AssetManager::Sound::kReturnButton);
	m_data->assets.Unload(AssetManager::Font::kGame);
}

// loads texture to asset manager
void GameOverState::Init()
{
	m_data->GameUI.InitGameUI(&m_data->window, m_data->assets.GetFont(AssetManager::Font::kGame), UIDisplay::UI::kEndGameUI);
	m_data->GameUI.SetEndGameUIUp(m_data->FilingCabinet.GetConfigInt(FileManager::FileData::kHighScore));
	m_data->FilingCabinet.StreamOut();
	m_data->assets.Load(AssetManager::Texture::kStartButton, m_data->FilingCabinet.GetFilePath(FileManager::FileData::kStartButtonTexture));
	m_data->assets.Load(AssetManager::Sound::kReturnButton, m_data->FilingCabinet.GetFilePath(FileManager::FileData::kReturnButtonSound));

	m_MenuSound.setBuffer(m_data->assets.GetSound(AssetManager::Sound::kReturnButton));
	m_background.setTexture(this->m_data->assets.GetTexture(AssetManager::Texture::kBackground));
	m_button.setTexture(this->m_data->assets.GetTexture(AssetManager::Texture::kStartButton));
	m_button.setScale(GameEngine::Vector2f(0.2f, 0.2f));
	m_button.setPosition((m_data->FilingCabinet.GetConfigInt(FileManager::FileData::kScreenWidth) / 2) - (m_button.getGlobalBounds().width / 2), (m_data->FilingCabinet.GetConfigInt(FileManager::FileData::kScreenHight) / 2) - (m_button.getGlobalBounds().height / 2));
	m_MenuSound.setVolume(25);
	m_data->jukebox.CheckMusic();
}


void GameOverState::HandleInput()
{
	sf::Event event;

	while (this->m_data->window.pollEvent(event))
	{
		if (GameEngine::Event::Closed == event.type)
		{
			this->m_data->window.close();
		}
	}
}

#pragma warning(disable : 4100)
void GameOverState::Update(float dt)
#pragma warning(default : 4100)
{
	m_data->jukebox.CheckMusic();
	if (this->m_clock.getElapsedTime().asSeconds() > 234)
	{
		m_data->machine.AddState(std::make_unique<MainMenuState>(m_data), true);
	}


	if (m_data->input.IsSpriteClicked(m_button, sf::Mouse::Left, m_data->window))
	{

		//plays click sound 
		m_MenuSound.play();
		//wait time for sound to go off boot leg but it works 
		GameEngine::Time time = sf::seconds(2.1f);
		sleep(time);
		//after sleep move state
		this->m_data->window.close();
	}
}

//renders state 
void GameOverState::Draw()
{

	this->m_data->window.clear(GameEngine::Color::Red);
	this->m_data->window.draw(this->m_background);
	this->m_data->window.draw(this->m_button);
	m_data->GameUI.Draw(&m_data->window, UIDisplay::UI::kEndGameUI);
	this->m_data->window.display();
}