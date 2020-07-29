/*Given two numbers represented by two linked lists of size N and M. The task is to return a sum list. 
The sum list is a linked list representation of the addition of two input numbers.*/

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

Node* newNode(int data)
{
	Node* new_node = new Node();
	new_node->val = data;
	new_node->next = NULL;
	return new_node;
}

/* Adds contents of two linked lists and
return the head node of resultant list */
Node* Add2Lists(Node* first, Node* second)
{
	// res is head node of the resultant list 
	Node* res = NULL;
	Node *temp = NULL, *prev = NULL;
	int carry = 0, sum;

	// while both lists exist 
	while (first != NULL
		|| second != NULL) {
		// Calculate value of next 
		// digit in resultant list. 
		// The next digit is sum of 
		// following things 
		// (i) Carry 
		// (ii) Next digit of first 
		// list (if there is a next digit) 
		// (ii) Next digit of second 
		// list (if there is a next digit) 
		sum = carry + (first ? first->val : 0)
			+ (second ? second->val : 0);

		// update carry for next calulation 
		carry = (sum >= 10) ? 1 : 0;

		// update sum if it is greater than 10 
		sum = sum % 10;

		// Create a new node with sum as data 
		temp = newNode(sum);

		// if this is the first node then 
		// set it as head of the resultant list 
		if (res == NULL)
			res = temp;

		// If this is not the first 
		// node then connect it to the rest. 
		else
			prev->next = temp;

		// Set prev for next insertion 
		prev = temp;

		// Move first and second 
		// pointers to next nodes 
		if (first)
			first = first->next;
		if (second)
			second = second->next;
	}

	if (carry > 0)
		temp->next = newNode(carry);

	// return head of the resultant list 
	return res;
}

int main()
{
	Node* head1 = NULL;
	head1 = Insert(head1, 1);
	head1 = Insert(head1, 2);
	head1 = Insert(head1, 3);


	Node* head2 = NULL;
	head2 = Insert(head2, 4);
	head2 = Insert(head2, 5);
	head2 = Insert(head2, 6);

	Node* res = Add2Lists(head1, head2);

	PrintLinkedList(res);

	return 0;
}