#include "ProjectileSoundStrategy.h"

#include "Definition.h"

ProjectileSoundStrategy::ProjectileSoundStrategy(GameEngine::GameDataRef data)
    :m_data(data)
{
    m_sound.setBuffer(m_data->assets.GetSound(AssetManager::Sound::kLazer));
    m_sound.setVolume(m_data->FilingCabinet.GetConfigInt(FileManager::FileData::kMasterSoundLevel));
}

void ProjectileSoundStrategy::MakeSound()
{
    m_sound.play();
}
