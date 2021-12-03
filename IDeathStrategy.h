#pragma once



class IDeathStrategy
{
public:
    virtual ~IDeathStrategy() = default;
    virtual void Execute() = 0;
};