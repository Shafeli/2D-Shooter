#include "ObjectFactory.h"
#include "AISpawnStrategy.h"
#include "GameObject.h"
#include <memory>

#include "AIAppearanceStrategy.h"
#include "AIScale.h"
#include "AISoundStrategy.h"
#include "DeathAppearanceStrategy.h"
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
{
    //Spawn
    auto AI = std::make_shared<GameObject>(m_data);
    const std::shared_ptr<ISpawnStrategy> spawn = std::make_shared<AISpawnStrategy>(m_data, m_counter);

    //Controls
    const std::shared_ptr<IControls> controls = std::make_shared<AIControls>(m_data);

    //Scale
    const std::shared_ptr<IScaleStrategy> scale = std::make_shared<AIScale>();

    //Appearance
    const std::shared_ptr<IAppearanceStrategy> appearance = std::make_shared<AIAppearanceStrategy>(m_data);
    const std::shared_ptr<IAppearanceStrategy> appearanceTwo = std::make_shared<DeathAppearanceStrategy>(m_data);

    //Sounds
    const std::shared_ptr<ISoundStrategy> sound = std::make_shared<AISoundStrategy>(m_data);

    AI->SetSound(sound);
    AI->SetAppearanceStrategy(appearance);
    AI->SetAppearanceStrategy(appearanceTwo);
    AI->SetScale(scale);
    AI->SetSpawn(spawn);
    AI->SetControls(controls);

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

    //Controls
    const std::shared_ptr<IControls> controls = std::make_shared<PlayerControls>(m_data);

    //Scale
    const std::shared_ptr<IScaleStrategy> scale = std::make_shared<PlayerScale>();

    //Appearance
    const std::shared_ptr<IAppearanceStrategy> appearance = std::make_shared<PlayerAppearanceStrategy>(m_data);

    //Sounds
    const std::shared_ptr<ISoundStrategy> sound = std::make_shared<PlayerSoundStrategy>(m_data);

    player->SetSound(sound);
    player->SetAppearanceStrategy(appearance);
    player->SetScale(scale);
    player->SetControls(controls);
    player->SetSpawn(spawn);

    player->GameObjectInit();
    return player;
}

std::shared_ptr<GameObject> ObjectFactory::MakeProjectile(const sf::Vector2f& pos, float direction)
{
    //Spawn
    auto projectile = std::make_shared<GameObject>(m_data);
    const std::shared_ptr<ISpawnStrategy> spawn = std::make_shared<ProjectileSpawnStrategy>(pos);

    //Controls
    const std::shared_ptr<IControls> controls = std::make_shared<ProjectileControls>(m_data, direction);

    //Scale
    const std::shared_ptr<IScaleStrategy> scale = std::make_shared<ProjectileScale>();

    //Appearance
    const std::shared_ptr<IAppearanceStrategy> appearance = std::make_shared<ProjetileAppearanceStrategy>(m_data);

    //Sounds
    const std::shared_ptr<ISoundStrategy> sound = std::make_shared<ProjectileSoundStrategy>(m_data);

    projectile->SetSound(sound);
    projectile->SetAppearanceStrategy(appearance);
    projectile->SetScale(scale);
    projectile->SetControls(controls);
    projectile->SetSpawn(spawn);

    projectile->GameObjectInit();
    return projectile;
}

