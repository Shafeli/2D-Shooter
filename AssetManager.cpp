#include "AssetManager.h"

#include <iostream>

void AssetManager::Load(Texture name, std::string fileName)
{
    sf::Texture texture;
    if (!IsLoaded(name))
    {
        if (texture.loadFromFile(fileName))
        {
            this->m_textures[name] = texture;
        }
    }
}

sf::Texture& AssetManager::GetTexture(Texture name)
{
    return this->m_textures.at(name);
}

void AssetManager::Load(Font name, std::string fileName)
{
    sf::Font font;
    if (!IsLoaded(name))
    {
        if (font.loadFromFile(fileName))
        {
            this->m_fonts[name] = font;
        }
    }
}

sf::Font& AssetManager::GetFont(Font name)
{
    return this->m_fonts.at(name);
}

void AssetManager::Load(Sound name, std::string fileName)
{
    sf::SoundBuffer sound;
    if (!IsLoaded(name))
    {
        if (sound.loadFromFile(fileName))
        {
            this->m_sounds[name] = sound;
        }
    }
}

sf::SoundBuffer& AssetManager::GetSound(Sound name)
{
    return this->m_sounds.at(name);
}

void AssetManager::Unload(Sound name)
{
    m_sounds.erase(name);
}

void AssetManager::Unload(Font name)
{
    m_fonts.erase(name);
}

void AssetManager::Unload(Texture name)
{
    m_textures.erase(name);
}

bool AssetManager::IsLoaded(Font key)
{
    for (auto const& i : m_fonts)
    {
        if (i.first == key)
        {
            std::cout << "Font File Failed" << " " << static_cast<int>(key) << "\n";
            return true;
        }
    }
    return false;
}

bool AssetManager::IsLoaded(Texture key)
{
    for (auto const& i : m_textures)
    {
        if (i.first == key)
        {
            std::cout << "Texture File Failed" << " " << static_cast<int>(key) << "\n";
            return true;
        }
    }
    return false;
}

bool AssetManager::IsLoaded(Sound key)
{
    for (auto const& i : m_sounds)
    {
        if (i.first == key)
        {
            std::cout << "Sound File Failed" << " " << static_cast<int>(key) << "\n";
            return true;
        }
    }
    return false;
}
