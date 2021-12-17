#include "GameManager.h"
#include "Definition.h"
#include <ctime>

////////////////////////////////////////////////
//                 source:                    //
////////////////////////////////////////////////

/*
https://www.sfml-dev.org/tutorials/2.5/start-vc.php - SFML & Visual Studio 
https://www.youtube.com/watch?v=YfMQyOw1zik - How to set up SFML 2.5.1 VS2019
https://en.sfml-dev.org/forums/index.php?topic=24904.0 - LNK1104 Error help
https://en.sfml-dev.org/forums/ - SFML forums I live here now
https://www.youtube.com/watch?v=C06eGdy7C6k&list=PL6xSOsbVA1eb_QqMTTcql_3PdOiE928up&index=3 - creating a game window
https://www.youtube.com/watch?v=kxb0GvBNOGU - SFML Game engine class
https://en.sfml-dev.org/forums/index.php?topic=16607.0 - SFML Resource Manager Documentation of SFML 2.5.1
https://www.sfml-dev.org/documentation/2.5.1/classsf_1_1RenderTexture.php - RenderTexture Documentation of SFML 2.5.1
https://www.sfml-dev.org/tutorials/2.5/window-inputs.php - Keyboard, mouse and joystick Documentation of SFML 2.5.1
https://www.sfml-dev.org/tutorials/2.5/audio-sounds.php - Playing sounds and music Documentation of SFML 2.5.1
 */

 /////////////////////////////////////////////////
 //         Gerneral Documentation              //
 //                                             //
 /////////////////////////////////////////////////
/*

 State machine runs the flow of the game / app
 
 a single struck holds the managers for various tasks
 
     -Asset Manager - > takes in a "FilePath" and a Key for the Asset overloads to Load are different key enum types - for data maps
     -CollisionDection Manager - > Checks if two Objects have touched and if they did -> Calls Objects MarkForDeath function - or if touching window top/ bottom/ left/ right
     -File Manager - deals with all things files reads in the config then store data in various maps and are accessed thruogh enum keys
     -Input Manager - abstracts sf::Key out of game code so replace SFML is a little easyer
     -Music Manager - plays music and loads music for the game currently does more with files then i would like 
     -Object Cleaner - loops over vectors pass into it and if MarkedForDeath performs remove_if calls on them and resizes the vecotr
     -Size Manager - takes in object and resizes their sprites
     -Spawn Manager - takes in object and adjusts thier poition
     
 Eveything in game is a GameObject
 UI Class is only responsable for drawing UI to the screen - Though arguments can be made that it also controls player live count and score
 Delta TIme class - Still bouncing the Idea of making it a singlton or now holda (Master Delta time) that is caulculated in GameManager where a tertiary copy of delta time can be if desired
 Definision holds g_Globals are currently only thing that needs to stay there is Screen Width / Screen Hieght that is only becuz File Manager is not a sigleton yet
 */

 /////////////////////////////////////////////////////
 //              TODO:
 //- finish file seting up file manager -> needs refactor
 //- High score saving system / leaderboard
 //- File Manager needs checks like Asset Manager has 
 //- The rate of AI Growth is to much cap it and Maybe slow growth
 //- move file stuff out of music manager
 //- 
 //-  
 //- 
 //- 
 //-  
 //- 
 //- Hit / step behavior
 //- refactor the mess in AI Controller
 //- Power-Ups -Faster rate of fire -glitter bomb for the lol's
 //-
 /////////////////////////////////////////////////////

/////////////////////////////////////////////////////
//              Bug Report:
//- moving from EndGameState -> MainMenu -> Game crashes // temp fix close window after game is over // feels bad -- "But time being a factor"
//- 
//-
//-
//-
/////////////////////////////////////////////////////

int main()
{
    //only used for musicd
    srand(time(nullptr));

    GameManager spaceShooter(gScreenWidth, gScreenHeight, "Space Shooter");
    spaceShooter.Run();
    return 0;
}