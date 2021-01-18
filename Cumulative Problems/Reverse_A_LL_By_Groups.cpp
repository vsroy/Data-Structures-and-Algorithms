/*Given a linked list of size N. The task is to reverse every k nodes (where k is an input to the function) in the linked list.*/

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

Node* ReverseLinkedListsByGroups(Node* head, int k)
{
	int counter = 0;
	Node* current = head;
	Node* prev = NULL;
	Node* next = NULL;

	/*reverse first k nodes of the linked list */
	while (current != NULL && counter < k)
	{
		next = current->next;
		current->next = prev;
		prev = current;
		current = next;
		counter++;
	}

	/*next is a pointer to k+1th node. Recursively call from the next node onwards*/
	if (next != NULL)
	head->next = ReverseLinkedListsByGroups(next, k);
	
	return prev;
}

int main()
{
	Node* head = NULL;
	head = Insert(head, 1);
	Insert(head, 2);
	Insert(head, 3);
	Insert(head, 4);
	Insert(head, 5);
	Insert(head, 6);
	Insert(head, 7);
	Insert(head, 8);

	PrintLinkedList(head);

	head = ReverseLinkedListsByGroups(head, 4);
	
	PrintLinkedList(head);

	return 0;
}