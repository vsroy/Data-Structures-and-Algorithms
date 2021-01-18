/*You are given N elements and your task is to Implement a Stack in which you can get minimum element in O(1) time.*/
#include<iostream>
#include<stack>
using namespace std;

class StackMin
{
	stack<int> s1;
	int minElement;

public:
	void GetMin()
	{
		if (s1.empty())
			cout << "\nStack is empty";
		else
			cout << "Min Element from stack is " << minElement << "\n";
	}

	void Top()
	{
		if (s1.empty())
			cout << "\nStack is empty";
		else
		{
			int top = s1.top();
			if (top < minElement)
				cout << "Top is " << minElement;
			else
				cout << "Top is " << top;
		}
	}

	void Pop()
	{
		if (s1.empty())
		{
			cout << "Stack is empty";
			return;
		}

		if (s1.top() < minElement)
		{
			int y = s1.top();
			s1.pop();
			minElement = 2 * minElement - y;
		}
		else
			s1.pop();
	}

	void Push(int x)
	{
		if (s1.empty())
		{
			s1.push(x);
			minElement = x;
			return;
		}

		if (x < minElement)
		{
			s1.push(2 * x - minElement);
			minElement = x;
		}
		else
			s1.push(x);
	}
};

int main()
{
	return 0;
}