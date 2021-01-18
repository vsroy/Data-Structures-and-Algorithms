/*Given a binary search tree, print out the elements of the tree in order without using recursion.*/
#include<iostream>
#include<stack>
using namespace std;

/* A binary tree Node has data, pointer to left child
and a pointer to right child */
struct Node
{
	int data;
	struct Node* left;
	struct Node* right;
	Node(int data)
	{
		this->data = data;
		left = right = NULL;
	}
};


/* Iterative function for inorder tree
traversal */
void inOrder(struct Node *root)
{
	if (root == NULL)
		return;

	stack<Node*> treeStack;

	Node* current = root;
	while (!treeStack.empty() || current != NULL)
	{
		//Reach the leftmost node of the current node
		while (current != NULL)
		{
			treeStack.push(current);
			current = current->left;
		}

		//If we reach the left most node, pop and insert right of the current
		current = treeStack.top();
		cout << current->data << " ";

		treeStack.pop();

		/* we have visited the node and its
		left subtree.  Now, it's right
		subtree's turn */
		current = current->right;
	}

}

/* Driver program to test above functions*/
int main()
{

	/* Constructed binary tree is
	1
	/   \
	2      3
	/  \
	4     5
	*/
	struct Node *root = new Node(1);
	root->left = new Node(2);
	root->right = new Node(3);
	root->left->left = new Node(4);
	root->left->right = new Node(5);

	inOrder(root);
	return 0;
}