/*Given 2 sorted arrays A and B of size N each. Print sum of middle elements of the array obtained after merging the given arrays.*/
#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

/* Function to get median
of a sorted array */
int Median(int arr[], int n)
{
	if (n % 2 == 0)
		return (arr[n / 2] +
		arr[n / 2 - 1]) / 2;
	else
		return arr[n / 2];
}

int GetMedian(int ar1[],
	int ar2[], int n)
{

	if (n == 0)
		return -1;

	if (n == 1)
		return (ar1[0] + ar2[0]) / 2;

	if (n == 2)
		return (max(ar1[0], ar2[0]) + min(ar1[1], ar2[1])) / 2;

	//Median of first sub array
	int m1 = Median(ar1, n);

	//Median of second sub array
	int m2 = Median(ar2, n);

	/* If medians are equal then
	return either m1 or m2 */
	if (m2 == m1)
		return m1;

	/* if m1 < m2 then median must
	exist in ar1[m1....] and
	ar2[....m2] */
	if (m1 < m2)
	{
		if (n % 2 == 0)
			return GetMedian(ar1 + n / 2 - 1, ar2, n - n / 2 + 1);
		return GetMedian(ar1 + n / 2, ar2, n - n / 2);
	}

	/* if m1 > m2 then median must
	exist in ar1[....m1] and
	ar2[m2...] */
	if (n % 2 == 0)
		return GetMedian(ar2 + n / 2 - 1, ar1, n - n / 2 + 1);
	return GetMedian(ar2 + n / 2, ar1, n - n / 2);
}

int main()
{
	int ar1[] = { 1, 2, 3, 6 };
	int ar2[] = { 4, 6, 8, 10 };
	int n1 = sizeof(ar1) /
		sizeof(ar1[0]);
	int n2 = sizeof(ar2) /
		sizeof(ar2[0]);
	if (n1 == n2)
		cout << "Median is "
		<< GetMedian(ar1, ar2, n1);
	else
		cout << "Doesn't work for arrays "
		<< "of unequal size";
	return 0;
}