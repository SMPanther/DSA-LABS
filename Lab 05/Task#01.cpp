#include<iostream>
using namespace std;

#include "Node.h"

/*
copy :
make new first node
loop:
copy data
link next
 
 
 display
loop:
print data
go next


freeMemory
loop:
save node
move next
delete


insert
go to pos-1
make new node
link it in between


remove
if pos=1:
move head
delete first
else:
go to pos-1
skip node
delete it*/
Node* copy(Node*s)
{
	if (s == nullptr)
	{
		return nullptr;
	}
	else
	{
		Node* head = new Node();
		head->data = s->data;
		head->next = nullptr;

		Node* t = head;
		s = s->next;

		while (s != nullptr)
		{
			t->next = new Node();
			t = t->next;
			t->data = s->data;
			t->next = nullptr;
			s = s->next;
		}
		return head;
	}
}

void display(Node* head)
{
	while (head != nullptr)
	{
		cout << head->data << " -> ";
		head = head->next;
	}
}
void freeMemory(Node*s)
{
	while (s != nullptr)
	{
		Node* temp = s;
		s = s->next;
		delete temp;
	}
}
void insert(Node* s, const int& value, const int& pos) // insert a Node of the given value at the given position
{
	Node* temp = s;

	for (int i = 1; i < pos-1; i++)
	{
		if (temp == nullptr)
		{
			cout << "Can't add\n";
			return;
		}

		temp = temp->next;
	}

	if (temp == nullptr)
	{
		cout << "Can't add\n";
		return;
	}

	Node* newNode = new Node{ value, temp->next };
	temp->next = newNode;


}
int remove(Node*& head, const int& pos)
{
	if (head == nullptr || pos <= 0)
	{
		cout << "Invalid position\n";
		return -1;
	}
	if (pos == 1)
	{
		Node* temp = head;
		int val = temp->data;
		head = head->next;
		delete temp;
		return val;
	}

	Node* temp = head;

	for (int i = 1; i < pos - 1; i++)
	{
		if (temp->next == nullptr)
		{
			cout << "Position out of range\n";
			return -1;
		}
		temp = temp->next;
	}

	if (temp->next == nullptr)
	{
		cout << "Position out of range\n";
		return -1;
	}

	Node* delNode = temp->next;
	int val = delNode->data;

	temp->next = delNode->next;
	delete delNode;

	return val;
}
int main()
{
	// copy
	Node* head = new Node{ 10, nullptr };
	head->next = new Node{ 20, nullptr };
	head->next->next = new Node{ 30, nullptr };

	cout << "Original List:\n";
	display(head);
	Node* copied = copy(head);

	cout << "Copied List:\n";
	display(copied);

	// Free both nodes
	//freeMemory(head);
	freeMemory(copied);

	insert(head, 5, 1);    
	//insert(head, 15, 3);   
	insert(head, 40, 6);

	cout << endl;
	cout << endl;
	cout << "After insertion :" << endl;
	display(head);
	cout << endl;

	remove(head, 1);
	cout << endl;
	cout << endl;
	cout << "After deletion :" << endl;
	display(head);

	return 0;
}
