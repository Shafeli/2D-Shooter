#pragma once
#include "GameManager.h"
#include "State.h"

class MainMenuState : public State
{
	//Ref to Game data local
    GameEngine::GameDataRef m_data;

	//sprites
	sf::Sprite m_background;
	sf::Sprite m_title;
	sf::Sprite m_playButton;
	sf::Sound m_MenuSound;

	//Sounds
    ////////////////////////////////////////////////
	sf::Music m_menuMusic;
	////////////////////////////////////////////////

public:
	//c'tor takes in reference to Game Data struct
	MainMenuState(GameEngine::GameDataRef data);
	~MainMenuState();


	virtual void Init()override final;
	virtual void HandleInput()override final;
	virtual void Update(float dt)override final;
	virtual void Draw()override final;
};

