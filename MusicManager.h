#pragma once
#include <SFML/Audio/Music.hpp>
#include <SFML/System/Clock.hpp>

class MusicManager
{
    int m_masterSound = 5;
    sf::Music m_music;
    sf::Clock m_musicTimer;
    bool m_onSwitch = false;

public:
    void initMusic();
    void SetMasterVolume(int amount) { m_masterSound = amount; }
    int GetMasterVolume() const { return m_masterSound; }
    void CheckMusic();
private:

    void TrackOne();
    void TrackTwo();
    void TrackThree();
};

