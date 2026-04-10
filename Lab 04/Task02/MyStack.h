#pragma once
#include "Stack.h"

class MyStack : public Stack
{
public:

    MyStack(int c = 0) : Stack(c) {}

    MyStack(const MyStack& ma) : Stack(ma) {}

    void push(const int& v)
    {
        if (!this->isFull())
        {
            this->values[++this->currentIndex] = v;
        }
    }

    bool pop(int& v)
    {
        if (!this->isEmpty())
        {
            v = this->values[this->currentIndex--];
            return true;
        }

        return false;
    }
};