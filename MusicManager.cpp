#include "MusicManager.h"

void MusicManager::initMusic()
{
    int random = rand() % 3;

    if (m_musicTimer.getElapsedTime().asSeconds() > 234)
    {
        switch (random)
        {
        case 0: TrackOne(); m_music.play(); m_musicTimer.restart(); break;
        case 1: TrackTwo(); m_music.play(); m_musicTimer.restart(); break;
        case 2: TrackThree(); m_music.play(); m_musicTimer.restart(); break;
        }
    }
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

    if (m_musicTimer.getElapsedTime().asSeconds() > 234)
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

void MusicManager::TrackOne()
{
    m_music.openFromFile("Resources/res/MainMenuMusic.wav");
}

void MusicManager::TrackTwo()
{
    m_music.openFromFile("Resources/res/GameStateMusic.wav");
}

void MusicManager::TrackThree()
{
    m_music.openFromFile("Resources/res/EndGameMusic.wav");
}
