/*Given a singly linked list of size N. The task is to swap elements in the linked list pairwise.
For example, if the input list is 1 2 3 4, the resulting list after swaps will be 2 1 4 3.*/

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

void swap(int& a, int& b)
{
	int temp = a;
	a = b;
	b = temp;
}

Node* PairWiseSwap(Node* head)
{
	Node* temp = head;
	while (temp != NULL && temp->next != NULL)
	{
		swap(temp->val, temp->next->val);
		temp = temp->next->next;
	}
	return head;
}

int main()
{
	Node* head = NULL;
	head = Insert(head, 1);
	head = Insert(head, 2);
	head = Insert(head, 3);
	head = Insert(head, 4);
	head = Insert(head, 5);
	head = Insert(head, 6);
	head = Insert(head, 7);
	head = Insert(head, 8);

	head = PairWiseSwap(head);

	PrintLinkedList(head);

	return 0;
}