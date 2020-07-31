/*Implement a Queue using 2 stacks s1 and s2 .*/
#include<iostream>
#include<stack>
using namespace std;

class QUsing2Stacks
{
	stack<int> s1;
	stack<int> s2;
public:
	//Always pop from stack 1
	void Pop()
	{
		if (s1.empty() && s2.empty())
		{
			cout << "Queue is empty";
			return;
		}
		
		if (s1.empty())
		{
			while (!s2.empty())
			{
				s1.push(s2.top());
				s2.pop();
			}
		}
		s1.pop();
	}

	//Always push in stack 2
	void Push(int x)
	{
		s2.push(x);
	}

	//Make sure 2 is empty before printing
	void PrintQ()
	{
		if (s1.empty() && s2.empty())
		{
			cout << "Queue is empty";
			return;
		}

		if (s1.empty())
		{
			while (!s2.empty())
			{
				s1.push(s2.top());
				s2.pop();
			}
		}

		while (!s1.empty())
		{
			s2.push(s1.top());
			s1.pop();
		}

		while (s2.empty())
		{
			cout << s2.top() << " ";
			s1.push(s2.top());
			s2.pop();
		}
	}
};

int main()
{

}