#pragma once


class GameObject;

class ITouchStrategy
{
public:
    virtual ~ITouchStrategy() = default;
    virtual void Execute(GameObject* pTarget) = 0;
};
