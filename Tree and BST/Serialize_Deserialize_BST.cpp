/*Serialization is to store a tree in an array so that it can be later restored and Deserialization is reading tree back from the array. 
Now your task is to complete the function serialize which stores the tree into an array A[ ] and deSerialize which deserializes the array to 
tree and returns it.
Note: The structure of tree must be maintained.*/
#include<iostream>
using namespace std;
#define MARKER -1 

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

// This function stores a tree in a file pointed by fp 
void Serialize(Node* root, FILE* fp)
{
	// If current node is NULL, store marker 
	if (root == NULL)
	{
		fprintf(fp, "%d ", MARKER);
		return;
	}

	// Else, store current node and recur for its children 
	fprintf(fp, "%d ", root->val);
	Serialize(root->left, fp);
	Serialize(root->right, fp);
}

// This function constructs a tree from a file pointed by 'fp' 
void DeSerialize(Node* root, FILE* fp)
{
	// Read next item from file. If theere are no more items or next 
	// item is marker, then return
	int val;
	
	
	if (!fscanf_s(fp, "%d", &val) || val == MARKER)
		return;

	// Else create node with this item and recur for children 
	root = NewNode(val);
	DeSerialize(root->left, fp);
	DeSerialize(root->right, fp);
}

int main()
{
	return 0;
}