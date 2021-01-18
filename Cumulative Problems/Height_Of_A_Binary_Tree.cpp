/*Given a binary tree, find its height.*/
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

int HeightOfABinaryTree(Node* root)
{
	if (root == NULL)
		return 0;

	int leftHeight = HeightOfABinaryTree(root->left);
	int rightHeight = HeightOfABinaryTree(root->right);

	if (leftHeight > rightHeight)
		return 1 + leftHeight;
	else
		return 1 + rightHeight;

	/*Alternate solution
	return 1 + max(HeightOfABinaryTree(root->left), HeightOfABinaryTree(root->right));
	*/
}

int main()
{
	return 0;
}