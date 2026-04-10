#include <iostream>
using namespace std;

#include "Queue.h"
#include "MyQueue.h"
#include "Stack.h"
#include "MyStack.h"

const int MAX_SIZE = 50;

int getSize(Queue* q)
{
    int size = 0;
    Queue* temp = new MyQueue(MAX_SIZE);

    while (!q->isEmpty())
    {
        int v = q->dequeue();
        temp->enqueue(v);
        size++;
    }

    while (!temp->isEmpty())
    {
        q->enqueue(temp->dequeue());
    }

    delete temp;
    return size;
}

void display(Queue* q)
{
    Queue* temp = new MyQueue(MAX_SIZE);

    while (!q->isEmpty())
    {
        int v = q->dequeue();
        cout << v << " ";
        temp->enqueue(v);
    }

    while (!temp->isEmpty())
    {
        q->enqueue(temp->dequeue());
    }

    delete temp;
    cout << endl;
}

void reverseFirstKElements(Queue* q, int k)
{
    int size = getSize(q);

    if (k <= 0 || k > size)
    {
        return;
    }

    Stack* s = new MyStack(size);

    for (int i = 0; i < k; i++)
    {
        int v = q->dequeue();
        s->push(v);
    }

    int v = 0;
    while (!s->isEmpty())
    {
        s->pop(v);
        q->enqueue(v);
    }

    for (int i = 0; i < size - k; i++)
    {
        int val = q->dequeue();
        q->enqueue(val);
    }

    delete s;
}

int main()
{
    Queue* q = new MyQueue(MAX_SIZE);

    // Example 1
    q->enqueue(10);
    q->enqueue(20);
    q->enqueue(30);
    q->enqueue(40);
    q->enqueue(50);

    int k = 3;

    cout << "Original Queue: ";
    display(q);

    reverseFirstKElements(q, k);

    cout << "After Reversing First " << k << " Elements: ";
    display(q);

    delete q;
    return 0;
}