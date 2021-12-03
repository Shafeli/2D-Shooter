#pragma once


class IResourseStrategy
{
public:
    virtual ~IResourseStrategy();

    virtual void ModAmount(int changeAmount) = 0;
    virtual int GetAmount() = 0;

};