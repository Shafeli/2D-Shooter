#include "ObjectFactory.h"
#include "GameObject.h"
#include <memory>

#include "AIAppearanceStrategy.h"
#include "AIControls.h"
#include "AISoundStrategy.h"
#include "DeathAppearanceStrategy.h"
#include "IControls.h"
#include "IAppearanceStrategy.h"
#include "PlayerAppearanceStrategy.h"
#include "PlayerControls.h"
#include "PlayerSoundStrategy.h"
#include "ProjectileControls.h"
#include "ProjectileSoundStrategy.h"

ObjectFactory::ObjectFactory(GameEngine::GameDataRef data)
    :m_data(data)
{
}

GameObject* ObjectFactory::MakeAI(int spawnCounter)
{
    //Spawn
    const auto AI = new GameObject(m_data);
    m_data->Spawner.AISpawnPosition(AI, &m_data->window, spawnCounter);

    //Controls
    const std::shared_ptr<IControls> controls = std::make_shared<AIControls>(m_data);

    //Scale
    m_data->Resizer.TieSize(AI);

    //Appearance
    const std::shared_ptr<IAppearanceStrategy> appearance = std::make_shared<AIAppearanceStrategy>(m_data);
    const std::shared_ptr<IAppearanceStrategy> appearanceTwo = std::make_shared<DeathAppearanceStrategy>(m_data);

    //Sounds
    const std::shared_ptr<ISoundStrategy> sound = std::make_shared<AISoundStrategy>(m_data);

    AI->SetSound(sound);
    AI->SetAppearanceStrategy(appearance);
    AI->SetAppearanceStrategy(appearanceTwo);
    AI->SetControls(controls);
    AI->GameObjectInit();
    return AI;
}

GameObject* ObjectFactory::MakePlayer()
{
    const auto player = new GameObject(m_data);

    //Controls
    const std::shared_ptr<IControls> controls = std::make_shared<PlayerControls>(m_data);

    //Scale
    m_data->Resizer.normalScale(player);

    //Appearance
    const std::shared_ptr<IAppearanceStrategy> appearance = std::make_shared<PlayerAppearanceStrategy>(m_data);

    //Sounds
    const std::shared_ptr<ISoundStrategy> sound = std::make_shared<PlayerSoundStrategy>(m_data);

    player->SetSound(sound);
    player->SetAppearanceStrategy(appearance);
    player->SetControls(controls);
    player->GameObjectInit();
    //Spawn TODO: look in to why only player needs to set spawn after init?
    m_data->Spawner.PlayerSpawn(player, &m_data->window);
    return player;
}

GameObject* ObjectFactory::MakeProjectile(const sf::Vector2f& pos, float direction, ProjetileAppearanceStrategy::ProjectileColor color)
{
    //Spawn
    auto projectile = new GameObject(m_data);
    m_data->Spawner.ProjectileSpawn(pos, projectile);

    //Controls
    const std::shared_ptr<IControls> controls = std::make_shared<ProjectileControls>(m_data, direction);

    //Scale
    m_data->Resizer.RectangleScale(projectile);

    //Appearance
    const std::shared_ptr<IAppearanceStrategy> appearance = std::make_shared<ProjetileAppearanceStrategy>(m_data, color);

    //Sounds
    const std::shared_ptr<ISoundStrategy> sound = std::make_shared<ProjectileSoundStrategy>(m_data);

    projectile->SetSound(sound);
    projectile->SetAppearanceStrategy(appearance);
    projectile->SetControls(controls);
    projectile->GameObjectInit();
    return projectile;
}

