/*Given a Binary Tree, find diameter of it.
+The diameter of a tree is the number of nodes on the longest path between two leaves in the tree.*/
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
	return (a > b ? a : b);
}

int height(struct Node* node)
{
	/* base case tree is empty */
	if (node == NULL)
		return 0;

	/* If tree is not empty then height = 1 + max of left
	height and right heights */
	return 1 + max(height(node->left), height(node->right));
}

int Diameter(Node* root)
{
	/* base case where tree is empty */
	if (root == NULL)
		return 0;

	/* get the height of left and right sub-trees */
	int lHeight = height(root->left);
	int rHeight = height(root->right);

	/* get the diameter of left and right sub-trees */
	int lDiameter = Diameter(root->left);
	int rDiameter = Diameter(root->right);

	/* Return max of following three
	1) Diameter of left subtree
	2) Diameter of right subtree
	3) Height of left subtree + height of right subtree + 1 */
	return max(lHeight + rHeight + 1, max(lDiameter, rDiameter));
}

int main()
{
	return 0;
}