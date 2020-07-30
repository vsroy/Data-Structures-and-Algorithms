/*Given a linked list of N nodes where nodes can contain values 0s, 1s, and 2s only. The task is to segregate 0s, 1s, and 2s linked list such that all zeros segregate to head side, 
2s at the end of the linked list, and 1s in the mid of 0s and 2s.*/

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

Node* Convert0s1s2s(Node* head)
{
	int count0 = 0,count1 = 0, count2 = 0;
	Node* temp = head;

	//First, Count 0s, 1s, 2s
	while (temp != NULL)
	{
		if (temp->val == 0)
			count0++;
		else if (temp->val == 1)
			count1++;
		else
			count2++;
		temp = temp->next;
	}

	//Now fill with 0s, 1s, 2s
	temp = head;
	while (count0 > 0)
	{
		temp->val = 0;
		temp = temp->next;
		count0--;
	}

	while (count1 > 0)
	{
		temp->val = 1;
		temp = temp->next;
		count1--;
	}

	while (count2 > 0)
	{
		temp->val = 2;
		temp = temp->next;
		count2--;
	}
	return head;
}

int main()
{
	Node* head = NULL;
	head = Insert(head, 1);
	head = Insert(head, 2);
	head = Insert(head, 2);
	head = Insert(head, 1);
	head = Insert(head, 2);
	head = Insert(head, 0);
	head = Insert(head, 2);
	head = Insert(head, 2);
	
	head = Convert0s1s2s(head);

	PrintLinkedList(head);

	return 0;
}