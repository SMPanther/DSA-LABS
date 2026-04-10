#include <iostream>
using namespace std;

#include "Stack.h"
#include "MyStack.h"

const int MAX_SIZE = 25;

void read(Stack*, istream&, int);
void display(Stack*, ostream&);

bool isPrime(int);
bool isPerfectSquare(int);
bool isStackPalindrome(Stack*);

int main()
{
    Stack* A = new MyStack(MAX_SIZE);

    cout << "Enter 10 integers:\n";
    read(A, cin, 10);

    cout << "Stack Values: " << endl;
    display(A, cout);

    Stack* temp = new MyStack(MAX_SIZE);
    int v = 0;
    cout << endl;
    cout << "Checking each value:" << endl;

    while (A->pop(v))
    {
        cout << v << " : ";

        if (isPrime(v))
        {
            cout << "Prime ";
        }

        if (isPerfectSquare(v))
        {
            cout << "PerfectSquare ";
        }
        temp->push(v);
        cout << endl;
    }

    while (temp->pop(v))
    {
        A->push(v);
    }

    if (isStackPalindrome(A))
    {
        cout << "Stack values form a Palindrome" << endl;
    }
    else
    {
        cout << "Stack values do NOT form a Palindrome" << endl;
    }

    return 0;
}

void read(Stack* s, istream& in, int n)
{
    int v = 0;

    for (int i = 0; i < n; i++)
    {
        in >> v;
        s->push(v);
    }
}

void display(Stack* s, ostream& out)
{
    Stack* temp = new MyStack(MAX_SIZE);
    int v = 0;

    while (s->pop(v))
    {
        out << v << " ";
        temp->push(v);
    }

    while (temp->pop(v))
        s->push(v);

    delete temp;
}

bool isPrime(int n)
{
    if (n <= 1)
    {
        return false;
    }

    for (int i = 2; i < n; i++)
    {
        if (n % i == 0)
        {
            return false;
        }
    }

    return true;
}

bool isPerfectSquare(int n)
{
    if (n < 0)
    {
        return false;
    }

    for (int i = 0; i * i <= n; i++)
    {
        if (i * i == n)
        {
            return true;
        }
    }

    return false;
}

bool isStackPalindrome(Stack* s)
{
    Stack* temp = new MyStack(MAX_SIZE);
    Stack* copy = new MyStack(MAX_SIZE);

    int v;

    while (s->pop(v))
    {
        temp->push(v);
        copy->push(v);
    }

    while (temp->pop(v))
    {
        s->push(v);
    }

    while (s->pop(v))
    {
        int x = 0;
        copy->pop(x);

        if (v != x)
        {
            temp->push(v);
            while (temp->pop(x))
            {
                s->push(x);
            }
            delete temp;
            delete copy;
            return false;
        }

        temp->push(v);
    }

    while (temp->pop(v))
    {
        s->push(v);
    }

    delete temp;
    delete copy;

    return true;
}