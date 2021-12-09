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
private:
    std::map<std::string, sf::Texture> m_textures;
    std::map<std::string, sf::Font> m_fonts;
    std::map<std::string, sf::SoundBuffer> m_sounds;

public:

    void LoadTexture(std::string name, std::string fileName);
    sf::Texture& GetTexture(std::string name);

    void LoadFont(std::string name, std::string fileName);
    sf::Font& GetFont(std::string name);

    void LoadSound(std::string name, std::string fileName);
    sf::SoundBuffer& GetSound(std::string name);

};