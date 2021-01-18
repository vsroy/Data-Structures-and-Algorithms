/*Given a binary tree, find if it is height balanced or not. 
A tree is height balanced if difference between heights of left and right subtrees is not more than one for all nodes of tree. */
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

int max(int a, int b)
{
	return (a >= b ? a : b);
}

int Height(Node* root)
{
	if (root == NULL)
		return 0;

	return (1 + max(Height(root->left), Height(root->right)));
}

int CheckForHeightBalanced(Node* root)
{
	/* If tree is empty then return true */
	if (root == NULL)
		return 1;

	/*Get the height of the left and right subtrees*/
	int leftHeight = Height(root->left);
	int rightHeight = Height(root->right);

	if (abs(leftHeight - rightHeight) <= 1 && CheckForHeightBalanced(root->left) && CheckForHeightBalanced(root->right))
		return 1;
	else
		return 0;
}

int main()
{
	return 0;
}
