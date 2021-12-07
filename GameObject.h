#pragma once
#include <vector>
#include <SFML/Graphics/Sprite.hpp>

#include "Definition.h"
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

    //TODO get this working for pacing player fire rate
    sf::Clock m_rateOfFire;

    float m_movementSpeed = gPlayerSpeed;

    std::vector<ITouchStrategy*> m_pTouchStrat;
    std::vector<IOnUseStrategy*> m_pOnUseStrat;
    std::vector<IDeathStrategy*> m_pDeathStrat;
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
