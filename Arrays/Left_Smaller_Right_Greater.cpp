/*Given an unsorted array of size N. Find the first element in array such that all of its left elements 
are smaller and all right elements to it are greater than it.
*/

#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int findElement(vector<int> ipVect)
{
	int n = ipVect.size();
	//Vectors to store the min value to the left and max value to the right for every element in the input array
	vector<int> leftMax(n,0);
	vector<int> rightMin(n,0);

	//Fill the left max array
	/*
	leftMax[0] = INT_MIN;
	for (int i = 1; i < n; i++)
		leftMax[i] = max(leftMax[i - 1], ipVect[i - 1]);
	*/

	int max_so_far = INT_MIN;
	for (int i = 0; i < n; i++)
	{
		leftMax[i] = max_so_far;
		max_so_far = max(max_so_far, ipVect[i]);
	}

	int right_min = INT_MAX;

	//Traverse the array from right
	for (int i = n - 1; i >= 0; i--)
	{
		if (leftMax[i] < ipVect[i] && ipVect[i] < right_min)
			return i;
		right_min = min(right_min, ipVect[i]);
	}
	return -1;
}

int main()
{
	vector<int> ipVect{ 5, 1, 4, 3, 6, 8, 10, 7, 9 };
	cout << findElement(ipVect);
	return 0;
}