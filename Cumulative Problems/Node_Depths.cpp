/*Program to find max Node depth of a tree*/
#include<iostream>
#include<algorithm>
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



int NodeDepth(node* root)
{
	if (root == NULL)
		return 0;

	return 1 + max(NodeDepth(root->left), NodeDepth(root->right));
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
	cout << NodeDepth(root);
	return 0;
}