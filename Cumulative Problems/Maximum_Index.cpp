/*Given an array A[] of N positive integers. The task is to find the maximum of j - i subjected to the constraint of A[i] <= A[j].*/
#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int MaxIndexDiff(vector<int> arr)
{
	int n = arr.size();

	int maxDiff;
	int i, j;

	vector<int> LMin(n, 0);
	vector<int> RMax(n, 0);

	/* Construct LMin[] such that
	LMin[i] stores the minimum value
	from (arr[0], arr[1], ... arr[i]) */
	LMin[0] = arr[0];
	for (i = 1; i < n; ++i)
		LMin[i] = min(arr[i], LMin[i - 1]);

	/* Construct RMax[] such that
	RMax[j] stores the maximum value from
	(arr[j], arr[j+1], ..arr[n-1]) */
	RMax[n - 1] = arr[n - 1];
	for (j = n - 2; j >= 0; --j)
		RMax[j] = max(arr[j], RMax[j + 1]);

	/* Traverse both arrays from left to right
	to find optimum j - i. This process is similar to
	merge() of MergeSort */
	i = 0, j = 0, maxDiff = -1;
	while (j < n && i < n) {
		if (LMin[i] < RMax[j]) {
			maxDiff = max(maxDiff, j - i);
			j = j + 1;
		}
		else
			i = i + 1;
	}

	return maxDiff;
}

int main()
{
	vector<int> ipVect{ 9, 2, 3, 4, 5,
		6, 7, 8, 18, 0 };
	cout << MaxIndexDiff(ipVect);
	return 0;
}