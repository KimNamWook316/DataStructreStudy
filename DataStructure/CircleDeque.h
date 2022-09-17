#pragma once

#include "CircleQueue.h"

class CCircleDeque :
    public CCircleQueue
{
public:
    CCircleDeque();

public:
    void AddFront(int data);
    int DeleteFront();
    int GetFront();
    void AddRear(int data);
    int DeleteRear();
    int GetRear();
    virtual void Print() override;
};

