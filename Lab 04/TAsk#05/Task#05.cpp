#include <iostream>
#include <string>
using namespace std;

#include "Queue.h"
#include "MyQueue.h"

const int MAX_SIZE = 50;

class Order
{
public:
    string item;
    int price;
    int time;

    Order(string i, int p, int t)
    {
        item = i;
        price = p;
        time = t;
    }
};

void display(Queue* q, Order arr[])
{
    Queue* temp = new MyQueue(MAX_SIZE);

    while (!q->isEmpty())
    {
        int index = q->dequeue();
        cout << arr[index].item << " ";
        temp->enqueue(index);
    }

    while (!temp->isEmpty())
    {
        q->enqueue(temp->dequeue());
    }

    delete temp;
    cout << endl;
}

void processOrders(Queue* q, Order arr[])
{
    int totalEarning = 0;
    int totalTime = 0;

    cout << endl;
    cout << "Processing Orders:" << endl;

    while (!q->isEmpty())
    {
        int index = q->dequeue();

        cout << "Serving: " << arr[index].item << endl;
        cout << "Price: " << arr[index].price << ", Time: " << arr[index].time << endl;

        totalEarning += arr[index].price;
        totalTime += arr[index].time;
    }

    cout << "\nTotal Earning: " << totalEarning << endl;
    cout << "Total Time Taken: " << totalTime << endl;
}

int main()
{
    Queue* orderQueue = new MyQueue(MAX_SIZE);

    Order menu[5] = {
        Order("Burger", 200, 20),
        Order("Sandwich", 250, 30),
        Order("French Fries", 100, 10),
        Order("Fried Chicken", 400, 40),
        Order("Pizza", 350, 40)
    };

    orderQueue->enqueue(0); 
    orderQueue->enqueue(1); 
    orderQueue->enqueue(2); 
    orderQueue->enqueue(3); 
    orderQueue->enqueue(4); 

    cout << "Order Queue:" << endl;
    display(orderQueue, menu);

    processOrders(orderQueue, menu);

    delete orderQueue;
    return 0;
}