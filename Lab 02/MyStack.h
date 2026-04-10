#pragma once
#include "Stack.h"

template <class T>
class MyStack : public Stack<T>
{
public:

    MyStack(int c = 0) : Stack<T>(c) {}

    MyStack(const MyStack& ma) : Stack<T>(ma) {}

    void push(const T& v)
    {
        if (!this->isFull())
        {
            this->values[++this->currentIndex] = v;
        }
    }

    bool pop(T& v)
    {
        if (!this->isEmpty())
        {
            v = this->values[this->currentIndex--];
            return true;
        }

        return false;
    }
};