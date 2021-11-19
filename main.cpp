#include <iostream>
#include "GameManager.h"
#include "SplashState.h"
#include "Definition.h"

////////////////////////////////////////////////
//                 source:                    //
////////////////////////////////////////////////

/*
https://www.sfml-dev.org/tutorials/2.5/start-vc.php - SFML & Visual Studio 
https://www.youtube.com/watch?v=YfMQyOw1zik - How to set up SFML 2.5.1 VS2019
https://en.sfml-dev.org/forums/index.php?topic=24904.0 - LNK1104 Error help
https://en.sfml-dev.org/forums/ - SFML forums Basiclly live here now
https://www.youtube.com/watch?v=C06eGdy7C6k&list=PL6xSOsbVA1eb_QqMTTcql_3PdOiE928up&index=3 - creating a game window
https://www.youtube.com/watch?v=kxb0GvBNOGU - SFML Game engine class
https://en.sfml-dev.org/forums/index.php?topic=16607.0 - SFML Resource Manager Documentation of SFML 2.5.1
https://www.sfml-dev.org/documentation/2.5.1/classsf_1_1RenderTexture.php - RenderTexture Documentation of SFML 2.5.1
https://www.sfml-dev.org/tutorials/2.5/window-inputs.php - Keyboard, mouse and joystick Documentation of SFML 2.5.1
https://www.sfml-dev.org/tutorials/2.5/audio-sounds.php - Playing sounds and music Documentation of SFML 2.5.1
 
 */


int main()
{

    GameManager spaceShooter(SCREEN_WIDTH, SCREEN_HEIGHT, "Space Shooter");

    return 0;
}