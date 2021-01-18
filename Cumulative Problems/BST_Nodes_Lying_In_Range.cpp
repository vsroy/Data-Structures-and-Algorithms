/*Given a Binary Search Tree (BST) and a range, count number of nodes that lie in the given range*/
#include<iostream>
using namespace std;

// A BST node 
struct node
{
	int data;
	struct node* left, *right;
};

// Utility function to create new node 
node *newNode(int data)
{
	node *temp = new node;
	temp->data = data;
	temp->left = temp->right = NULL;
	return (temp);
}

int GetCount(node* root, int low, int high)
{
	if (root == NULL)
		return 0;
	
	if (root->data >= low && root->data <= high)
		return 1 + GetCount(root->left, low, high) + GetCount(root->right, low, high);

	else if (root->data < low)
		return GetCount(root->right, low, high);
	else
		return GetCount(root->left, low, high);
}

int main()
{
	// Let us construct the BST shown in the above figure 
	node *root = newNode(10);
	root->left = newNode(5);
	root->right = newNode(50);
	root->left->left = newNode(1);
	root->right->left = newNode(40);
	root->right->right = newNode(100);
	/* Let us constructed BST shown in above example
	10
	/    \
	5       50
	/       /  \
	1       40   100   */
	int l = 5;
	int h = 45;
	cout << "Count of nodes between [" << l << ", " << h
		<< "] is " << GetCount(root, l, h);
	return 0;
}