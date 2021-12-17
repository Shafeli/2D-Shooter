#include "SizeManager.h"
#include "GameObject.h"

//takes in an object and scales thier sprite
void SizeManager::normalScale(GameObject* toScale)
{
    toScale->GetSprite().setScale(m_playerSize);
}
//takes in an object and scales thier sprite
void SizeManager::RectangleScale(GameObject* toScale)
{
    toScale->GetSprite().setScale(m_lazerSize);
}
//takes in an object and scales thier sprite
void SizeManager::TieSize(GameObject* toScale)
{
    toScale->GetSprite().setScale(m_tieSize);
}
