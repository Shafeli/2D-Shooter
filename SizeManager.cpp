#include "SizeManager.h"
#include "GameObject.h"

void SizeManager::normalScale(GameObject* toScale)
{
    toScale->GetSprite().setScale(m_normalSize);
}

void SizeManager::RectangleScale(GameObject* toScale)
{
    toScale->GetSprite().setScale(m_rectangleSize);
}
