#pragma once


class IControls
{
public:
    virtual ~IControls() = default;
    virtual void Execute() = 0;
};
