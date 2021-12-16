#pragma once
#include <fstream>
#include <map>
#include <vector>

class FileManager
{
public:

    enum class FileData {

        //front
        kGameFont, //0

        //texture
        kPlayerTexture, //1
        kBackgroundTexture, //2
        kEnemyTexture, //3
        kDeathTexture, //4
        kLazerTexture, //5
        kGameTitleTexture, //6 
        kStartButtonTexture, //7
         
        //sounds
        kLazerSound, //8
        kEnemyDeathSound, //9
        kPlayerDeathSound, //10
        kReturnButtonSound, //11
        kSplashScreenLoadSound, //12
        kButtonClickSound, //13

        //ints
        kScreenHight, //14
        kScreenWidth, //15
        kAIRandomFireDistro, //16
        kBulletSoundLevel, //17
        kMasterSoundLevel, //18

        //floats
        kSplashShowTime, //19

        //player
        kPlayerSpeed, //20
        kPlayerRateOfFire, //21
        kPlayerProjectileSpeed, //22

        //AI
        kAISpeed, //23
        kAIRateOfFire, //24
        kAIProjectileSpeed, //25
        kAIDecressTimer, //26

        //HighScore
        kHighScore, //27

        //size of list
        kSize
    };

private:


    static constexpr auto kGameConfigFile = "Resources/GameData/Config.txt";
    static constexpr auto kGameHighScoreFile = "Resources/GameData/HighScore.txt";
 

    std::map<FileData, std::string> m_AssetFiles;
    std::map<FileData, int> m_FileConfigInts;
    std::map<FileData, float> m_FileConfigFloats;

///////////////////////////////
/// File Manager stores constexpers to files
///
/// enum for the data you want is passed in to Load function
/// Load function parses the file top to bottom then looks up thru the enum in the map the file
/// was loaded to and gets the data for the enum
/// 
///////////////////////////////



public:
    FileManager();

    void SaveHighScore(int data);
    std::string GetFilePath(FileData name);


private:
    
    //void IntLoader(int& enumkey, std::ifstream* file);
    //void FloatLoader(int& enumkey, std::ifstream* file);
    //void FilePathLoader(int& enumkey, std::ifstream* file);
    void Load();


};
