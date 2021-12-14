#pragma once
#include <vector>
#include "GameManager.h"

class ISoundStrategy;
class IAppearanceStrategy;
class IControls;

class GameObject : std::enable_shared_from_this<GameObject>
{
    GameEngine::GameDataRef m_data;
    sf::Sprite m_sprite;
    sf::Clock m_rateOfFire;
    sf::Clock m_DeathTimer;

    std::shared_ptr<IControls> m_pControlType;
    std::vector<std::shared_ptr<IAppearanceStrategy>> m_pAppearanceStrategy;
    std::vector<std::shared_ptr<ISoundStrategy>> m_pSoundStrategy;

    bool m_isAlive = true;
public:

    ///////////////////////////////////////////
    // Create Object
    ///////////////////////////////////////////
    GameObject(GameEngine::GameDataRef data);
    void GameObjectInit();

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
    bool TargetMoveFlag();
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
    sf::Sprite& GetSprite();
    void MarkedForDeath();
    bool isAlive() const { return m_isAlive; }
 
};
