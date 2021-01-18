/*Given a binary tree, connect the nodes that are at same level. You'll be given an addition nextRight pointer for the same.*/
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

void ConnectNodesAtSameLevel(Node* root)
{
	if (root == NULL)
		return;

	queue<Node*> treeQ;
	treeQ.push(root);

	while (!treeQ.empty())
	{
		Node* temp;
		int count = treeQ.size();
		for (int i = 0; i < count; i++)
		{
			temp = treeQ.front();
			treeQ.pop();
			
			//If this the last node in the level
			if (i == count - 1)
				temp->levelRight = NULL;
			else
				temp->levelRight = treeQ.front();

			if (temp->left)
				treeQ.push(temp->left);
			if (temp->right)
				treeQ.push(temp->right);
		}
	}
}

int main()
{
	Node* root = NULL;
	root = Insert(root, 2);
	root = Insert(root, 1);
	root = Insert(root, 3);
	
	ConnectNodesAtSameLevel(root);

	return 0;
}