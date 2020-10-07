/*Write a program that, given an array A[] of n numbers and another number x, determines whether or not there exist two elements 
in S whose sum is exactly x. */
#include<iostream>
#include<vector>
#include<unordered_set>
using namespace std;

void FindPairs(vector<int> arr, int sum)
{
	unordered_set<int> hash;

	for (int i = 0; i < arr.size(); i++)
	{
		int diff = sum - arr[i];
		if (hash.find(diff) != hash.end())
			cout << "Pair is " << diff << " and " << arr[i] << endl;
		else
			hash.insert(arr[i]);
	}
}

int main()
{
	vector<int> arr{ 0, -1, 2, -3, 1 };
	FindPairs(arr, -2);
	return 0;
}