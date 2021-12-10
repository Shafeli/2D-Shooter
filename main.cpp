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
 //         Main & Gerneral Documentation
 // TODO: documentation
 /////////////////////////////////////////////////
/*
 
 
 
 */

 /////////////////////////////////////////////////////
 //              TODO:
 //- End Game if AI Touches Bottom of the screen
 //- Score System 
 //- Score UI
 //- High Score Leaderboards and saving system with User Choice Name
 //- End Game Screen UI
 //- Updated Collision System
 //- AI Manager class
 //- Updata AI spawning to make scaleable
 //- Enum system for loading and retrieving assets 
 /////////////////////////////////////////////////////

/////////////////////////////////////////////////////
//              Bug Report:
//- Player not getting hit until shoots first shot after that working normal
//- Bullets keep traveling after they "hit something"
//- Bullets need to be deleted if they are off the screen game starts to get
// overload and slow then crashes
//
/////////////////////////////////////////////////////

int main()
{
    srand(time(nullptr));

    GameManager spaceShooter(gScreenWidth, gScreenHeight, "Space Shooter");
    return 0;
}