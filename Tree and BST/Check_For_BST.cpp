/*Given a binary tree. Check whether it is a BST or not.*/
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

/* Returns true if the given
tree is a BST and its values
are >= min and <= max. */
int CheckForBSTUtil(Node* root, int minLimit, int maxLimit)
{
	if (root == NULL)
		return 1;

	//We return a false value if it violates the minimum and maximum condition
	if (root->val < minLimit || root->val > maxLimit)
		return 0;

	//We do an AND operation of validity of left and right subtrees
	return (CheckForBSTUtil(root->left, minLimit, root->val-1) && 
		    CheckForBSTUtil(root->right,root->val+1,maxLimit));
}

/* Returns true if the given
tree is a binary search tree
(efficient version). */
int CheckForBST(Node* root)
{
	return CheckForBSTUtil(root, INT_MIN, INT_MAX);
}

int main()
{

}