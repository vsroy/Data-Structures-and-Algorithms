/*Implement a binary tree with a method getRandomNode() that returns a random node.*/
#include<iostream>
using namespace std;

struct Node
{
	int data;
	int children;
	Node* left;
	Node* right;
};

Node* newNode(int data)
{
	Node* temp = new Node;
	temp->data = data;
	temp->left = temp->right = NULL;
	temp->children = 0;
	return temp;
}

//This root is used to fill children counts
int GetElements(Node* root)
{
	if (root == NULL)
		return 0;
	return GetElements(root->left) + GetElements(root->right) + 1;
}

//Inserts children count for each node
void InsertChildrenCount(Node*& root)
{
	if (!root)
		return;
	root->children = GetElements(root) - 1;
	InsertChildrenCount(root->left);
	InsertChildrenCount(root->right);
}


// returns number of children for root 
int Children(Node* root)
{
	if (!root)
		return 0;
	return root->children + 1;
}

// Helper Function to return a random node 
int RandomNodeUtil(Node* root, int count)
{
	if (!root)
		return 0;

	if (count == Children(root->left))
		return root->data;

	if (count < Children(root->left))
		return RandomNodeUtil(root->left,count);

	return RandomNodeUtil(root->right, count - Children(root->left) - 1);
}

int randomNode(Node* root)
{

	int count = rand()%root->children + 1;
	return RandomNodeUtil(root, count);
}

int main()
{
	// Creating Above Tree 
	Node* root = newNode(10);
	root->left = newNode(20);
	root->right = newNode(30);
	root->left->right = newNode(40);
	root->left->right = newNode(50);
	root->right->left = newNode(60);
	root->right->right = newNode(70);

	InsertChildrenCount(root);

	cout << "A Random Node From Tree : "
		<< randomNode(root) << endl;

	return 0;
}