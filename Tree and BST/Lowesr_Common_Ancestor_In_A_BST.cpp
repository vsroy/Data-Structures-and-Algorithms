/*Given a Binary Search Tree (with all values unique) and two node values. Find the Lowest Common Ancestors of the two nodes in the BST.*/
#include<iostream>
#include<queue>
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

Node* LowestCommonAncestor(Node* root, int x1, int x2)
{
	if (root == NULL)
		return NULL;

	//if both x1 and x2 are smaller than current value of node, then we have to travel to left subtree to find LCA
	if (x1 < root->val && x2 < root->val)
		return LowestCommonAncestor(root->left, x1, x2);
	
	//if both x1 and x2 are greater than current value of node, then we have to travel to right subtree to find LCA
	if (x1 > root->val && x2 > root->val)
		return LowestCommonAncestor(root->right, x1, x2);
	
	return root;
}

int main()
{
	return 0;
}