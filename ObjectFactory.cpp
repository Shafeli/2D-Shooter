#include "ObjectFactory.h"
#include "AISpawnStrategy.h"
#include "GameObject.h"
#include <memory>

#include "AIAppearanceStrategy.h"
#include "AIScale.h"
#include "AISoundStrategy.h"
#include "IControls.h"
#include "IScaleStrategy.h"
#include "PlayerSpawnStrategy.h"
#include "IAppearanceStrategy.h"
#include "PlayerAppearanceStrategy.h"
#include "PlayerScale.h"
#include "PlayerSoundStrategy.h"
#include "ProjectileScale.h"
#include "ProjectileSoundStrategy.h"
#include "ProjectileSpawnStrategy.h"
#include "ProjetileAppearanceStrategy.h"


ObjectFactory::ObjectFactory(GameDataRef data)
    :m_data(data)
    ,m_counter(0)
{
}

void ObjectFactory::CounterReseter()
{
    if (m_counter == 10)
    {
        m_counter = 0;
    }
}

std::shared_ptr<GameObject> ObjectFactory::MakeAI()
{   //Spawn
    auto AI = std::make_shared<GameObject>(m_data);
    const std::shared_ptr<ISpawnStrategy> Strat = std::make_shared<AISpawnStrategy>(m_data, m_counter);
    const auto SpawnStrat = std::dynamic_pointer_cast<ISpawnStrategy>(Strat);

    //Controls
    const std::shared_ptr<IControls> controls = std::make_shared<AIControls>(m_data);
    const auto controlsStrat = std::dynamic_pointer_cast<IControls>(controls);
   
  
    //Scale
    const std::shared_ptr<IScaleStrategy> scale = std::make_shared<AIScale>();
    const auto scaleStrat = std::dynamic_pointer_cast<AIScale>(scale);

    //Appearance
    const std::shared_ptr<IAppearanceStrategy> appearance = std::make_shared<AIAppearanceStrategy>(m_data);
    const auto appearanceStrat = std::dynamic_pointer_cast<AIAppearanceStrategy>(appearance);

    //Sounds
    const std::shared_ptr<ISoundStrategy> sound = std::make_shared<AISoundStrategy>(m_data);
    const auto soundStrat = std::dynamic_pointer_cast<AISoundStrategy>(sound);

    AI->SetSound(soundStrat);
    AI->SetAppearanceStrategy(appearance);
    AI->SetScale(scaleStrat);
    AI->SetSpawn(SpawnStrat);
    AI->SetControls(controlsStrat);

    AI->GameObjectInit();

    ++m_counter;
    CounterReseter();
    return AI;
}

std::shared_ptr<GameObject>ObjectFactory::MakePlayer()
{
    //Spawn
    auto player = std::make_shared<GameObject>(m_data);
    const std::shared_ptr<ISpawnStrategy> spawn = std::make_shared<PlayerSpawnStrategy>(m_data);
    const auto SpawnStrat = std::dynamic_pointer_cast<PlayerSpawnStrategy>(spawn);

    //Controls
    const std::shared_ptr<IControls> controls = std::make_shared<PlayerControls>(m_data);
    const auto controlsStrat = std::dynamic_pointer_cast<PlayerControls>(controls);


    //Scale
    const std::shared_ptr<IScaleStrategy> scale = std::make_shared<PlayerScale>();
    const auto scaleStrat = std::dynamic_pointer_cast<IScaleStrategy>(scale);

    //Appearance
    const std::shared_ptr<IAppearanceStrategy> appearance = std::make_shared<PlayerAppearanceStrategy>(m_data);
    const auto appearanceStrat = std::dynamic_pointer_cast<PlayerAppearanceStrategy>(appearance);

    //Sounds
    const std::shared_ptr<ISoundStrategy> sound = std::make_shared<PlayerSoundStrategy>(m_data);
    const auto soundStrat = std::dynamic_pointer_cast<PlayerSoundStrategy>(sound);

    player->SetSound(soundStrat);
    player->SetAppearanceStrategy(appearanceStrat);
    player->SetScale(scaleStrat);
    player->SetControls(controlsStrat);
    player->SetSpawn(SpawnStrat);
    player->GameObjectInit();
    return player;
}

std::shared_ptr<GameObject> ObjectFactory::MakeProjectile(const sf::Vector2f& pos, float direction)
{
    //Spawn
    auto projectile = std::make_shared<GameObject>(m_data);
    const std::shared_ptr<ISpawnStrategy> spawn = std::make_shared<ProjectileSpawnStrategy>(pos);
    const auto SpawnStrat = std::dynamic_pointer_cast<ProjectileSpawnStrategy>(spawn);

    //Controls
    const std::shared_ptr<IControls> controls = std::make_shared<ProjectileControls>(m_data, direction);
    const auto controlsStrat = std::dynamic_pointer_cast<ProjectileControls>(controls);


    //Scale
    const std::shared_ptr<IScaleStrategy> scale = std::make_shared<ProjectileScale>();
    const auto scaleStrat = std::dynamic_pointer_cast<ProjectileScale>(scale);

    //Appearance
    const std::shared_ptr<IAppearanceStrategy> appearance = std::make_shared<ProjetileAppearanceStrategy>(m_data);
    const auto appearanceStrat = std::dynamic_pointer_cast<ProjetileAppearanceStrategy>(appearance);


    //Sounds
    const std::shared_ptr<ISoundStrategy> sound = std::make_shared<ProjectileSoundStrategy>(m_data);
    const auto soundStrat = std::dynamic_pointer_cast<ProjectileSoundStrategy>(sound);

    projectile->SetSound(soundStrat);
    projectile->SetAppearanceStrategy(appearanceStrat);
    projectile->SetScale(scaleStrat);
    projectile->SetControls(controlsStrat);
    projectile->SetSpawn(SpawnStrat);

    projectile->GameObjectInit();
    return projectile;
}

