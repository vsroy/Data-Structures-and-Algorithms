/*Given a binary tree, write a function to test if the tree is a binary search tree.*/
#include<iostream>
using namespace std;

/* A binary tree node has data, pointer to left
child and a pointer to right child */
struct Node
{
	int data;
	Node *left, *right;
};



// A utility function to create a node 
Node* newNode(int data)
{
	Node* temp = new Node;
	temp->data = data;
	temp->left = temp->right = NULL;
	return temp;
}

bool CheckForValidBinaryTree(Node* root, int min, int max)
{
	//Base Case. Leaf Node will always be valid as it has no left and right child
	if (root == NULL)
		return true;

	return (root->data >= min) && (root->data <= max) &&
		CheckForValidBinaryTree(root->left, min, root->data - 1) &&
		CheckForValidBinaryTree(root->right, root->data + 1, max);
}

//  Driver code to test above methods 
int main()
{
	Node* root = newNode(6);
	root->right = newNode(9);
	root->right->left = newNode(7);
	root->right->right = newNode(10);
	root->right->right->right = newNode(11);

	cout << CheckForValidBinaryTree(root, INT_MIN, INT_MAX);
	return 0;
}