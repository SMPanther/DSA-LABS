#include <iostream>
using namespace std;

#include "Stack.h"
#include "MyStack.h"

const int MAX_SIZE = 25;

void read(Stack* s, istream& in, int n)
{
    int value;

    cout << "Enter values\n";

    for (int i = 0; i < n; i++)
    {
        in >> value;
        s->push(value);
    }
}

void display(Stack* s, ostream& out)
{
    Stack* temp = new MyStack(MAX_SIZE);
    int v;

    while (s->pop(v))
    {
        out << v << " ";
        temp->push(v);
    }

    while (temp->pop(v))
    {
        s->push(v);
    }

    delete temp;
    out << endl;
}

void copy(Stack* src, Stack* dst)
{
    Stack* temp = new MyStack(MAX_SIZE);
    int v;

    while (src->pop(v))
    {
        temp->push(v);
    }

    while (temp->pop(v))
    {
        src->push(v);
        dst->push(v);
    }

    delete temp;
}

void insert(Stack* src, Stack* dst, int pos)
{
    Stack* temp = new MyStack(MAX_SIZE);
    int v;
    int count = 0;

    while (dst->pop(v))
    {
        temp->push(v);
    }

    while (temp->pop(v))
    {
        if (count == pos)
        {
            Stack* temp2 = new MyStack(MAX_SIZE);

            while (src->pop(v))
            {
                temp2->push(v);
            }

            while (temp2->pop(v))
            {
                dst->push(v);
                src->push(v);
            }

            delete temp2;
        }

        dst->push(v);
        count++;
    }

    delete temp;
}

void shiftUp(Stack* s, int pos)
{
    Stack* temp = new MyStack(MAX_SIZE);
    int v;
    int count = 0;

    while (s->pop(v))
    {
        if (count >= pos)
            temp->push(v);

        count++;
    }

    while (temp->pop(v))
    {
        s->push(v);
    }

    delete temp;
}

void shiftDown(Stack* s, int pos)
{
    Stack* temp = new MyStack(MAX_SIZE);
    int v;

    for (int i = 0; i < pos; i++)
        temp->push(0);

    while (s->pop(v))
        temp->push(v);

    while (temp->pop(v))
        s->push(v);

    delete temp;
}

void stats(Stack* s, int& max, float& average)
{
    Stack* temp = new MyStack(MAX_SIZE);
    int v;
    int sum = 0;
    int count = 0;

    while (s->pop(v))
    {
        if (count == 0 || v > max)
            max = v;

        sum += v;
        count++;

        temp->push(v);
    }

    while (temp->pop(v))
        s->push(v);

    if (count > 0)
        average = (float)sum / count;

    delete temp;
}

int main()
{
    Stack* A = new MyStack(MAX_SIZE); 
    int n = 0;
    cout << "please select a number between 1 and " << MAX_SIZE << ": ";
    cin >> n;
    read(A, cin, n);
    cout << "Stack A Values: ";
    display(A, cout);
    Stack* B = new MyStack(MAX_SIZE);
    copy(A, B);
    cout << "Stack B Values: ";
    display(B, cout);
    Stack* C = new MyStack(MAX_SIZE);
    C->push(9);
    C->push(7);
    C->push(5);
    insert(A, C, 2);
    cout << "Stack C Values: ";
    display(C, cout);
    shiftUp(C, 2);                  // chnaged name from sheftleft to shiftUp
    cout << "Stack C Values: ";
    display(C, cout);
    shiftDown(C, 2);                // chnaged name from sheftRight to shiftDown
    cout << "Stack C Values: ";
    display(C, cout);
    int mx = 0;
    float ag = 0.0;
    stats(C, mx, ag);
    cout << "Stack C Values: ";
    display(C, cout);
    cout << "Average is " << ag << " maximum is " << mx << endl;
    return 0;
}