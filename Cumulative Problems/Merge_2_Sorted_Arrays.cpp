/*Given 2 sorted arrays, A and B, where A is long enough to hold the contents of
A and B, write a function to copy the contents of B into A without using any buffer or additional memory.*/
#include<iostream>
#include<vector>
using namespace std;

void MergeArrays(vector<int> arr1, vector<int> arr2)
{
	int a_index = arr1.size() - arr2.size() - 1;
	int b_index = arr2.size() - 1;

	int mergeIndex = arr1.size() - 1;

	while (a_index >= 0 && b_index >= 0)
	{
		if (arr1[a_index] > arr2[b_index])
		{
			arr1[mergeIndex] = arr1[a_index];
			arr1[a_index] = arr2[b_index];
			a_index--;
		}
		else
			arr1[mergeIndex] = arr2[b_index];
		mergeIndex--;
	}

	while (b_index >= 0)
	{
		arr1[mergeIndex] = arr2[b_index];
		b_index--;
		mergeIndex--;
	}
}

int main()
{
	return 0;
}
