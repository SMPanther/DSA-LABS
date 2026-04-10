#include <iostream>
using namespace std;

#include "Stack.h"
#include "MyStack.h"
#include "Queue.h"
#include "MyQueue.h"

/*
1) Understanding of Task:

Accordding to what i understand to pperform diffrent operations on queue
we can only queue and stack(if needed) to implement the globle function
------------------------------------------------------------

2) Approach / Solution:

we will use temporaray quese so the orignal values arnt lost

Example
Original: A -> B ->C
Remove A -> print -> temp me store
Remove B -> print -> temp me store
Remove C -> print -> temp me store

then we will move all the values from temp to all the nessicary queues and the orignial queue
Final:
A → B → C →

------------------------------------------------------------

3) Functions reuse:

getSize(),display(),append() are ost likly to be reused the most


------------------------------------------------------------

4) Learning:
i learned the directional flow of the queue how to correctly retrive and put data and how to correctly minipulate
the data if the queue to our desired outcome

------------------------------------------------------------
5) Skills Developed:

use of queue and how to manipulate data in queue
Logic building
how to solve difrent problem while using queue

*/


// same as task#1
void display(Queue* q, ostream& out)
{
    Queue* temp = new MyQueue(100);

    while (!q->isEmpty())
    {
        int v = q->dequeue();
        out << v << " ";
        temp->enqueue(v);
    }

    while (!temp->isEmpty())
        q->enqueue(temp->dequeue());

    out << endl;
    delete temp;
}

// same as task#1
int getSize(Queue* q)
{
    int size = 0;
    Queue* temp = new MyQueue(100);

    while (!q->isEmpty())
    {
        int v = q->dequeue();
        temp->enqueue(v);
        size++;
    }

    while (!temp->isEmpty())
        q->enqueue(temp->dequeue());

    delete temp;
    return size;
}

// same as task#1
void append(Queue* src, Queue* dst)
{
    Queue* temp = new MyQueue(100);

    while (!src->isEmpty())
    {
        int v = src->dequeue();
        dst->enqueue(v);
        temp->enqueue(v);
    }

    while (!temp->isEmpty())
    {
        src->enqueue(temp->dequeue());
    }

    delete temp;
}

// same as task#1
void append(Queue* src, Queue* dst, int no)
{
    Queue* temp = new MyQueue(100);
    int count = 0;

    while (!src->isEmpty())
    {
        int v = src->dequeue();

        if (count < no)
        {
            dst->enqueue(v);
            count++;
        }

        temp->enqueue(v);
    }

    while (!temp->isEmpty())
    {
        src->enqueue(temp->dequeue());
    }

    delete temp;
}

void insert(Queue* q, int value, int pos)
{
    Queue* temp = new MyQueue(100);
    int index = 0;

    while (!q->isEmpty())
    {
        if (index == pos)
            temp->enqueue(value);

        int v = q->dequeue();
        temp->enqueue(v);
        index++;
    }

    if (pos >= index)
    {
        temp->enqueue(value);
    }

    while (!temp->isEmpty())
    {
        q->enqueue(temp->dequeue());
    }

    delete temp;
}

void insert(Queue* src, Queue* dst, int pos)
{
    Queue* temp = new MyQueue(100);
    int index = 0;

    while (!dst->isEmpty())
    {
        if (index == pos)
        {
            append(src, temp);
        }

        temp->enqueue(dst->dequeue());
        index++;
    }

    if (pos >= index)
    {
        append(src, temp);
    }

    while (!temp->isEmpty())
    {
        dst->enqueue(temp->dequeue());
    }

    delete temp;
}

void shiftRight(Queue* q, int pos)
{
    int size = getSize(q);

    if (pos >= size)
    {
        return;
    }

    Queue* temp = new MyQueue(100);

    int shiftCount = size - pos;

    for (int i = 0; i < shiftCount; i++)
    {
        int v = q->dequeue();
        q->enqueue(v);
    }

    delete temp;
}

void shiftLeft(Queue* q, int pos)
{
    int size = getSize(q);

    if (pos >= size)
    {
        return;
    }

    for (int i = 0; i < pos; i++)
    {
        int v = q->dequeue();
        q->enqueue(v);
    }
}

bool isEqual(Queue* q1, Queue* q2)
{
    Queue* t1 = new MyQueue(100);
    Queue* t2 = new MyQueue(100);

    bool equal = true;

    while (!q1->isEmpty() && !q2->isEmpty())
    {
        int v1 = q1->dequeue();
        int v2 = q2->dequeue();

        if (v1 != v2)
            equal = false;

        t1->enqueue(v1);
        t2->enqueue(v2);
    }

    if (!q1->isEmpty() || !q2->isEmpty())
    {
        equal = false;
    }

    while (!t1->isEmpty())
    {
        q1->enqueue(t1->dequeue());
    }

    while (!t2->isEmpty())
    {
        q2->enqueue(t2->dequeue());
    }

    delete t1;
    delete t2;

    return equal;
}

const int MAX_SIZE = 10;

int main()
{
    Queue* A = new MyQueue(MAX_SIZE);

    A->enqueue(10);
    A->enqueue(9);
    A->enqueue(2);
    A->enqueue(5);
    A->enqueue(-7);

    cout << "Queue A: ";
    display(A, cout);

    Queue* B = new MyQueue(MAX_SIZE);

    insert(B, -100, 2);
    cout << "Queue B after insert: ";
    display(B, cout);

    insert(A, B, 2);
    cout << "Queue B after inserting A: ";
    display(B, cout);

    shiftRight(B, 2);
    cout << "Queue B after shiftRight: ";
    display(B, cout);

    shiftLeft(B, 2);
    cout << "Queue B after shiftLeft: ";
    display(B, cout);

    return 0;
}
