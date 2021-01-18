/*You are given a linked list of N nodes. The task is to remove the loop from the linked list, if present.*/

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

void RemoveLoopInALinkedList(Node* head)
{
	//First we find the node that is the start of the loop in the LL
	Node* fast = head;
	Node* slow = head;

	//First, we detect the loop in the linked list
	while (fast && slow && slow->next)
	{
		if (fast == slow)
			break;
		fast = fast->next->next;
		slow = slow->next;
	}

	//We now have fast and slow point to the start of the loop. Move the slow pointer to the head and keep the fast as it is
	//Move slow and fast until they meet
	slow = head;
	while (slow != fast)
	{
		slow = slow->next;
		fast = fast->next;
	}

	//Now slow and fast are both pointing to the same Node which is the start of the loop
	//Move the fast pointer till next of fast does not point to slow. Make the next of the fast to NULL

	while (fast->next != slow)
		fast = fast->next;

	fast->next = NULL;
}

int main()
{
	
}