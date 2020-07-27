/*Given a linked list of N nodes. The task is to check if the the linked list has a loop. Linked list can contain self loop.*/
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

bool DetectLoopInLinkedList(Node* head)
{
	//Using Floyd Warshall Cycle Finding ALgorithm, we wil detect loop in a Linked List
	Node* slow = head;
	Node* fast = head;

	while (slow && fast && fast->next)
	{
		if (slow == fast)
			return true;
		slow = slow->next;
		fast = fast->next->next;
	}
	return false;
}

int main()
{

}