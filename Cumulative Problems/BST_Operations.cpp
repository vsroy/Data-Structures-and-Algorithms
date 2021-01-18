/*BST Operations*/
#include<iostream>
#include<algorithm>
using namespace std;

struct Node
{
	Node* left;
	Node* right;
	int val;
};

Node* NewNode(int x)
{
	Node* newNode =  new Node;
	newNode->left = NULL;
	newNode->right = NULL;
	newNode->val = x;
	return newNode;
}

//Insertion of a node in a tree
Node* InsertNode(Node* root, int x)
{
	if(root == NULL)
		return NewNode(x);
	if(x < root->val)
		root->left = InsertNode(root->left, x);
	else if(x > root->val)
		root->right = InsertNode(root->right, x);
	return root;
}

//Will print sorted contents of BST
void PrintInOrder(Node* root)
{
	if(root == NULL)
		return;
	PrintInOrder(root->left);
	cout << root->val << " ";
	PrintInOrder(root->right);
}

bool ValidateBSTUtil(Node* root, int minVal, int maxVal)
{
	if(root == NULL)
		return 1;
	if(root->val < minVal || root->val > maxVal)
		return 0;
	else
		return ValidateBSTUtil(root->left,minVal,root->val-1) && ValidateBSTUtil(root->right,root->val+1,maxVal);
}

//Validate a BST
bool ValidateBST(Node* root)
{
	return ValidateBSTUtil(root, INT_MIN, INT_MAX);
}

int MinHeight(Node* root)
{
	if (root == NULL)
		return 0;

	if (root->left == NULL && root->right == NULL)
		return 1;
	
	if (!root->left)
		return MinHeight(root->left) + 1;

	if (!root->right)
		return MinHeight(root->right) + 1;

	return min(MinHeight(root->left), MinHeight(root->right)) + 1;
}

void InvertBinaryTree(Node* root)
{
	if(root == NULL)
		return;

	else
	{	
		Node* temp;

		//Recursively call the subtrees
		InvertBinaryTree(root->left);
		InvertBinaryTree(root->right);

		//Swap the pointers in the node
		temp = root->left;
		root->left = root->right;
		root->right = temp;
	}
}

int main()
{
	Node* root = NULL;
	root = InsertNode(root, 6);
	InsertNode(root, 4);
	InsertNode(root, 9);
	InsertNode(root, 7);
	InsertNode(root, 10);
	InsertNode(root, 1);

	PrintInOrder(root);

	cout << endl << ValidateBST(root);
	return 0;
}