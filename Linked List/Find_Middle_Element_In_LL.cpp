/*Given a singly linked list of N nodes. The task is to find the middle of the linked list. 
For example, if given linked list is 1->2->3->4->5 then the output should be 3.*/
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

int PrintMiddleElement(Node* head)
{
	Node* first = head;
	Node* second = head;

	while (second != NULL && second->next != NULL)
	{
		second = second->next->next;
		first = first->next;
	}
	return first->val;
}

int main()
{
	Node* head = NULL;
	head = Insert(head, 1);
	Insert(head, 2);
	Insert(head, 3);
	Insert(head, 4);
	Insert(head, 5);
	//Insert(head, 6);

	PrintLinkedList(head);

	cout << PrintMiddleElement(head);

	return 0;
}