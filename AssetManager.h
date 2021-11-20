#pragma once

#include <map>
#include <SFML/Graphics.hpp>


/////////////////////////////////////////////////
//          AssetManger
// TODO: documentation
/////////////////////////////////////////////////


class AssetManager
{
private:
    std::map<std::string, sf::Texture> m_textures;
    std::map<std::string, sf::Font> m_fonts;

public:

    void LoadTexture(std::string name, std::string fileName);
    sf::Texture& GetTexture(std::string name);

    void LoadFont(std::string name, std::string fileName);
    sf::Font& GetFont(std::string name);

};