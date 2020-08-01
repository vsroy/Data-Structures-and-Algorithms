/*Implement a Stack using two queues q1 and q2.*/
#include<iostream>
#include<queue>
using namespace std;

class StackUsing2Queues
{
	queue<int> q1;
	queue<int> q2;

	//We have to push in either q1 or q2 by preceedence of q1 over q2
	void Push(int x)
	{
		q1.push(x);
	}

	void Pop()
	{
		if (q1.empty())
			return;

		//Leave one element in q1 and push all others in q2
		while (q1.size() != 1)
		{
			q2.push(q1.front());
			q1.pop();
		}
		cout << "Popped Element is " << q1.front();
		q1.pop();

		/*Swap the contents of q1 and q2 so that pushing will only occur in q1 and q2 will be kept as a temporary queue*/
		queue<int> temp = q1;
		q1 = q2;
		q2 = temp;
	}

	int Top()
	{
		if (q1.empty())
		{
			cout << "\nStack is empty";
			return -1;
		}

		while (q1.size() != 1)
		{
			q2.push(q1.front());
			q1.pop();
		}
		
		int res = q1.front();
		q2.push(q1.front());
		q1.pop();

		queue<int> temp = q1;
		q1 = q2;
		q2 = temp;

		return res;
	}
};

int main()
{
	return 0;
}