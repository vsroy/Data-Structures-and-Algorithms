/*Given an array, write a function to find any subarray that sums to zero, if one exists.*/
#include<iostream>
#include<vector>
#include<unordered_map>
using namespace std;

void SubArrayZeroSum(vector<int> arr)
{
	unordered_map<int, int> hashSet;
	int sum = 0;
	for (int i = 0; i < arr.size(); i++)
	{
		sum += arr[i];
		if (sum == 0)
			cout << "Sum Found from index 0 to " << i << endl;
		else
		{
			if (hashSet.find(sum) != hashSet.end())
			{
				//This sum has been encountered before. So, find the differnces in the indices
				cout << "Sum Found from index " << hashSet[sum] + 1 << " and " << i << endl;
			}
		}
		hashSet[sum] = i;
	}
}

 
int main()
{
	vector<int> arr{ 1, 4, -2, -2, 5, -4, 3 };

	SubArrayZeroSum(arr);

	return 0;
}