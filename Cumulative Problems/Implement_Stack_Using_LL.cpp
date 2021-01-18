/*You have a linked list and you have to implement the functionalities push and pop of stack using this given linked list.*/
#include<iostream>
using namespace std;

struct StackNode
{
	StackNode* next;
	int val;
	StackNode(int x)
	{
		next = NULL;
		val = x;
	}
};

class Stack
{
public:
	StackNode* topNode;
	Stack()
	{
		topNode = NULL;
	}

	void Push(int x)
	{
		//If stack is empty
		if (topNode == NULL)
			topNode = new StackNode(x);
		else
		{
			StackNode* temp = new StackNode(x);
			temp->next = topNode;
			topNode = temp;
		}
	}

	void Pop()
	{
		//If stack is empty
		if (topNode == NULL)
			return;
		else
		{
				StackNode* temp = topNode;
				topNode = topNode->next;
				delete temp;
		}
	}

	int Top()
	{
		if (topNode == NULL)
		{
			cout << "\nStack is empty";
			return -1;
		}
		return topNode->val;
	}
};

int main()
{
	Stack s;
	s.Push(11);
	s.Push(22);
	s.Push(33);
	s.Push(44);

	cout << "\nTop element is " << s.Top();

	s.Pop();
	s.Pop();

	cout << "\nTop element is " << s.Top();

	s.Pop();
	s.Pop();

	cout << "\nTop element is " << s.Top();

	return 0;
}