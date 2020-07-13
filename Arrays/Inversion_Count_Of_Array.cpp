/*Given an array of positive integers. The task is to find inversion count of array.
Inversion Count : For an array, inversion count indicates how far (or close) the array is from being sorted. If array is 
already sorted then inversion count is 0. If array is sorted in reverse order that inversion count is the maximum. */

#include<iostream>
#include<vector>
using namespace std;

int GetInverseCount(vector<int> ipVect)
{
	int count = 0;
	for (int i = 0; i < ipVect.size(); i++)
		for (int j = 0; j < i; j++)
			if (ipVect[j] < ipVect[i])
				count++;
	return count;
}

int main()
{
	vector<int> ipVect{ 1, 20, 6, 4, 5 };
	cout << GetInverseCount(ipVect);
	return 0;
}