/*Program to implement DFS in BST*/
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


void DFS(node* root)
{
	if (root == NULL)
		return;

	DFS(root->left);
	cout << root->data << " ";
	DFS(root->right);
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
	DFS(root);
	return 0;
}