#pragma once
#include <fstream>
#include <map>
#include <vector>

class FileManager
{
public:
    enum class FileData {
        //front
        kGameFont = 3000, //3000
        //texture
        kPlayerTexture, //3001
        kBackgroundTexture, //3002
        kEnemyTexture, //3003
        kDeathTexture, //3004
        kLazerTexture, //3005
        kGameTitleTexture, //3006 
        kStartButtonTexture, //3007
        //sounds
        kLazerSound, //3008
        kEnemyDeathSound, //3009
        kPlayerDeathSound, //3010
        kReturnButtonSound, //3011
        kSplashScreenLoadSound, //3012
        kButtonClickSound, //3013
        //ints
        kScreenHight, //3014
        kScreenWidth, //3015
        kAIRandomFireDistro, //3016
        kBulletSoundLevel, //3017
        kMasterSoundLevel, //3018
        //floats
        kSplashShowTime, //3019
        //player
        kPlayerSpeed, //3020
        kPlayerRateOfFire, //3021
        kPlayerProjectileSpeed, //3022
        //AI
        kAISpeed, //3023
        kAIRateOfFire, //3024
        kAIProjectileSpeed, //3025
        kAIDecressTimer, //3026
        //HighScore
        kHighScore, //3027
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
/// enum for the data you want is passed in to Get function
/// Load function parses the file top to bottom then fills the hash up
/// first number is cast to enum as the key the enum in the map the file
/// was loaded to and gets the data for the enum
/// 
///////////////////////////////
public:
    FileManager();
    void SaveHighScore(int data);
    std::string GetFilePath(FileData name);
    float GetConfigFloat(FileData name);
    int GetConfigInt(FileData name);

private:
    void Load();
    bool IsLoaded(FileData key);
};
