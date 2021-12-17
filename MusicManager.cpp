#include "MusicManager.h"

void MusicManager::initMusic()
{
    m_music.setVolume(m_masterSound);
    int random = rand() % 3;

    //pic random for track to be played
    if (m_musicTimer.getElapsedTime().asSeconds() > 153)
    {
        switch (random)
        {
        case 0: TrackOne(); m_music.play(); m_musicTimer.restart(); break;
        case 1: TrackTwo(); m_music.play(); m_musicTimer.restart(); break;
        case 2: TrackThree(); m_music.play(); m_musicTimer.restart(); break;
        }
    }
    //pic random for track to be played
    if(m_onSwitch == false)
    {
        switch (random)
        {
        case 0: TrackOne(); m_music.play(); m_musicTimer.restart(); m_onSwitch = true; break;
        case 1: TrackTwo(); m_music.play(); m_musicTimer.restart(); m_onSwitch = true; break;
        case 2: TrackThree(); m_music.play(); m_musicTimer.restart(); m_onSwitch = true; break;
        }
        m_onSwitch = true;
    }
}

void MusicManager::CheckMusic()
{
    int random = rand() % 3;
    //pic random for track to be played if time is > then 153 seconds
    if (m_musicTimer.getElapsedTime().asSeconds() > 153)
    {
        switch(random)
        {
        case 0: TrackOne(); m_music.play(); m_musicTimer.restart(); break;
        case 1: TrackTwo(); m_music.play(); m_musicTimer.restart(); break;
        case 2: TrackThree(); m_music.play(); m_musicTimer.restart(); break;
        }
        TrackTwo();
        m_music.play();
        m_musicTimer.restart();
    }
}

//songs to be played
void MusicManager::TrackOne()
{
    m_music.openFromFile("Resources/res/ThePowerOfTheDarkSide.wav");
}

void MusicManager::TrackTwo()
{
    m_music.openFromFile("Resources/res/TheForce.wav");
}

void MusicManager::TrackThree()
{
    m_music.openFromFile("Resources/res/ImperialMarch.wav");
}
