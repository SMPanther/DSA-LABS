#include <iostream>
using namespace std;
#include "AbstractArray.h"
#include "MyArray.h"

void read(AbstractArray*, istream& , int); // reads 1 to 10 integers from the user
void display(AbstractArray*, ostream&); // displays values in the AbstractArray
void copy(AbstractArray* src, AbstractArray* dst); // copy src AbstractArray to dst AbstractArray
void insert(AbstractArray* src, AbstractArray* dst, int pos); // insert src AbstractArray to dst AbstractArray at the given pos
void shiftLeft(AbstractArray* aa, int pos); // shift left AbstractArray aa from the given pos
void shiftRight(AbstractArray* aa, int pos); // shift right AbstractArray aa from the given pos

void stats(AbstractArray* AA, int& max, float& average)// calculate maimum and average value of AA
{
	int MAX_SIZE = 25;
	int value;
	int sum = 0;
	int count = 0;

	AbstractArray* temp = new MyArray(MAX_SIZE);

	while (!AA->isEmpty())
	{
		AA->remove(value);

		if (count == 0 || value > max)
			max = value;

		sum += value;
		count++;

		temp->add(value);
	}

	while (!temp->isEmpty())
	{
		temp->remove(value);
		AA->add(value);
	}

	delete temp;

	if (count > 0)
		average = (float)sum / count;
}
	
const int MAX_SIZE = 25; // required to set the size od the arrays


int main()
{
	int n = 0; // required for read function
	AbstractArray* A = new MyArray(MAX_SIZE);// changeed new AbstractArray() to new MyArray()	int n = 0;
	cout << "please select a number between 1 and " << MAX_SIZE << ": ";
	cin >> n;
	read(A, cin, n);

	cout << "Array A Values: ";
	display(A, cout);
	AbstractArray* B = new MyArray(MAX_SIZE); // changeed new AbstractArray() to new MyArray()
	copy(A, B);
	cout << "Array B Values: ";
	display(B, cout);
	AbstractArray* C = new MyArray(MAX_SIZE); // changeed new AbstractArray() to new MyArray()
	C->add(9);
	C->add(7);
	C->add(5);
	insert(A, C, 2);
	cout << "Array C Values: ";
	display(C, cout);
	shiftLeft(C, 2);
	cout << "Array C Values: ";
	display(C, cout);
	shiftRight(C, 2);
	cout << "Array C Values: ";
	display(C, cout);
	int mx = 0;
	float ag = 0.0;
	stats(C, mx, ag);


	cout << "Array C Values: ";
	display(C, cout);
	cout << "Average is " << ag << " maximum is " << mx << endl;
	return 0;
}
void read(AbstractArray* AA, istream& in , int size) // Added the 3rd paremeteer int size to match the parameter list of the call in main
{
	cout << "Enter values" << endl;
	for (int i = 0; i < size; i++)
	{
		int v = 0;
		in >> v;
		AA->add(v);
	}
}

void display(AbstractArray* AA, ostream& out)
{
	int value = 0;;

	AbstractArray* temp = new MyArray(MAX_SIZE);

	while (!AA->isEmpty())
	{
		AA->remove(value);
		out << value << " ";
		temp->add(value);
	}
		out << endl;
	while (!temp->isEmpty())
	{
		temp->remove(value);
		AA->add(value);
	}

	delete temp;
	
}

void copy(AbstractArray* src, AbstractArray* dst)
{
	int value = 0;

	AbstractArray* temp = new MyArray(MAX_SIZE);

	while (!src->isEmpty())
	{
		src->remove(value);
		temp->add(value);
	}
	while (!temp->isEmpty())
	{
		temp->remove(value);
		src->add(value);
		dst->add(value);
	}

	delete temp;
}

void insert(AbstractArray* src, AbstractArray* dst, int pos)
{
	int value = 0;
	int i = 0;

	AbstractArray* temp = new MyArray(MAX_SIZE);

	while (!dst->isEmpty())
	{
		dst->remove(value);
		temp->add(value);
	}

	while (!temp->isEmpty())
	{
		temp->remove(value);

		if (i == pos)
		{
			copy(src, dst);
		}

		dst->add(value);
		i++;
	}
	delete temp;
}

void shiftLeft(AbstractArray* aa, int pos)
{
	int value = 0;
	int i = 0;

	AbstractArray* temp = new MyArray(MAX_SIZE);

	while (!aa->isEmpty())
	{
		aa->remove(value);

		if (i >= pos)
		{
			temp->add(value);
		}
		i++;
	}

	while (!temp->isEmpty())
	{
		temp->remove(value);
		aa->add(value);
	}
	delete temp;
}

void shiftRight(AbstractArray* aa, int pos)
{
	int value = 0;

	AbstractArray* temp = new MyArray(MAX_SIZE);

	for (int i = 0; i < pos; i++)
	{
		temp->add(0);
	}

	while (!aa->isEmpty())
	{
		aa->remove(value);
		temp->add(value);
	}

	while (!temp->isEmpty())
	{
		temp->remove(value);
		aa->add(value);
	}

	delete temp;
}
