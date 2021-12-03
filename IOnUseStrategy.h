#pragma once


class IOnUseStrategy
{
public:
    virtual ~IOnUseStrategy() = default;
    virtual void Execute() = 0;
};