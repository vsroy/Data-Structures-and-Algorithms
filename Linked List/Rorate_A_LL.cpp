/*Given a singly linked list of size N. The task is to rotate the linked list counter-clockwise by k nodes, 
where k is a given positive integer smaller than or equal to length of the linked list.*/

#include<iostream>
using namespace std;

struct  Node
{
	int val;
	Node* next;
};

Node* NewNode(int x)
{
	Node* temp = new Node;
	temp->val = x;
	temp->next = NULL;
	return temp;
}

Node* Insert(Node* head, int x)
{
	if (head == NULL)
		return NewNode(x);
	Node* temp = head;
	while (temp->next != NULL)
	{
		temp = temp->next;
	}
	temp->next = NewNode(x);
	return head;
}

void PrintLinkedList(Node* head)
{
	Node* temp = head;
	while (temp != NULL)
	{
		cout << temp->val << " ";
		temp = temp->next;
	}
	cout << endl;
}

Node* RotateLinkedList(Node* head, int k)
{
	int counter = 0;

	Node* temp = head;
	while (temp != NULL)
	{
		counter++;
		temp = temp->next;
	}

	//Check if k > total elements of Linked List
	if (k > counter)
		return NULL;

	//Now, move k steps down the Linked List
	temp = head;
	counter = 0;
	
	while (counter < k-1)
	{
		temp = temp->next;
		counter++;
	}

	//We get the element now which will be our new head, and element previous to that will be last element
	Node* temp2 = temp->next;		//1 2 3 4 5 6 7 8 
	Node* temp3 = temp->next;
	temp->next = NULL;

	
	while (temp2->next != NULL)
		temp2 = temp2->next;

	temp2->next = head;
	head = temp3;

	return head;
}

int main()
{
	Node* head = NULL;
	head = Insert(head, 1);
	Insert(head, 2);
	Insert(head, 3);
	Insert(head, 4);
	Insert(head, 5);
	/*
	Insert(head, 6);
	Insert(head, 7);
	Insert(head, 8);
	*/

	PrintLinkedList(head);

	head = RotateLinkedList(head, 3);

	PrintLinkedList(head);

	return 0;
}