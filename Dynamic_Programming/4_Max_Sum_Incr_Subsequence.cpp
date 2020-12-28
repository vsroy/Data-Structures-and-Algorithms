/*Given an array A of N positive integers. Find the sum of maximum sum increasing subsequence of the given array.*/
#include<iostream>
#include<vector>
using namespace std;

int MaxSumIncreasingSubSequence(vector<int>& ipVect)
{
	int n = ipVect.size();

	int max = 0;
	vector<int> dpSum(n, 0);

	//Initiazlize values for all indexes
	for (int i = 0; i < n; i++)
		dpSum[i] = ipVect[i];

	/* Compute maximum sum values
	in bottom up manner just as in max increasing subsequence */
	for (int i = 1; i < n; i++)
	{
		for (int j = 0; j < i; j++)
		{
			if (ipVect[i] > ipVect[j] && dpSum[j] + ipVect[i] > dpSum[i])
				dpSum[i] = dpSum[j] + ipVect[i];
		}
	}

	//Find the max value
	for (int i = 0; i < n; i++)
		if (dpSum[i] > max)
			max = dpSum[i];
	return max;
}

int main()
{
	vector<int> ipVect{ 1, 101, 2, 3, 100, 4, 5 };
	cout << MaxSumIncreasingSubSequence(ipVect);
	return 0; 
}