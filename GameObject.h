#pragma once
#include <vector>
#include "GameManager.h"

class ISoundStrategy;
class IAppearanceStrategy;
class IScaleStrategy;
class ISpawnStrategy;
class IControls;

class GameObject : std::enable_shared_from_this<GameObject>
{
    GameDataRef m_data;
    sf::Sprite m_sprite;
    sf::Clock m_rateOfFire;
    sf::Clock m_DeathTimer;

    std::shared_ptr<IControls> m_pControlType;
    std::vector<std::shared_ptr<ISpawnStrategy>> m_pSpawnStrategy;
    std::vector<std::shared_ptr<IScaleStrategy>> m_pSacleStrategy;
    std::vector<std::shared_ptr<IAppearanceStrategy>> m_pAppearanceStrategy;
    std::vector<std::shared_ptr<ISoundStrategy>> m_pSoundStrategy;

    bool m_isAlive = true;
public:

    ///////////////////////////////////////////
    // Create Object
    ///////////////////////////////////////////
    GameObject(GameDataRef data);
    void GameObjectInit();

    ///////////////////////////////////////////
    // Spawn Startegy
    ///////////////////////////////////////////
    void SetSpawn(std::shared_ptr<ISpawnStrategy>);
    void Spawn();

    ///////////////////////////////////////////
    // Scale Startegy
    ///////////////////////////////////////////
    void SetScale(std::shared_ptr<IScaleStrategy>pSacleStrategy);
    void Scale();

    //////////////////////////////////////////////////////
    ///////////////////////////////////////////
    // Appearance Startegy
    ///////////////////////////////////////////
    void SetAppearanceStrategy(std::shared_ptr<IAppearanceStrategy>pAppearanceStrategy);
    void SetStartAppearance();
    void SetDeathAppearance();
    ///////////////////////////////////////////
    // Draws Sprite to Window 
    ///////////////////////////////////////////
    void Draw();
    //////////////////////////////////////////////////////

    /////////////////////////////////////////////////////
    ///////////////////////////////////////////
    // Control
    /////////////////////////////////////////////////
    void SetControls(std::shared_ptr<IControls> controls);
    void Update(float dt);
    ///////////////////////////////////////////
    // returns if pControl has used action button
    ///////////////////////////////////////////
    bool OnUse();
    /////////////////////////////////////////////////////

    ///////////////////////////////////////////
    // Sound
    ///////////////////////////////////////////
    void SetSound(std::shared_ptr<ISoundStrategy> sound);
    void MakeSound();


    ///////////////////////////////////////////
    // Current Hit dectection 
    ///////////////////////////////////////////
    const sf::Vector2f& GetPOS();
    const sf::Sprite& GetSprite();
    void MarkedForDeath();
    bool IsDead() const
    {
        bool isdead = false;

        if (m_isAlive == false)
            return isdead == true;

        return isdead;
    }
    sf::Clock GetTimer() { return m_DeathTimer; }
};
