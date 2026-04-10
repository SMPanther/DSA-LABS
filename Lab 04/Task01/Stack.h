#pragma once

class Stack
{
protected:
    int currentIndex;
    int* values;
    int maxCapacity;

public:

    Stack(int _maxCapacity = 0)
    {
        currentIndex = -1;
        maxCapacity = _maxCapacity;
        values = new int[maxCapacity];
    }

    Stack(const Stack& AA)
    {
        maxCapacity = AA.maxCapacity;
        currentIndex = AA.currentIndex;

        values = new int[maxCapacity];

        for (int i = 0; i <= currentIndex; i++)
            values[i] = AA.values[i];
    }

    virtual void push(const int& v) = 0;
    virtual bool pop(int& value) = 0;

    bool isEmpty()
    {
        return (currentIndex < 0);
    }

    bool isFull()
    {
        return (currentIndex == maxCapacity - 1);
    }

};