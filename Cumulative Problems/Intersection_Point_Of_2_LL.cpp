/*Given two singly linked lists of size N and M, write a program to get the point where two linked lists intersect each other.*/

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

int countNodes(Node* head)
{
	int count = 0;
	Node* temp = head;
	while (temp != NULL)
	{
		count++;
		temp = temp->next;
	}
	return count;
}

int IntersectionHelper(Node* longer, Node* shorter, int k)
{
	int index = 0;

	//Move the longer list k steps forward
	for (int i = 0; i < k; i++)
	{
		if (longer == NULL)
			return -1;
		longer = longer->next;
	}

	//Move longer and shorter k steps unitl they meet. If they do not meet, they do not intersect
	while (longer != NULL && shorter != NULL)
	{
		if (longer == shorter)
			return longer->val;
		longer = longer->next;
		shorter = shorter->next;
	}
	return -1;
}

int IntersectionOf2LinkedLists(Node* head1, Node* head2)
{
	int count1 = 0, count2 = 0;
	count1 = countNodes(head1);
	count2 = countNodes(head2);
	
	if (count1 > count2)
		return IntersectionHelper(head1, head2, count1 - count2);
	else
		return IntersectionHelper(head2, head1, count2 - count1);
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

	return 0;
}