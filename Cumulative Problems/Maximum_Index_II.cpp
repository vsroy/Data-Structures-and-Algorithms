/*Given an array A[] of N positive integers. The task is to find the maximum of j - i subjected to the constraint of A[i] <= A[j].*/
#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int MaxIndexDiff(vector<int> arr)
{
	int n = arr.size();

	int maxDiff;
	vector<int> lMin(n, 0);
	vector<int> rMax(n, 0);

	/* Construct LMin[] such that
	LMin[i] stores the minimum value
	from (arr[0], arr[1], ... arr[i]) */
	lMin[0] = arr[0];
	for (int i = 1; i < n; i++)
		lMin[i] = min(arr[i], lMin[i - 1]);

	/* Construct rMax[] such that
	RMax[j] stores the maximum value from
	(arr[j], arr[j+1], ..arr[n-1]) */
	rMax[n - 1] = arr[n - 1];
	for (int j = n - 2; j >= 0; --j)
		rMax[j] = max(arr[j], rMax[j + 1]);

	/* Traverse both arrays from left to right
	to find optimum j - i. This process is similar to
	merge() of MergeSort */
	int i = 0, j = 0;
	maxDiff = -1;
	while (j < n && i < n)
	{
		if (lMin[i] < rMax[j])
		{
			maxDiff = max(maxDiff, j - i);
			j++;
		}
		else
			i++;
	}
	return maxDiff;
}

int main()
{
	vector<int> ipVect{ 9, 2, 3, 4, 5, 6, 7, 8, 18, 0 };

	cout << MaxIndexDiff(ipVect);
	return 0;
}