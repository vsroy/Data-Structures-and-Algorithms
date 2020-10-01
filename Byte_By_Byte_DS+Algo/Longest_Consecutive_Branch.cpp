/*Given a tree, write a function to find the length of the longest branch of nodes in increasing consecutive order.*/
#include <iostream>
#include <algorithm>
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

void longestConsecutiveUtil(Node* root, int expected, int& result, int length)
{
	if (root == NULL)
		return;

	if (root->data == expected)
		length += 1;
	else
		length = 1;

	//Update the result
	result = max(length, result);
		
	//Recur for left and right subtrees with expectation more than the value of the current root data
	longestConsecutiveUtil(root->left, root->data + 1, result, length);

	longestConsecutiveUtil(root->right, root->data + 1, result, length);
}

int longestConsecutive(Node* root)
{
	if (root == NULL)
		return 0;

	int result = 0;
	longestConsecutiveUtil(root, 0, result, 0);

	return result;
}

//  Driver code to test above methods 
int main()
{
	Node* root = newNode(6);
	root->right = newNode(9);
	root->right->left = newNode(7);
	root->right->right = newNode(10);
	root->right->right->right = newNode(11);

	printf("%d\n", longestConsecutive(root));
	return 0;
}