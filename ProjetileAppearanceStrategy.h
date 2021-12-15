#pragma once
#include "GameManager.h"
#include "IAppearanceStrategy.h"
class ProjetileAppearanceStrategy : public IAppearanceStrategy
{
public:
    enum class ProjectileColor { kPlayer, kEmey };
private:
    GameEngine::GameDataRef m_data;
    GameEngine::Sprite* m_sprite;
    ProjectileColor m_color;
public:
    ProjetileAppearanceStrategy(GameEngine::GameDataRef data, ProjectileColor color);
    void SetAppearance(GameEngine::Sprite* toChange) override;

};

