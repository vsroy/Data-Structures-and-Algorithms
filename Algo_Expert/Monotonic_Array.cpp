/*Given an array arr[] of N elements where N ≥ 2, the task is to check the type of array whether it is:
Increasing.
Decreasing.
Increasing then decreasing.
Decreasing then increasing.*/

/*
Approach: The following conditions must satitisfy for:

Increasing array: The first two and the last two elements must be in increasing order.
Decreasing array: The first two and the last two elements must be in decreasing order.
Increasing then decreasing array: The first two elements must be in increasing order and the last two elements must be in decreasing order.
Decreasing then increasing array: The first two elements must be in decreasing order and the last two elements must be in increasing order.*/

#include<iostream>
#include<vector>
using namespace std;

void CheckType(vector<int> arr)
{
	int n = arr.size();
	if(arr[0] <= arr[1] && arr[n-1] >= arr[n-2])	
		cout << "Increasing";
	else if(arr[0] >= arr[1] && arr[n-1] <= arr[n-2])	
		cout << "Decreasing";
	else if(arr[0] <= arr[1] && arr[n-1] <= arr[n-2])	
		cout << "Increasing then Decreasing";
	else if(arr[0] >= arr[1] && arr[n-1] >= arr[n-2])
		cout << "Decreasing then Increasing";	
}

int main()
{
	vector<int> arr{1, 2, 3, 4};
	CheckType(arr);
	return 0;
}