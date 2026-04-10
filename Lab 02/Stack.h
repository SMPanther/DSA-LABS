#pragma once

template <class T>
class Stack
{
protected:
    int currentIndex;
    T* values;
    int maxCapacity;

public:

    Stack(int _maxCapacity = 0)
    {
        currentIndex = -1;
        maxCapacity = _maxCapacity;
        values = new T[maxCapacity];
    }

    Stack(const Stack& AA)
    {
        maxCapacity = AA.maxCapacity;
        currentIndex = AA.currentIndex;

        values = new T[maxCapacity];

        for (int i = 0; i <= currentIndex; i++)
            values[i] = AA.values[i];
    }

    virtual void push(const T& v) = 0;
    virtual bool pop(T& value) = 0;

    bool isEmpty()
    {
        return (currentIndex < 0);
    }

    bool isFull()
    {
        return (currentIndex == maxCapacity - 1);
    }

};