/*Given an unsorted linked list, write a function to remove all the duplicates.*/
#include<iostream>
using namespace std;

/* Link list node */
struct Node {
	int data;
	struct Node* next;
};

void push(struct Node** head_ref, int new_data)
{
	/* allocate node */
	struct Node* new_node = new Node;

	/* put in the data  */
	new_node->data = new_data;

	/* link the old list off the new node */
	new_node->next = (*head_ref);

	/* move the head to point to the new node */
	(*head_ref) = new_node;
}

// Returns true if there is a loop in linked list
// else returns false.
bool detectLoop(struct Node* h)
{
	//Using Floyd Warshall Cycle Detection Algorithm
	Node* fast = h;
	Node* slow = h;

	while (slow && fast && fast->next)
	{
		if (slow == fast)
			return true;
		slow = slow->next;
		fast = fast->next;
	}
	return false;
}

void RemoveDuplicates(Node *head)
{
	Node* current = head;

	Node* next_next;

	if (current == NULL)
		return;

	while (current->next != NULL)
	{
		if (current->next->data == current->data)
		{
			next_next = current->next->next;
			delete current->next;
			current->next = next_next;
		}
		else
			current = current->next;
	}
}

/* Driver program to test above function*/
int main()
{
	/* Start with the empty list */
	struct Node* head = NULL;

	push(&head, 20);
	push(&head, 4);
	push(&head, 15);
	push(&head, 10);

	/* Create a loop for testing */
	head->next->next->next->next = head;

	if (detectLoop(head))
		cout << "Loop found";
	else
		cout << "No Loop";

	return 0;
}