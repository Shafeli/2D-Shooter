#include "AssetManager.h"

void AssetManager::LoadTexture(std::string name, std::string fileName)
{
    sf::Texture texture;

    if(texture.loadFromFile(fileName))
    {
        this->m_textures[name] = texture;
    }
}

sf::Texture& AssetManager::GetTexture(std::string name)
{
    return this->m_textures.at(name);
}

void AssetManager::LoadFont(std::string name, std::string fileName)
{
    sf::Font font;

    if (font.loadFromFile(fileName))
    {
        this->m_fonts[name] = font;
    }
}

sf::Font& AssetManager::GetFont(std::string name)
{
    return this->m_fonts.at(name);
}

void AssetManager::LoadSound(std::string name, std::string fileName)
{
    sf::SoundBuffer sound;
    
    if (sound.loadFromFile(fileName))
    {
        this->m_sounds[name] = sound;
    }
}

sf::SoundBuffer& AssetManager::GetSound(std::string name)
{
    return this->m_sounds.at(name);
}
