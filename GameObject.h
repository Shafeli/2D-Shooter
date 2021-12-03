#pragma once
#include <vector>
#include <SFML/Graphics/Sprite.hpp>

#include "GameManager.h"

class IControls;
class ITouchStrategy;
class IResourseStrategy;
class IOnUseStrategy;
class IDeathStrategy;

class GameObject
{
    GameDataRef m_data;
    sf::Sprite m_sprite;
    sf::Clock m_rateOfFire;

    //TODO move to  Definition.h
    float m_movementSpeed = 5.f;

    std::vector<ITouchStrategy*> m_touchStrat;
    std::vector<IOnUseStrategy*> m_basicStrat;
    std::vector<IDeathStrategy*> m_deathStrat;
    IResourseStrategy* m_pScore;
    IControls* m_pControlType;

public:
    GameObject(GameDataRef data);

    void Update(float dt);
    void Draw();

    void AddTouchStrat(ITouchStrategy* pNewStepStrat);

    void OnTouch(GameObject* pActivator);

    void AddDeathStrat(IDeathStrategy* pNewStrat);
    void EndLife();

    void AddOnUseStrat(IOnUseStrategy* pNewStrat);
    void OnUse();

    void SetScoreStrat(IResourseStrategy* pNewStrat);
    void UpdateScore(int amount);
     
};
