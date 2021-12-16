#pragma once

#include <map>
#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>


/////////////////////////////////////////////////
//          AssetManger
// TODO: documentation
/////////////////////////////////////////////////


class AssetManager
{
public:
    enum class Font { kGame };
    enum class Texture { kPlayer, kBackground, kEnemy, kDeath, kLazer, kGameTitle, kStartButton };
    enum class Sound { kLazer, kEnemyDeath, kPlayerDeath, kReturnButton, kSplashScreenLoad, kButtonClick };

private:
    std::map<Texture, sf::Texture> m_textures;
    std::map<Font, sf::Font> m_fonts;
    std::map<Sound, sf::SoundBuffer> m_sounds;

public:

    //Loaders
    ////////////////////////////////////////////////////
    void Load(Texture name, std::string fileName);
    void Load(Font name, std::string fileName);
    void Load(Sound name, std::string fileName);

    //Retrievers
    ////////////////////////////////////////////////////
    sf::Texture& GetTexture(Texture name);
    sf::Font& GetFont(Font name);
    sf::SoundBuffer& GetSound(Sound name);

    //unloaders
    ////////////////////////////////////////////////////
    void Unload(Sound name);
    void Unload(Texture name);
    void Unload(Font name);

private:
 
    //Checkers
    /////////////////////////////////////////////////////
    bool IsLoaded(Font key);
    bool IsLoaded(Texture key);
    bool IsLoaded(Sound key);
};