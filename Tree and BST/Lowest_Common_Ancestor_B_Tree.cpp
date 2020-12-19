// C++ Program for Lowest Common Ancestor in a Binary Tree
// A O(n) solution to find LCA of two given values n1 and n2

#include<iostream>
#include<vector>
using namespace std;

// A Binary Tree node
struct Node
{
	int key;
	struct Node *left, *right;
};

// Utility function creates a new binary tree node with given key
Node * newNode(int k)
{
	Node *temp = new Node;
	temp->key = k;
	temp->left = temp->right = NULL;
	return temp;
}

//Function that finds the path from root to desired node
bool FindPath(Node* root, vector<int>& path, int k)
{
	if (root == NULL)
		return false;

	//Pushing the current key for the path
	path.push_back(root->key);

	//Checking that we have reached the desired key
	if (root->key == k)
		return true;

	//Checking for left and right subtrees. If found return true;
	if ((root->left && FindPath(root->left, path, k)) || (root->right && FindPath(root->right, path, k)))
		return true;

	//Else if we have reached the leaf node wihtout finding the path, pop the element that we inserted and return false
	path.pop_back();
	return false;
}

int findLCA(Node* root, int n1, int n2)
{
	vector<int> path1, path2;

	//If either n1/n2 is absent
	if (!FindPath(root, path1, n1) || !FindPath(root, path2, n2))
		return -1;

	int i;
	for (i = 0; i < path1.size() && i < path2.size(); i++)
		if (path1[i] != path2[i])
			return path1[i - 1];
	return -1;
}

// Driver program to test above functions
int main()
{
	// Let us create the Binary Tree shown in above diagram.
	Node * root = newNode(1);
	root->left = newNode(2);
	root->right = newNode(3);
	root->left->left = newNode(4);
	root->left->right = newNode(5);
	root->right->left = newNode(6);
	root->right->right = newNode(7);
	cout << "LCA(4, 5) = " << findLCA(root, 4, 5);
	cout << "nLCA(4, 6) = " << findLCA(root, 4, 6);
	cout << "nLCA(3, 4) = " << findLCA(root, 3, 4);
	cout << "nLCA(2, 4) = " << findLCA(root, 2, 4);
	return 0;
}