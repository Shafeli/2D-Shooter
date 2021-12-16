#pragma once
#include "GameManager.h"

class IControls
{
public:
    virtual ~IControls() = default;
    virtual void Execute(GameObject* object, float dt) = 0;
    virtual bool FireShot() = 0;
};
