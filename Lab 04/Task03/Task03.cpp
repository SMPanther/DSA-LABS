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

// Same as task 1 & 2
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
void display(Queue* s, ostream& out) // Display the values in the Queue
{
	int size = getSize(s);
	Queue* temp = new MyQueue(size);
	int value = 0;

	while (!s->isEmpty())
	{
		value = s->dequeue();
		out << value << " ";
		temp->enqueue(value);
	}

	while (!temp->isEmpty())
	{
		s->enqueue(temp->dequeue());
	}


	out << endl;
	delete temp;
}
void append(Queue* src, Queue* dst) // append src to dst
{
	int src_size = getSize(src);
	Queue* temp = new MyQueue(src_size);
	int value = 0;
	while (!src->isEmpty())
	{
		value = src->dequeue();
		temp->enqueue(value);
		dst->enqueue(value);
	}

	while (!temp->isEmpty())
	{
		src->enqueue(temp->dequeue());
	}
	delete temp;
}
void append(Queue* src, Queue* dst, int no) // append no of values fromsrc to dst
{
	int src_size = getSize(src);

	if (no >= src_size)
	{
		no = src_size;
	}

	Queue* temp = new MyQueue(src_size);

	int value = 0;
	int count = 0;

	while (!src->isEmpty())
	{
		value = src->dequeue();
		temp->enqueue(value);

		if(count < no)
		{
			dst->enqueue(value);
			count++;
		}
	}

	while (!temp->isEmpty())
	{
		src->enqueue(temp->dequeue());
	}
	delete temp;

}
void reverseAppend(Queue* src, Queue* dst)// append src in dst in reverseorder
{
	int src_size = getSize(src);
	Queue* qTemp = new MyQueue(src_size);
	Stack* sTemp = new MyStack(src_size);
	int value = 0;

	while (!src->isEmpty())
	{
		value = src->dequeue();
		qTemp->enqueue(value);
		sTemp->push(value);
	}

	while (!qTemp->isEmpty())
	{
		src->enqueue(qTemp->dequeue());
		sTemp->pop(value);
		dst->enqueue(value);
	}
	delete qTemp;
	delete sTemp;
}
void insert(Queue* src, Queue* dst, int pos)
{
	int src_size = getSize(src);
	Queue* temp = new MyQueue(src_size);
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
void insert(Queue* q, int v, int pos) // insert a value in the queue atthe given position
{
	int src_size = getSize(q);

	if (pos >= src_size)
	{
		cout << "cant insert in this position." << endl;
	}

	Queue* temp = new MyQueue(src_size + 1);

	int count = 0;
	int value = 0;

	while (!q->isEmpty())
	{
		value = q->dequeue();
		 
		if (count == pos)
		{
			temp->enqueue(v);
		}

		temp->enqueue(value);
		count++;
	}

	while (!temp->isEmpty())
	{
		q->enqueue(temp->dequeue());
	}

	delete temp;
}
bool isEqual(Queue* q1, Queue* q2)
{
	int size = getSize(q1);
	if (size != getSize(q2))
	{
		return false;
	}

	Queue* t1 = new MyQueue(size);
	Queue* t2 = new MyQueue(size);
	bool equal = true;

	while (!q1->isEmpty())
	{
		int v1 = q1->dequeue();
		int v2 = q2->dequeue();

		if (v1 != v2)
			equal = false;

		t1->enqueue(v1);
		t2->enqueue(v2);
	}

	while (!t1->isEmpty())
	{
		q1->enqueue(t1->dequeue());
		q2->enqueue(t2->dequeue());
	}
	delete t1;
	delete t2;

	return equal;
}
bool isPalindrome(Queue* q) // check if the values in the queue arePalindrome
{
	int size = getSize(q);
	Queue* temp = new MyQueue(size);

	reverseAppend(q, temp);

	bool result = isEqual(q, temp);

	delete temp;

	return result;

}
void shiftRight(Queue* q, int pos)
{
	int size = getSize(q);

    if (pos >= size) 
	{
		return;
	}

    int shift = size - pos;

    for (int i = 0; i < shift; i++)
    {
        int v = q->dequeue();
        q->enqueue(v);
    }
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



void isPalindrome(Queue* q, bool& result)//where single digits are stored andyou can’t use any other Queue or Stack or ADT
{
	int size = getSize(q);

	if (size == 0)
	{
		result = true;
		return;
	}

	int num = 0;

	for (int i = 0; i < size; i++)
	{
		int digit = q->dequeue();

		num = num * 10 + digit;

		q->enqueue(digit);
	}

	int original = num;
	int reversed = 0;

	while (num != 0)
	{
		int digit = num % 10;
		reversed = reversed * 10 + digit;
		num /= 10;
	}

	result = (original == reversed);
}
void rotateLeft(Queue* q, int pos)
{
	shiftLeft(q,pos);
}
void rotateRight(Queue* q, int pos)
{
	int size = getSize(q);
	if (size == 0) 
	{
		return;
	}

	pos = pos % size;
	int shift = size - pos;

	for (int i = 0; i < shift; i++)
	{
		int v = q->dequeue();
		q->enqueue(v);
	}
}


int get(Queue* q, int pos) // get from the queue the value at the givenposition after removing from the Queue
{
	int size = getSize(q);
	Queue* temp = new MyQueue(size);

	int count = 0;
	int value = 0;
	int result = 0;

	while (!q->isEmpty())
	{
		value = q->dequeue();
		if (count == pos) 
		{
			result = value;
		}
		temp->enqueue(value);
		count++;
	}

	while (!temp->isEmpty())
	{
		q->enqueue(temp->dequeue());
	}
	return result;
}
void sort(Queue* q)
{
	int size = getSize(q);

	Queue* sorted = new MyQueue(size);

	for (int i = 0; i < size; i++)
	{
		int minVal;
		bool first = true;

		for (int j = 0; j < size - i; j++)
		{
			int v = q->dequeue();
			if (first || v < minVal)
			{
				minVal = v;
				first = false;
			}

			q->enqueue(v);
		}

		bool removed = false;

		for (int j = 0; j < size - i; j++)
		{
			int v = q->dequeue();

			if (v == minVal && !removed)
			{
				sorted->enqueue(v); 

				removed = true;
			}
			else
			{
				q->enqueue(v); 
			}
		}
	}
	while (!sorted->isEmpty())
	{
		q->enqueue(sorted->dequeue());
	}

	delete sorted;
}


const int MAX_SIZE = 10;
// somechanges in the main as a Queue B was being used that wasnt created so replaced it with A and D 
int main()
{
	Queue* A = new MyQueue(MAX_SIZE);
	A->enqueue(10);
	A->enqueue(9);
	A->enqueue(2);
	A->enqueue(5);
	A->enqueue(-7);
	cout << " Queue A Values: ";
	display(A, cout);

	rotateRight(A, 2);
	cout << " Queue A Values after rotateRight from pos 2";
	display(A, cout);
	rotateLeft(A, 2);
	cout << " Queue B Values after rotateLeft from pos 2: ";
	display(A, cout);
	int v = get(A, 3);
	cout << "Value at pos 3: " << v << endl;
	cout << " Queue A Values after get from pos 3: ";
	display(A, cout);
	if (isPalindrome(A))
	{
		cout << "A is a Palindrome\n";
	}
	else
	{
		cout << "A is NOT a Palindrome\n";
	}
	Queue* C = new MyQueue(MAX_SIZE);
	C->enqueue(234);
	C->enqueue(56);
	C->enqueue(786);
	C->enqueue(56);
	C->enqueue(234);
	if (isPalindrome(C))
	{
		cout << "C is a Palindrome\n";
	}
	else
	{
		cout << "C is NOT a Palindrome\n";
	}
	Queue* D = new MyQueue(MAX_SIZE);
	C->enqueue(3);
	C->enqueue(5);
	C->enqueue(7);
	C->enqueue(5);
	C->enqueue(3);
	bool isIt = false;
	isPalindrome(D, isIt);
	if (D)
	{
		cout << "D is a Palindrome\n";
	}
	else
	{
		cout << "D is NOT a Palindrome\n";
	}
	sort(D);
	cout << " Queue B Values after sort in ascending \n";
	display(D, cout);
	return 0;
}
