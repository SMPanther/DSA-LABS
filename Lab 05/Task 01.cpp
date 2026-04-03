#include<iostream>
#include "Node.h"
#include "Task 01.h"
using namespace std;
//Write codes of the following Global functions and a suitable main function to test your functions :
//1.	Node * copy(Node*); // creates a copy of Node and all the connected nodes via the next-chain if any
//2.	void freeMemory(Node*);// frees the memory of all the connected Nodes
//3.	void insert(Node*, const int& value, const int& pos); // insert a Node of the given value at the given position
//4.	int remove(Node*, const int& pos); // removes the Node at the given position and return the values of the Node
//5.	void display(Node*); // displays al the connected Nodes

Node* copy(Node* n)
{
	if (n == nullptr)
	{
		return nullptr;
	}

	Node* head = new Node{ n->data, nullptr };
	Node* temp = head;

	n = n->next;

	while (n != nullptr)
	{
		temp->next = new Node{ n->data, nullptr };
		temp = temp->next;
		n = n->next;
	}

	return head;
}

void display(Node*n)
{
	while (n != nullptr)
	{
		cout << n->data << "->";
		n = n->next;
	}
	cout << endl;
}

void freeMemory(Node* n)
{
	while (n != nullptr)
	{
		Node* temp = n;
		n = n->next;
		delete temp;
	}
}
void readNode(int n, Node*& head)
{
	if (n <= 0) return;

	head = new Node();
	Node* temp = head;

	for (int i = 0; i < n; i++)
	{
		cout << "Enter Element " << i + 1 << ": ";
		cin >> temp->data;

		if (i < n - 1)
		{
			temp->next = new Node();
			temp = temp->next;
		}
	}

	temp->next = nullptr;
}

void insert(Node*& head, const int& value, const int& pos)
{
	Node* newNode = new Node{ value, nullptr };
	// Insert at beginning
	if (pos == 0)
	{
		newNode->next = head;
		head = newNode;
		return;
	}
	Node* temp = head;
	// Traverse to (pos - 1)
	for (int i = 0; i < pos - 1 && temp != nullptr; i++)
	{
		if (temp->next == nullptr)
		{
			cout << "Position Out of Range";
			return;
		}
		temp = temp->next;
	}

	// If position is invalid
	if (temp == nullptr)
	{
		cout << "Invalid Node for insertion";
		delete newNode;
		return;
	}

	// Insert node
	newNode->next = temp->next;
	temp->next = newNode;
}

int remove(Node*& head, const int& pos)
{
	if (head == nullptr) return -1;

	if (pos == 0)
	{
		Node* temp = head;
		int val = temp->data;
		head = head->next;
		delete temp;
		return val;
	}

	Node* temp = head;

	for (int i = 0; i < pos - 1 && temp->next != nullptr; i++)
	{
		if (temp->next == nullptr)
		{
			cout << "Position Out of Range";
			return -1;
		}
		temp = temp->next;
	}

	if (temp->next == nullptr) return -1;

	Node* del = temp->next;
	int val = del->data;

	temp->next = del->next;
	delete del;

	return val;
}

int main()
{
	Node* node = new Node();
	int n = 0;
	cout << "Enter No. of Elements:";
	cin >> n;
	readNode(n, node);
	cout << "Original Nodes: ";
	display(node);
	Node* ncopy = new Node();
	ncopy = copy(node);
	cout << "Copied Nodes: ";
	display(ncopy);
	cout << "Inserting Node at 02:" << endl;
	insert(node, 234, 2);
	display(node);
	cout << "Removing Node at 03:" << endl;
	remove(node, 3);
	freeMemory(node);
	freeMemory(ncopy);
}


