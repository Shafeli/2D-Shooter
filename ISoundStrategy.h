#pragma once

class ISoundStrategy
{
public:
    virtual ~ISoundStrategy() = default;
    virtual void MakeSound() = 0;
};
