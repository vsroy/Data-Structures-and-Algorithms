/*Given two sorted linked lists consisting of N and M nodes respectively. The task is to merge both of the list (in-place) 
and return head of the merged list.*/

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

Node* MergeLinkedLists(Node* head1, Node* head2)
{
	if (head1 == NULL)
		return head2;
	if (head2 == NULL)
		return head1;

	Node* head = NULL;
	
	if (head1->val < head2->val)
	{
		head = head1;
		head1 = head1->next;
	}
	else
	{
		head = head2;
		head2 = head2->next;
	}

	Node* resultHead = head;

	while (head1 != NULL && head2 != NULL)
	{
		if (head1->val < head2->val)
		{
			head->next = head1;
			head = head->next;
			head1 = head1->next;
		}
		else
		{
			head->next = head2;
			head = head->next;
			head2 = head2->next;
		}
	}
	if (head1 == NULL)
		head->next = head2;
	else
		head->next = head1;

	return resultHead;
}

int main()
{
	Node* head1 = NULL;
	head1 = Insert(head1, 5);
	head1 = Insert(head1, 10);
	head1 = Insert(head1, 15);
	head1 = Insert(head1, 40);

	Node* head2 = NULL;
	head2 = Insert(head2, 2);
	head2 = Insert(head2, 3);
	head2 = Insert(head2, 20);

	Node* head = MergeLinkedLists(head1, head2);

	PrintLinkedList(head);
	return 0;
}