#pragma once

// TODO: documentation
/////////////////////////////////////////////////
//           Definition
// place for constexpr & globals
// single place for file paths for quick and easy changing out files for anything in project
// format will be Macros for file names
// constexpr for global values
// globals should have g followed by name  
//
/////////////////////////////////////////////////


//TODO Change to constexpr 
/////////////////////////////////
//size of window 
#define SCREEN_WIDTH 768
#define SCREEN_HEIGHT 1024
/////////////////////////////////

/////////////////////////////////
//Splash screen 
#define SPLASH_STATE_SHOW_TIME 3.0
#define SPLASH_SCENE_BACKGROUND_FILEPATH "Resources/res/Space.jpg"
/////////////////////////////////

/////////////////////////////////
//Main menu background
#define MAIN_MENU_BACKGROUND_FILEPATH "Resources/res/Space.jpg"
//Game Title 
#define GAME_TITLE_FILEPATH "Resources/res/title1.png"
//Play Button
#define PLAY_BUTTON_FILEPATH "Resources/res/StartButton.png"
/////////////////////////////////

/////////////////////////////////
//Game Background 
#define Game_BACKGROUND_FILEPATH "Resources/res/Space.jpg"
/////////////////////////////////

/////////////////////////////////
//Game Over Screen
#define Game_OVER_FILEPATH "Resources/res/Space.jpg"
/////////////////////////////////



/////////////////////////////////
//Player
#define PLAYER_SPRITE "Resources/res/Player.png"
constexpr float gPlayerSpeed = 7.f;
constexpr float gRateOfFire = 1.f / 4;
/////////////////////////////////

/////////////////////////////////
//Bullet
#define BULLET_SPRITE "Resources/res/Bullet.png"
constexpr float gBulletYAxisAmount = 30.f;
/////////////////////////////////

//////////////////////////////////
//AI 
#define TARGET_SPRITE "Resources/res/Target.png"
constexpr float gTargetSpeed = 10.f;
constexpr float gTargetYAxisDecreaseAmount = 30.f;
//////////////////////////////////

// TODO: animation system - save for later quite a lot of work in this
///////////////////////////////////////
//  TODO: prototype animation manager
// 
//#define  ANIMATION_DURATION 0.4f;
///////////////////////////////////////