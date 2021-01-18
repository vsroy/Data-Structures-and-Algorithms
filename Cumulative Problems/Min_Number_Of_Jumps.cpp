/*Given an array of integers where each element represents the max number of steps that can be made forward from that element. 
Write a function to return the minimum number of jumps to reach the end of the array (starting from the first element). 
If an element is 0, they cannot move through that element.*/
#include<iostream>
#include<vector>
using namespace std;

int MinJumps(vector<int> arr)
{
	//jumps[0] will hold the result
	int n = arr.size();
	vector<int> jumps(n, 0);

	int min;

	// Minimum number of jumps needed 
	// to reach last element from last 
	// elements itself is always 0 
	jumps[n - 1] = 0;

	// Start from the second element, 
	// move from right to left and 
	// construct the jumps[] array where 
	// jumps[i] represents minimum number 
	// of jumps needed to reach 
	// arr[m-1] from arr[i] 
	for (int i = n - 1; i >= 0; i--)
	{
		// If arr[i] is 0 then arr[n-1] 
		// can't be reached from here
		if (arr[i] == 0)
			jumps[i] = INT_MAX;

		// If we can direcly reach to 
		// the end point from here then 
		// jumps[i] is 1 
		if (arr[i] >= n - 1 - i)
			jumps[i] = 1;

		// Otherwise, to find out the minimum 
		// number of jumps needed to reach 
		// arr[n-1], check all the points 
		// reachable from here and jumps[] 
		// value for those points 
		else
		{
			// initialize min value 
			min = INT_MAX;

			// following loop checks with all 
			// reachable points and takes 
			// the minimum 
			for (int j = i + 1; j < n && j <= arr[i] + i; j++)
			{
				if (jumps[i] < min)
					min = jumps[i];
			}	

			// Handle overflow 
			if (min != INT_MAX)
				jumps[i] = min + 1;
			else
				jumps[i] = min;
		}
	}
	return jumps[0];
}
int main()
{
	vector<int> arr{ 1, 3, 6, 1, 0, 9 };
	cout << MinJumps(arr);
	return 0;
}