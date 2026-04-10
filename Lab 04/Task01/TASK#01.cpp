// main.cpp for task 1
#include <iostream>
using namespace std;

#include "Stack.h"
#include "MyStack.h"
#include "Queue.h"
#include "MyQueue.h"

void read(Queue*, istream&); // read from user or file until queue is full
void display(Queue*, ostream&); // Display the values in the Queue
void append(Queue* src, Queue* dst); // append src to dst
void append(Queue* src, Queue* dst, int no); // append no of values fromsrc to dst
void reverseAppend(Queue* src, Queue* dst);// append src in dst in reverse order
int getSize(Queue* q);
void stats(Queue* q, int& sum, float& average);
bool isEqual(Queue*, Queue*);
const int MAX_SIZE = 5;

int main()
{
	Queue* A = new MyQueue(MAX_SIZE);
	int n = 0;
	read(A, cin);
	cout << " Queue A Values: ";
	display(A, cout);
	Queue* B = new MyQueue(MAX_SIZE);
	append(A, B);
	cout << " Queue B Values: ";
	display(B, cout);
	Queue* C = new MyQueue(MAX_SIZE);
	C->enqueue(9);
	C->enqueue(7);
	C->enqueue(5);
	append(A, C, 2);
	cout << "Queue C Values after append of 2 values from A: ";
	display(C, cout);
	Queue* D = new MyQueue(MAX_SIZE);
	reverseAppend(C, D);
	cout << "Queue D Values after reverse append from V: ";
	display(D, cout);
	int mx = 0;
	float ag = 0.0;
	stats(A, mx, ag);
	cout << "Queue A Values: ";
	display(A, cout);
	cout << "Average is " << ag << " maximum is " << mx << endl;
	Queue* M = new MyQueue(MAX_SIZE);
	Queue* N = new MyQueue(MAX_SIZE);
	Queue* P = new MyQueue(MAX_SIZE);
	append(A, M);
	append(N, M);
	append(N, P);
	P->enqueue(111);
	if (!isEqual(A, M))
	{
		cout << "Not Equal:\n";
	}
	else
	{
		cout << "Equal:\n";
	}
	if (!isEqual(A, P))
	{
		cout << "Not Equal:\n";
	}
	else
	{
		cout << "Equal:\n";
	}
	return 0;
}

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
void read(Queue* q, istream& in)
{
    cout << "Enter values of Queue" << endl;
    int value;
    while (!q->isFull())
    {
        in >> value;
        q->enqueue(value);
    }
}

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
    {
        q->enqueue(temp->dequeue());
    }

    out << endl;
    delete temp;
}

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

void reverseAppend(Queue* src, Queue* dst)
{
    Stack* s = new MyStack(100); // juas we need to revirest the direction of data stack is the best structure to do that

    Queue* temp = new MyQueue(100);

    while (!src->isEmpty())
    {
        int v = src->dequeue();
        s->push(v);
        temp->enqueue(v);
    }

    while (!s->isEmpty())
    {
        int v;
        s->pop(v);
        dst->enqueue(v);
    }

    while (!temp->isEmpty())
    {
        src->enqueue(temp->dequeue());
    }

    delete s;
    delete temp;
}

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
    {
        q->enqueue(temp->dequeue());
    }

    delete temp;
    return size;
}

void stats(Queue* q, int& sum, float& avg)
{
    sum = 0;
    int size = 0;

    Queue* temp = new MyQueue(100);

    while (!q->isEmpty())
    {
        int v = q->dequeue();
        sum += v;
        size++;
        temp->enqueue(v);
    }

    while (!temp->isEmpty())
    {
        q->enqueue(temp->dequeue());
    }

    avg = (size == 0) ? 0 : (float)sum / size;

    delete temp;
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
        equal = false;

    while (!t1->isEmpty())
        q1->enqueue(t1->dequeue());

    while (!t2->isEmpty())
        q2->enqueue(t2->dequeue());

    delete t1;
    delete t2;

    return equal;
}
