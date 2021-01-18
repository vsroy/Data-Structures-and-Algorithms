/*Given a Binary Tree. Check whether it is Symmetric or not, i.e. whether the binary tree is a Mirror image of itself or not.*/
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

int CheckForMirrorImage(Node* root1, Node* root2)
{
	if (root1 == NULL && root2 == NULL)
		return 1;

	if (root1 && root2 && (root1->val == root2->val))
	{
		return CheckForMirrorImage(root1->left, root2->right)
			&& CheckForMirrorImage(root1->right, root2->left);
	}
	return 0;
}

int main()
{
	return 0;
}
