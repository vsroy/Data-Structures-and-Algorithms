/*Write an efficient program to find the sum of contiguous subarray
within a one-dimensional array of numbers which has the largest sum.
This is also knowm as Kadane's algorithm*/

#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int maxSizeSubArray(vector<int> ipVect)
{
	int currSum = 0;
	int maxSoFar = INT_MIN;

	for (int i = 0; i < ipVect.size(); i++)
	{
		currSum += ipVect[i];

		//If array contains only negative numbers, use the following
		//currSum = max(currSum + ipVect[i], ipVect[i]);
		if (currSum < 0)
			currSum = 0;

		else if (currSum > maxSoFar)
			maxSoFar = currSum;
	}
	return maxSoFar;
}

int main()
{
	vector<int> ipVect{ -2, -3, 4, -1, -2, 1, 5, -3 };
	cout << maxSizeSubArray(ipVect);
	return 0;
}