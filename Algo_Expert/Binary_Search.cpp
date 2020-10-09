/*Given a sorted array arr[] of n elements, write a function to search a given element x in arr[].*/
#include<iostream>
#include<vector>
using namespace std;

int Binary_Search(vector<int> arr, int l, int r, int val)
{
	if (r >= l)
	{
		int mid = l + (r - l) / 2;

		if (arr[mid] == val)
			return mid;

		if (val < arr[mid])
			return Binary_Search(arr, l, mid - 1, val);
		else
			return Binary_Search(arr, mid + 1, r, val);
	}
	else
		return -1;
}
int main()
{
	vector<int> arr{ 2, 3, 4, 10, 40 };
	cout << Binary_Search(arr, 0, arr.size() - 1, 10);
	return 0;
}