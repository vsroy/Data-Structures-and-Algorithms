/*Given a binary tree. Check whether it is a BST or not.*/
#include<iostream>
#include<queue>
#include<map>
using namespace std;

struct Node
{
	Node* left;
	Node* right;
	int val;
	int hd = 0;
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

void PrintBottomViewOfBST(Node* root)
{
	//Base Case
	if (root == NULL)
		return;

	queue<Node*> tempQ;
	map<int, int> treeMap;

	root->hd = 0;
	tempQ.push(root);

	while (!tempQ.empty())
	{
		Node* temp = tempQ.front();
		tempQ.pop();
		
		treeMap[temp->hd] = temp->val;

		if (temp->left)
		{
			temp->left->hd = temp->hd - 1;
			tempQ.push(temp->left);
		}

		if (temp->right)
		{
			temp->right->hd = temp->hd + 1;
			tempQ.push(temp->right);
		}
	}
	
	map<int, int>::iterator it;
	for (it = treeMap.begin(); it != treeMap.end(); it++)
	{
		cout << it->second << " ";
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
	root = Insert(root, 60);

	PrintInOrderBST(root);
	cout << endl;
	PrintBottomViewOfBST(root);
	return 0;
}