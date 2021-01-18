/*Given a Binary Tree (BT), convert it to a Doubly Linked List(DLL) In-Place. The left and right pointers in nodes are to be 
used as previous and next pointers respectively in converted DLL. The order of nodes in DLL must be same as Inorder of the given Binary Tree. 
The first node of Inorder traversal (leftmost node in BT) must be the head node of the DLL.*/

#include<iostream>
using namespace std;

struct Node
{
	Node* left;
	Node* right;
	Node* levelRight;
	int val;
};

Node* NewNode(int x)
{
	Node* temp = new Node;
	temp->left = NULL;
	temp->right = NULL;
	temp->levelRight = NULL;
	temp->val = x;
	return temp;
}

Node* Insert(Node* root, int x)
{
	if (root == NULL)
		return NewNode(x);

	if (x < root->val)
		root->left = Insert(root->left, x);
	else
		root->right = Insert(root->right, x);

	return root;
}

void PrintInOrderBST(Node* root)
{
	if (root == NULL)
		return;

	PrintInOrderBST(root->left);
	cout << root->val << " ";
	PrintInOrderBST(root->right);
}

void ConvertToDoublyLinkedList(Node* root, Node** head)
{
	//Base Case
	if (root == NULL)
		return;

	// Initialize previously visited node as NULL. This is 
	// static so that the same value is accessible in all recursive 
	// calls 
	static Node* prev = NULL;

	//Recursively convert left subtree
	ConvertToDoublyLinkedList(root->left, head);

	//If this is the first node, head of the Linked List is root
	if (prev == NULL)
		*head = root;
	else
	{
		root->left = prev;
		prev->right = root;
	}
	prev = root;

	//Recursively convert right subtree
	ConvertToDoublyLinkedList(root->right, head);
}

int main()
{
	Node* root = NULL;
	root = Insert(root, 10);
	root = Insert(root, 20);
	root = Insert(root, 30);
	root = Insert(root, 40);
	root = Insert(root, 50);

	Node* head = NULL;

	ConvertToDoublyLinkedList(head,&root);

	return 0;
}