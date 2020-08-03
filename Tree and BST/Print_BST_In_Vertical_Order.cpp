#include<iostream>
#include<map>
#include<vector>
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

// Utility function to store vertical order in map 'treeMap' 
// 'hd' is horigontal distance of current node from root. 
// 'hd' is initially passed as 0 
void PrintBSTInverticalOrderUtil(Node* root, int hd, map<int, vector<int>>& treeMap)
{
	// Base case 
	if (root == NULL)
		return;

	// Store current node in map 'm' 
	treeMap[hd].push_back(root->val);

	// Store nodes in left and right subtree 
	PrintBSTInverticalOrderUtil(root->left, hd - 1, treeMap);
	PrintBSTInverticalOrderUtil(root->right, hd + 1, treeMap);
}

void PrintBSTInverticalOrder(Node* root)
{
	// Create a map and store vertical order in map
	map<int, vector<int>> treeMap;
	PrintBSTInverticalOrderUtil(root,0,treeMap);

	map<int, vector<int>>::iterator iter;

	// Traverse the map and print nodes at every horigontal 
	// distance
	for (iter = treeMap.begin(); iter != treeMap.end(); iter++)
	{
		vector<int> tempVect = iter->second;
		for (int i = 0; i < tempVect.size(); i++)
			cout << tempVect[i];
		cout << endl;
	}
}

int main()
{
	Node* root = NULL;
	root = Insert(root, 10);
	root = Insert(root, 20); 
	root = Insert(root, 30); 
	root = Insert(root, 40);
	root = Insert(root, 50);

	PrintBSTInverticalOrder(root);

	return 0;
}