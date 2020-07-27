/*Given a linked list consisting of L nodes and given a number N. The task is to find the Nth node from the end of the linked list.*/

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

int PrintNthNodeFromEnd(Node* head, int n)
{
	Node* fast = head;
	Node* slow = head;

	int counter = 0;
	while (fast != NULL && counter < n)
	{
		fast = fast->next;
		counter++;
	}

	if (fast == NULL)
		return -1;

	while (fast != NULL)
	{
		fast = fast->next;
		slow = slow->next;
	}
	return slow->val;
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
	head = Insert(head, 9);
	
	PrintLinkedList(head);

	cout << PrintNthNodeFromEnd(head,11);
	return 0;
}