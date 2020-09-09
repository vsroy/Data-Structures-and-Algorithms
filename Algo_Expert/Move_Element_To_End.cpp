/*Given an array of random numbers, Push all the zero’s of a given array to the end of the array. For example, if the given arrays is {1, 9, 8, 4, 0, 0, 2, 7, 0, 6, 0}, it should be changed to {1, 9, 8, 4, 2, 7, 6, 0, 0, 0, 0}. 
The order of all other elements should be same. Expected time complexity is O(n) and extra space is O(1).*/
#include<iostream>
#include<vector>
using namespace std;

void PushZerosToEnd(vector<int>& arr)
{
	int n = arr.size();
	int count = 0;
	for(int i=0;i<n;i++)
	{
		if (arr[i] != 0)
		{
			arr[count] = arr[i];
			count++;
		}
	}
	while(count < n)
	{
		arr[count] = 0;
		count++;
	}
}

int main()
{
	vector<int> arr{1, 9, 8, 4, 0, 0, 2, 7, 0, 6, 0, 9};
	PushZerosToEnd(arr);

	for(auto i : arr)
		cout << i << " ";
	return 0;
}