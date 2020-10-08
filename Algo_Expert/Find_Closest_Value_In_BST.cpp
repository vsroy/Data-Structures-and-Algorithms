/*Program to find closest value to particular numebr in BST*/
#include<iostream>
using namespace std;

/* A binary tree node has key, pointer to left child
and a pointer to right child */
struct Node
{
	int key;
	struct Node* left, *right;
};

/* Utility that allocates a new node with the
given key and NULL left and right pointers. */
struct Node* newnode(int key)
{
	struct Node* node = new (struct Node);
	node->key = key;
	node->left = node->right = NULL;
	return (node);
}

// Function to find node with minimum absolute 
// difference with given K 
// min_diff   --> minimum difference till now 
// min_diff_key  --> node having minimum absolute 

void maxDiffUtil(Node *ptr, int k, int &min_diff, int &min_diff_key)
{
	if (ptr == NULL)
		return;
	
	// If k itself is present 
	if (ptr->key == k)
	{
		min_diff = 0;
		min_diff_key = ptr->key;
		return;
	}

	// update min_diff and min_diff_key by checking 
	// current node value 
	int abs_val = abs(ptr->key - k);
	if (abs_val < min_diff)
	{
		min_diff = abs_val;
		min_diff_key = ptr->key;
	}

	// if k is less than ptr->key then move in 
	// left subtree else in right subtree 
	if (k < ptr->key)
		maxDiffUtil(ptr->left, k, min_diff, min_diff_key);
	else
		maxDiffUtil(ptr->right, k, min_diff, min_diff_key);
}

// Wrapper over maxDiffUtil() 
void maxDiff(Node *root, int k)
{
	int min_diff = INT_MAX;
	int min_diff_key = -1;

	maxDiffUtil(root, k, min_diff, min_diff_key);
	cout << "Min Diff = " << min_diff << " and min key = " << min_diff_key;
}

// Driver program to run the case 
int main()
{
	struct Node *root = newnode(9);
	root->left = newnode(4);
	root->right = newnode(17);
	root->left->left = newnode(3);
	root->left->right = newnode(6);
	root->left->right->left = newnode(5);
	root->left->right->right = newnode(7);
	root->right->right = newnode(22);
	root->right->right->left = newnode(20);
	int k = 18;
	maxDiff(root, k);
	return 0;
}