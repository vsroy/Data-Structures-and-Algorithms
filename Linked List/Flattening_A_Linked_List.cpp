/*Given a Linked List of size N, where every node represents a linked list and contains two pointers of its type:
(i) a next pointer to the next node,
(ii) a bottom pointer to a linked list where this node is head.
You have to flatten the linked list to a single linked list which should be sorted.*/

#include<iostream>
using namespace std;

// A Linked List Node 
typedef struct Node
{
	int data;
	struct Node *right;
	struct Node *down;
} Node;

/* A utility function to insert a new node at the beginning
of linked list */
void push(Node** head_ref, int new_data)
{
	/* allocate node */
	Node* new_node = (Node *)malloc(sizeof(Node));
	new_node->right = NULL;

	/* put in the data  */
	new_node->data = new_data;

	/* link the old list off the new node */
	new_node->down = (*head_ref);

	/* move the head to point to the new node */
	(*head_ref) = new_node;
}

/* Function to print nodes in the flattened linked list */
void printList(Node *node)
{
	while (node != NULL)
	{
		printf("%d ", node->data);
		node = node->down;
	}
}

Node* Merge(Node* a, Node* b)
{
	//If first list/second list is empty, return the other list
	if (a == NULL)
		return b;

	if (b == NULL)
		return a;

	//Compare the data members of both the lists and put the smaller one in result
	Node* result;
	if (a->data < b->data)
	{
		result = a;
		result->down = Merge(a->down, b);
	}
	else
	{
		result = b;
		result->down = Merge(a, b->down);
	}
	result->right = NULL;
	return result;
}

Node* FlattenLinkedList(Node* head)
{
	//Base Case
	if (head == NULL || head->right == NULL)
		return head;

	//Merge this list with the list on the right side
	return Merge(head, head->right);
}

int main()
{

}