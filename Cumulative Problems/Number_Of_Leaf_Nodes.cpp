/*Given a Binary Tree of size N , You have to count leaves in it. For example, there are two leaves in following tree*/
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

int CountNumberOfLeafNodes(Node* root)
{
	if (root = NULL)
		return 0;

	if (root->left == NULL && root->right == NULL)
		return 1;

	return CountNumberOfLeafNodes(root->left) + CountNumberOfLeafNodes(root->right);
}

int main()
{
	return 0;
}