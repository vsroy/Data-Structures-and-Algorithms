/*Given an array of n positive integers. Write a program to find the sum of maximum sum subsequence of the given array such that the integers 
in the subsequence are sorted in increasing order. For example, if input is {1, 101, 2, 3, 100, 4, 5}, then output should be 106 (1 + 2 + 3 + 100), 
if the input array is {3, 4, 5, 10}, then output should be 22 (3 + 4 + 5 + 10) and if the input array is {10, 5, 4, 3}, then output should be 10*/
#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int MaxSumIncreasingSub(vector<int>& arr)
{
	int n = arr.size();

	vector<int> table(n, 0);

	for (int i = 0; i < n; i++)
		table[i] = arr[i];

	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < i; j++)
		{
			if ((arr[i] > arr[j]) && (table[j] + arr[i] > table[i]))
				table[i] = table[j] + arr[i];
		}
	}

	int maxVal = INT_MIN;
	for (int i = 0; i < n; i++)
		maxVal = max(table[i], maxVal);
	return maxVal;
}

int main()
{
	vector<int> arr{ 1, 101, 2, 3, 100, 4, 5 };
	cout << MaxSumIncreasingSub(arr);
	return 0; 
}