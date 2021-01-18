/*Given that integers are being read from a data stream. Find the median of all the elements read so far starting from the first integer 
till the last integer. This is also called the Median of Running Integers. The data stream can be any source of data, 
for example, a file, an array of integers, input stream etc.*/
#include<iostream>
#include<queue>
#include<vector>
#include<functional>
using namespace std;


void PrintMedians(vector<int> arr)
{
	// max heap to store the smaller half elements 
	priority_queue<int> smaller;

	//min heap tp store the greter half elements
	priority_queue<int, vector<int>, greater<int>> greater;

	double median = arr[0];

	smaller.push(arr[0]);

	// reading elements of stream one by one 
	/*  At any time we try to make heaps balanced and
	their sizes differ by at-most 1. If heaps are
	balanced,then we declare median as average of
	min_heap_right.top() and max_heap_left.top()
	If heaps are unbalanced,then median is defined
	as the top element of heap of larger size  */
	for (int i = 1; i < arr.size(); i++)
	{
		int x = arr[i];
		//left side has more elements
		if (smaller.size() > greater.size())
		{
			if (x < median)
			{
				greater.push(smaller.top());
				smaller.pop();
				smaller.push(x);
			}
			else
				greater.push(x);

			median = (smaller.top() + greater.top()) / 2.0;
		}
		//right side has more elements
		else if (greater.size() > smaller.size())
		{
			if (x > median)
			{
				smaller.push(greater.top());
				greater.pop();
				greater.push(x);
			}
			else
				greater.push(x);

			median = (smaller.top() + greater.top()) / 2.0;
		}
		//Both sides have equal elements
		else
		{
			if (x < median)
			{
				smaller.push(x);
				median = smaller.top();
			}
			else
			{
				greater.push(x);
				median = greater.top();
			}
		}
	}
	cout << median;
}

int main()
{
	vector<int> arr{ 5, 15, 10, 20, 3 };
	PrintMedians(arr);
	return 0;
}