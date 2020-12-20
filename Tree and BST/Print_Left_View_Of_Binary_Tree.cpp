/*Given a Binary Tree, print Left view of it. Left view of a Binary Tree is set of nodes visible when tree is visited from Left side. 
The task is to complete the function leftView(), which accepts root of the tree as argument.*/

#include<iostream>
using namespace std;

struct Node
{
	Node* left;
	Node* right;
	int val;
};

Node* NewNode(int x)
{
	Node* temp = new Node;
	temp->left = NULL;
	temp->right = NULL;
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

void PrintLeftViewUtil(Node* root, int level, int& maxLevel)
{
	//Base Case
	if (root == NULL)
		return;

	if (maxLevel < level)
	{
		cout << root->val << " ";	//This is occur when current element is the first node in the level
		maxLevel = level;
	}

	PrintLeftViewUtil(root->left, level + 1, maxLevel);
	PrintLeftViewUtil(root->right, level + 1, maxLevel);
}

void PrintLeftViewOfBST(Node* root)
{
	int maxLevel = 0;
	PrintLeftViewUtil(root, 1, maxLevel);
}

int main()
{
	Node* root = NULL;
	root = Insert(root, 50);
	root = Insert(root, 20);
	root = Insert(root, 30);
	root = Insert(root, 40);
	root = Insert(root, 70);
	root = Insert(root, 60);
	root = Insert(root, 80);
	
	PrintInOrderBST(root);
	cout << endl;
	PrintLeftViewOfBST(root);

	return 0;
}