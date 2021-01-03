/*Given a set of numbers, check whether it can be partitioned into two subsets such that the sum of elements in both subsets is same or not.*/
#include<iostream>
#include<vector>
using namespace std;

bool IsSubsetSum(vector<int> set, int sum)
{
	int n = set.size();
	// The value of subset[i][j] will be true if 
	// there is a subset of set[0..j-1] with sum 
	// equal to i 
	vector<vector<bool>> subset(n + 1, vector<bool>(sum + 1, 0));

	// If sum is 0, then answer is true 
	for (int i = 0; i <= n; i++)
		subset[i][0] = true;

	// If sum is not 0 and set is empty, 
	// then answer is false 
	for (int i = 1; i <= sum; i++)
		subset[0][i] = false;

	// Fill the subset table in botton up manner 
	for (int i = 1; i <= n; i++)
	{
		for (int j = 1; j <= sum; j++)
		{
			if (j < set[i - 1])
				subset[i][j] = subset[i - 1][j];
			if (j >= set[i - 1])
				subset[i][j] = subset[i - 1][j] || subset[i - 1][j - set[i - 1]];
		}
	}
	return subset[n][sum];
}

int main()
{
	vector<int> set{ 3, 34, 4, 12, 5, 2 };
	cout << IsSubsetSum(set,9);
	return 0;
}