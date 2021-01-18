/*Given a binary tree, where every node value is a Digit from 1-9 .Find the sum of all the numbers which are formed from root to leaf paths.*/
#include<iostream>
using namespace std;

class node
{
public:
	int data;
	node *left, *right;
};

// function to allocate new node with given data  
node* newNode(int data)
{
	node* Node = new node();
	Node->data = data;
	Node->left = Node->right = NULL;
	return (Node);
}

// Returns sum of all root to leaf paths. 
// The first parameter is root  
// of current subtree, the second  
// parameter is value of the number formed  
// by nodes from root to this node  
void treePathsSumUtil(node *root, int val)
{
	if (root == NULL)
		return;

	val = val * 10 + root->data;

	//If it is a leaf node, we print the value
	if (root->left == NULL && root->right == NULL)
		cout << val << " ";

	else
	{
		treePathsSumUtil(root->left, val);
		treePathsSumUtil(root->right, val);
	}
}

// A wrapper function over treePathsSumUtil()  
void treePathsSum(node *root)
{
	treePathsSumUtil(root, 0);
}

// Driver code 
int main()
{
	node *root = newNode(6);
	root->left = newNode(3);
	root->right = newNode(5);
	root->left->left = newNode(2);
	root->left->right = newNode(5);
	root->right->right = newNode(4);
	root->left->right->left = newNode(7);
	root->left->right->right = newNode(4);
	//cout << "Sum of all paths is " << treePathsSum(root);
	treePathsSum(root);
	return 0;
}