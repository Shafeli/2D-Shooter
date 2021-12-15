#include "SizeManager.h"
#include "GameObject.h"

void SizeManager::normalScale(GameObject* toScale)
{
    toScale->GetSprite().setScale(m_playerSize);
}

void SizeManager::RectangleScale(GameObject* toScale)
{
    toScale->GetSprite().setScale(m_lazerSize);
}

void SizeManager::TieSize(GameObject* toScale)
{
    toScale->GetSprite().setScale(m_tieSize);
}
