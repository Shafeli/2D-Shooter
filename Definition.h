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

constexpr int gScreenHeight = 1024;
constexpr int gScreenWidth = 768;

/////////////////////////////////
//size of window 

constexpr auto gGameFontFile = "Resources/fonts/ARCADE.TTF";
/////////////////////////////////

/////////////////////////////////
//Splash screen 

constexpr auto gSplahBackgroundFile = "Resources/res/Space.jpg";
constexpr auto gSplashSoundFile = "Resources/res/SplashScreen.wav";
/////////////////////////////////

/////////////////////////////////
//Main menu background
constexpr auto gMainMenuBackgroundFile = "Resources/res/Space.jpg";
//Game Title 
constexpr auto gGameTitleFile = "Resources/res/title1.png";
//Play Button
constexpr auto gPlayButtonFile = "Resources/res/StartButton.png";
constexpr auto gClickSoundFile = "Resources/res/MenuSound.ogg";
constexpr auto gVaderSoundFile = "Resources/res/YouShouldNot.wav";
constexpr auto gTrapSoundFile = "Resources/res/Trap.wav";
/////////////////////////////////

/////////////////////////////////
//Game Background 
constexpr auto gGameBackgroundFile = "Resources/res/DeathStar.jpg";
/////////////////////////////////

/////////////////////////////////
//Game Over Screen
constexpr auto gGameOverFile = "Resources/res/Space.jpg";
/////////////////////////////////


/////////////////////////////////
//Player
constexpr auto gPlayerSpriteFile = "Resources/res/Player.png";
constexpr auto gPlayerSoundFile = "Resources/res/PlayerDeath.wav";

/////////////////////////////////
//1.f / 4;
constexpr auto gDeathSpriteFile = "Resources/res/Death.png";
constexpr auto gTargetSpriteFile = "Resources/res/Target.png";
constexpr auto gDeathSoundFile = "Resources/res/Boom.wav";
constexpr auto gMultiKillSoundFile = "Resources/res/QuakeKill.wav";
constexpr auto gBulletSpriteFile = "Resources/res/Bullet.png";
constexpr auto gBulletSoundFile = "Resources/res/Lazer.wav";




//constexpr int gScreenHeight = 1024;//-
//constexpr int gScreenWidth = 768;//-
//
//constexpr int gAIRandomFire = 78; //-
//constexpr int gBulletSoundLevel = 5; //-
////             masterSoundLevel   10   //-
//
//
//
//constexpr float gSplashShowTime = 2.5f; //-
//
//constexpr float gPlayerSpeed = 360.f;//-
//constexpr float gRateOfFire = .25f;//-
//constexpr float gPlayerBulletYAxisAmount = 660.f; //-
//
//constexpr float gTargetSpeed = 100.f;//-
//constexpr float gAIRateOfFireInSeconds = .6f; //-
//constexpr float gAIBulletYAxisAmount = 500.f;//-
//constexpr float gTargetYAxisDecreaseAmount = .05f; //-
