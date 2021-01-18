/*Complete the function to print spiral order traversal of a tree.*/
#include<iostream>
#include<stack>
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

void PrintLevelOrderTraversalSpiral(Node* root)
{
	if (root == NULL)
		return;

	stack<Node*> s1;
	stack<Node*> s2;

	s1.push(root);
	
	//Either of the stacks must have some data in it
	while (!s1.empty() || !s2.empty())
	{
		while (!s1.empty())
		{
			Node* temp = s1.top();
			cout << temp->val << " ";

			//We put right first as next level is even
			if (temp->right)
				s2.push(temp->right);
			//We put left next
			if (temp->left)
				s2.push(temp->left);

			s1.pop();
		}

		while (!s2.empty())
		{
			Node* temp = s2.top();
			cout << temp->val << " ";

			//We put left first as next level is odd
			if (temp->left)
				s1.push(temp->left);

			//Then we put right
			if (temp->right)
				s1.push(temp->right);

			s2.pop();
		}
	}
}

int main()
{
	Node* root = NULL;
	root = Insert(root, 1);
	root = Insert(root, 8);
	root = Insert(root, 4);
	root = Insert(root, 7);
	root = Insert(root, 9);
	root = Insert(root, 5);

	PrintLevelOrderTraversalSpiral(root);

	return 0;
}