/*Given an array A of size N having distinct elements, the task is to find the next greater element for each element of the 
array in order of their appearance in the array. If no such element exists, output -1 */

#include<iostream>
#include<stack>
#include<vector>
using namespace std;

void PrintNextGreaterElement(vector<int> ipVect)
{
	stack<int> tempStack;  
	/* push the first element to stack */
	tempStack.push(ipVect[0]);

	// iterate for rest of the elements 
	for (int i = 1; i < ipVect.size(); i++)
	{
		if (tempStack.empty())
		{
			tempStack.push(ipVect[i]);
			continue;
		}

		/* if stack is not empty, then
		pop an element from stack.
		If the popped element is smaller
		than next, then
		a) print the pair
		b) keep popping while elements are
		smaller and stack is not empty */
		while (!tempStack.empty() && tempStack.top() < ipVect[i])
		{
			cout << tempStack.top() << " ---> " << ipVect[i] << endl;
			tempStack.pop();
		}

		/* push next to stack so that we can find
		next greater for it */
		tempStack.push(ipVect[i]);
	}

	/* After iterating over the loop, the remaining
	elements in stack do not have the next greater
	element, so print -1 for them */
	while (!tempStack.empty())
	{
		cout << tempStack.top() << " ---> -1" << endl;
		tempStack.pop();
	}
}

int main()
{
	vector<int> ipVect{ 11, 13, 21, 3 };
	PrintNextGreaterElement(ipVect);
	return 0;
}