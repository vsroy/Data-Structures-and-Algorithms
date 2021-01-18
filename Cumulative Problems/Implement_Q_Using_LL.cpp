/*Implement a Queue using Linked List.*/
#include<iostream>
using namespace std;

struct QNode
{
	QNode* next;
	int val;
	QNode(int x)
	{
		val = x;
		next = NULL;
	}
};

class Queue
{
public:
	QNode* front, *rear;

	Queue()
	{
		front = rear;
	}

	void enQueue(int x)
	{
		QNode* temp = new QNode(x);
		
		if (front == NULL)
		{
			front = rear = temp;
			return;
		}
		
		rear->next = temp;
		rear = temp;
	}

	void deQueue()
	{
		if (front == NULL)
			return;

		QNode* temp = front;
		front = front->next;

		if (front == NULL)
			rear = NULL;

		delete temp;
	}
};

int main()
{
	Queue q;
	q.enQueue(10);
	q.enQueue(20);
	q.deQueue();
	q.deQueue();
	q.enQueue(30);
	q.enQueue(40);
	q.enQueue(50);
	q.deQueue();
	cout << "Queue Front : " << (q.front)->val << endl;
	cout << "Queue Rear : " << (q.rear)->val;

	return 0;
}