#include <iostream>
#include <fstream>
#include <string>
using namespace std;

#include "Stack.h"
#include "MyStack.h"

const int MAX_SIZE = 100;

void readFile(Stack<string>*, int&);
void display(Stack<string>*, int&);
void reverseCopy(Stack<string>*, Stack<string>*, int&);
void removeDuplicates(Stack<string>*, int&);
void wordFrequency(Stack<string>*, Stack<int>*, int&);

int main()
{
    Stack<string>* words = new MyStack<string>(MAX_SIZE);
    Stack<string>* reverseStack = new MyStack<string>(MAX_SIZE);
    Stack<int>* freq = new MyStack<int>(MAX_SIZE);

    int wordCount = 0;

    readFile(words, wordCount);

    cout << "\nOriginal Stack:\n";
    display(words, wordCount);

    reverseCopy(words, reverseStack, wordCount);

    cout << "\nReverse Copy:\n";
    display(reverseStack, wordCount);

    removeDuplicates(reverseStack, wordCount);

    cout << "\nAfter Removing Duplicates:\n";
    display(reverseStack, wordCount);

    cout << "\nWord Frequencies:\n";
    wordFrequency(reverseStack, freq, wordCount);

    delete words;
    delete reverseStack;
    delete freq;

    return 0;
}

void readFile(Stack<string>* s, int& count)
{
    ifstream file("para.txt");

    if (!file)
    {
        cout << "File not found.\n";
        return;
    }

    string word;

    while (file >> word && count < MAX_SIZE)
    {
        s->push(word);
        count++;
    }

    file.close();
}

void display(Stack<string>* s, int& count)
{
    Stack<string>* temp = new MyStack<string>(MAX_SIZE);

    string v;

    while (s->pop(v))
    {
        cout << v << " ";
        temp->push(v);
    }

    while (temp->pop(v))
        s->push(v);

    cout << endl;

    delete temp;
}

void reverseCopy(Stack<string>* src, Stack<string>* dst, int& count)
{
    Stack<string>* temp = new MyStack<string>(MAX_SIZE);

    string v;

    while (src->pop(v))
    {
        dst->push(v);
        temp->push(v);
    }

    while (temp->pop(v))
        src->push(v);

    delete temp;
}

void removeDuplicates(Stack<string>* s, int& count)
{
    Stack<string>* temp = new MyStack<string>(MAX_SIZE);

    string v;

    while (s->pop(v))
    {
        bool duplicate = false;

        Stack<string>* check = new MyStack<string>(MAX_SIZE);

        string x;

        while (temp->pop(x))
        {
            if (x == v)
            {
                duplicate = true;
            }

            check->push(x);
        }

        while (check->pop(x))
        {
            temp->push(x);
        }

        delete check;

        if (!duplicate)
            temp->push(v);
    }

    while (temp->pop(v))
        s->push(v);

    delete temp;
}

void wordFrequency(Stack<string>* s, Stack<int>* freq, int& count)
{
    Stack<string>* temp = new MyStack<string>(MAX_SIZE);

    string v;

    while (s->pop(v))
    {
        int frequency = 1;

        Stack<string>* check = new MyStack<string>(MAX_SIZE);

        string x;

        while (temp->pop(x))
        {
            if (x == v)
            {
                frequency++;
            }

            check->push(x);
        }

        while (check->pop(x))
        {
            temp->push(x);
        }

        delete check;

        cout << v << " : " << frequency << endl;

        freq->push(frequency);

        temp->push(v);
    }

    while (temp->pop(v))
    {
        s->push(v);
    }

    delete temp;
}
