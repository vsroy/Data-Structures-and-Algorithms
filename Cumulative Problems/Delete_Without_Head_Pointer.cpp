/*You are given a pointer/ reference to the node which is to be deleted from the linked list of N nodes. 
The task is to delete the node. Pointer/ reference to head node is not given.*/
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

void Convert0s1s2s(Node* temp)
{
	if (temp == NULL)
	{
		cout << "List is empty";
		return;
	}
	if (temp->next == NULL)
	{
		cout << "Last node in the list, cannot be freed, require head";
		return;
	}
	else
	{
		Node* temp2 = temp->next;
		temp->val = temp2->val;
		temp->next = temp2->next;
		delete temp2;
	}
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

	PrintLinkedList(head);

	return 0;
}
