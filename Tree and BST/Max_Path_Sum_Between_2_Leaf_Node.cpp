/*Given a binary tree in which each node element contains a number. Find the maximum possible sum from one leaf node to another.*/
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

// Utility function to find maximum of two integers 
int max(int a, int b)
{
	return (a >= b) ? a : b;
}

int FindMaxPathSum(Node* root, int& res)
{
	//Base Case
	if (root == NULL)
		return 0;

	//Leaf Node
	if (!root->left && !root->right)
		return root->val;

	// Find maximum sum in left and right subtree. Also 
	// find maximum root to leaf sums in left and right 
	// subtrees and store them in leftVal and rightVal 
	int leftVal = FindMaxPathSum(root->left, res);
	int rightVal = FindMaxPathSum(root->right, res);

	//if both left and right children exists
	if (root->left && root->right)
	{
		//Update result if needed
		res = max(res, leftVal + rightVal + root->val);

		// Return maxium possible value for root being 
		// on one side 
		return max(leftVal, rightVal) + root->val;
	}
	
	// If any of the two children is empty, return 
	// root sum for root being on one side 
	return (!root->left) ? rightVal + root->val : leftVal + root->val;
}

int main()
{
	return 0;
}