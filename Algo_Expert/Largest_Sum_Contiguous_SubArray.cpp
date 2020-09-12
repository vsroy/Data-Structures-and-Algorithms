/*Write an efficient program to find the sum of contiguous subarray within a one-dimensional array of numbers which has the largest sum.*/
#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int MaxSubArraySum(vector<int> arr)
{
	int curMax = arr[0];
	int max_so_far = arr[0];

	for (int i = 0; i < arr.size(); i++)
	{
		curMax = max(arr[i], curMax + arr[i]);
		max_so_far = max(curMax, max_so_far);
	}
	return max_so_far;
}

int main()
{
	vector<int> arr{ -2, -3, 4, -1, -2, 1, 5, -3 };
	cout << MaxSubArraySum(arr);
	return 0;
}