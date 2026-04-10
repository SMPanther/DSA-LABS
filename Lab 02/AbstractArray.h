#pragma once // i moved the fuction declaration from outside the class to the inside to rremoved the LINKER error i was facing 
class AbstractArray
{
public:
	AbstractArray(int _maxCapacity = 0)
	{
		currentIndex = -1;
		maxCapacity = _maxCapacity;
		values = new int[maxCapacity] {0};
	}
	AbstractArray(const AbstractArray& AA)
	{
		{
			maxCapacity = AA.maxCapacity;
			values = new int[maxCapacity] {0};
			// uncommented the for loop as we need to copy each element in AA into the new AbstractArray that we are creating
			for (int i = 0; i < maxCapacity; i++)
			{
				values[i] = AA.values[i];
			}

		}
	}
	virtual void add(int v) = 0; // increments currentIndex and add value if not full
	virtual bool remove(int& value) = 0; // if not empty returns the value at the currentIndex and decrements currentIndex
	virtual bool get(int index, int& value) = 0; // return the value at the index if index is valid
	virtual void insert(int index, int value) = 0; // inserts the value at the index if index is valid, replaces existing value
	bool isEmpty()
	{
			return (currentIndex < 0);
	}
	bool isFull()
	{
		return (currentIndex == maxCapacity - 1);

	}

protected:
	int currentIndex;
	int* values;
	int maxCapacity;

};


