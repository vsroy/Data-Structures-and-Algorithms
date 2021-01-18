/*Given a stack, sort the elements in the stack using one additional stack.*/
#include<iostream>
#include<stack>
using namespace std;

void SortStack(stack<int> ipStack)
{
	if (ipStack.empty())
		cout << "Nothing to sort";

	//Create a temporary stack
	stack<int> tempStack;

	while (!ipStack.empty())
	{
		//Get the top of ipStack
		int temp = ipStack.top();
		ipStack.pop();

		//Keep popping greater elements from temp stack till we get a smaller element and then push it
		while (!tempStack.empty() && tempStack.top() > temp)
		{
			ipStack.push(tempStack.top());
			tempStack.pop();
		}
		tempStack.push(temp);
	}

	//The sorted elements will be in the temp stack
	while (!tempStack.empty())
	{
		cout << tempStack.top() << " ";
		tempStack.pop();
	}
}

int main()
{
	stack<int> ipStack;
	ipStack.push(34);
	ipStack.push(3);
	ipStack.push(31);
	ipStack.push(98);
	ipStack.push(92);
	ipStack.push(23);

	SortStack(ipStack);

	return 0;
}