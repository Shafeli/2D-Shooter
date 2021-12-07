#include "GameObject.h"

GameObject::GameObject(GameDataRef data)
{
}

void GameObject::Update(float dt)
{
}

void GameObject::Draw()
{
}

void GameObject::AddTouchStrat(ITouchStrategy* pNewStepStrat)
{
}

void GameObject::OnTouch(GameObject* pActivator)
{
}

void GameObject::AddDeathStrat(IDeathStrategy* pNewStrat)
{
}

void GameObject::EndLife()
{
}

void GameObject::AddOnUseStrat(IOnUseStrategy* pNewStrat)
{
}

void GameObject::OnUse()
{
}

void GameObject::SetScoreStrat(IResourseStrategy* pNewStrat)
{
}

void GameObject::UpdateScore(int amount)
{
}
