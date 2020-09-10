#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int LongestMountainSubArray(vector<int> arr)
{
	int n = arr.size();
	int begin = -1, end = -1;
	int max_length = 0;

	for(int i=0;i<n-1;i++)
	{
		//We have an increasing sequence
		if (arr[i + 1] > arr[i])
		{
			// When a new mountain sub-array 
			// is found, there is a need to 
			// set the variables k, j to -1 
			// in order to help calculate the 
			// length of new mountain sub-array 
			if (end != -1)
			{
				begin = -1; end = -1;
			}

			if (begin == -1)
				begin = i;

		}
		else if (arr[i + 1] < arr[i])
		{
			// Checks if starting element exists 
			// or not, if the starting element 
			// of the mountain sub-array exists 
			// then the index of ending element 
			// is stored in k 
			if (begin != -1)
				end = i + 1;

			// This condition checks if both 
			// starting index and ending index 
			// exists or not, if yes, the 
			// length is calculated. 
			if (begin != -1 && end != -1)
				max_length = max(end - begin + 1, max_length);
		}
		else
		{
			// ignore if there is no 
			// increase or decrease in 
			// the value of the next element 
			begin = -1; end = -1;
		}
	}
	if (begin != -1 && end != -1)
		max_length = max(end - begin + 1, max_length);
	
	return max_length;
}

int main()
{
	vector<int> arr{ 1, 3, 1, 4,
		5, 6, 7, 8,
		9, 8, 7, 6, 5 };

	cout << LongestMountainSubArray(arr);
	return 0;
}