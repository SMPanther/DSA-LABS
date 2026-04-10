#pragma once
#include "Queue.h"

class MyQueue : public Queue
{
public:
    MyQueue(int s) : Queue(s)
    {
        values = new int[maxCapacity];
    }

    MyQueue(const MyQueue& mq) : Queue(mq)
    {
        values = new int[maxCapacity];
        for (int i = 0; i < count; i++)
        {
            values[i] = mq.values[i];
        }
    }

    ~MyQueue()
    {
        delete[] values;
    }

    void enqueue(const int& value)
    {
        if (isFull())
        {
            cout << "Queue is full\n";
            return;
        }

        if (isEmpty())
        {
            startOfQIndex = 0;
        }

        values[++topOfQIndex] = value;
        count++;
    }

    int dequeue()
    {
        if (isEmpty())
        {
            cout << "Queue is empty\n";
            return -1;
        }

        int value = values[startOfQIndex];
        startOfQIndex++;
        count--;

        // reset when empty
        if (count == 0)
        {
            startOfQIndex = -1;
            topOfQIndex = -1;
        }

        return value;
    }

    void display(ostream& out) const
    {
        if (isEmpty())
        {
            out << "Queue is empty\n";
            return;
        }

        for (int i = startOfQIndex; i <= topOfQIndex; i++)
        {
            out << values[i] << " ";
        }
        out << endl;
    }

protected:
    int* values;
};