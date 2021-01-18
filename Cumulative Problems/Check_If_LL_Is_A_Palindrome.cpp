/*Given a singly linked list of size N of integers. The task is to check if the given linked list is palindrome or not.*/
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

/* Function to reverse the linked list  Note that this
function may change the head */
void reverse(struct Node** head_ref)
{
	struct Node* prev = NULL;
	struct Node* current = *head_ref;
	struct Node* next;
	while (current != NULL) {
		next = current->next;
		current->next = prev;
		prev = current;
		current = next;
	}
	*head_ref = prev;
}

/* Function to check if two input lists have same data*/
bool compareLists(struct Node* head1, struct Node* head2)
{
	struct Node* temp1 = head1;
	struct Node* temp2 = head2;

	while (temp1 && temp2) {
		if (temp1->val == temp2->val) {
			temp1 = temp1->next;
			temp2 = temp2->next;
		}
		else
			return 0;
	}

	/* Both are empty reurn 1*/
	if (temp1 == NULL && temp2 == NULL)
		return 1;

	/* Will reach here when one is NULL
	and other is not */
	return 0;
}

bool CheckLinkedListIsPalindrome(Node* head)
{
	Node* slow = head, *fast = head;
	Node* prev_slow = head, *second_half = head;
	Node* midNode = NULL;	//To handle odd list
	bool res = true;

	if (head != NULL && head->next != NULL)
	{
		while (fast && fast->next)
		{
			/* Get the middle of the list. Move slow_ptr by 1
			and fast_ptrr by 2, slow_ptr will have the middle
			node */
			fast = fast->next;
			/*We need previous of the slow_ptr for
			linked lists  with odd elements */
			prev_slow = slow;
			slow = slow->next;
		}

		/* fast_ptr would become NULL when there are even elements in list.
		And not NULL for odd elements. We need to skip the middle node
		for odd case and store it somewhere so that we can restore the
		original list*/
		if (fast != NULL)
		{
			midNode = slow;
			slow = slow->next;
		}

		// Now reverse the second half and compare it with first half 
		second_half = slow;
		prev_slow->next = NULL;
		reverse(&second_half);
		res = compareLists(head, second_half);

		/* Construct the original list back */
		reverse(&second_half);

		// If there was a mid node (odd size case) which 
		// was not part of either first half or second half
		if (!midNode)
		{
			prev_slow->next = midNode;
			midNode->next = second_half;
		}
		else
			prev_slow->next = second_half;
	}
	return res;
}

int main()
{

}