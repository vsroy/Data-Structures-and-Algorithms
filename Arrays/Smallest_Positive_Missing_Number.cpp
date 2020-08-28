/*You are given an array arr[] of N integers including 0. The task is to find the smallest positive number missing from the array.*/
#include<iostream>
#include<vector>
using namespace std;

// Function to return the first missing positive 
// number from the given unsorted array 
int FirstMissingPosNumber(vector<int> ipVect)
{
	int n = ipVect.size();
	// To mark the occurrence of elements 
	vector<int> present(n+1,0);

	// Only mark the required elements 
	// All non-positive elements and 
	// the elements greater n + 1 will never 
	// be the answer 
	// For example, the array will be {1, 2, 3} 
	// in the worst case and the result 
	// will be 4 which is n + 1 
	for (int i = 0; i < n; i++)
		if (ipVect[i] > 0 && ipVect[i] <= n)
			present[ipVect[i]] = true;

	// Find the first element which didn't 
	// appear in the original array 
	for (int i = 1; i <= n; i++)
		if (present[i] == 0)
			return i;

	// If the original array was of the 
	// type {1, 2, 3} in its sorted form 
	return n + 1;
}

int main()
{
	vector<int> ipVect{ 0, 10, 2, -10, -20 };
	cout << FirstMissingPosNumber(ipVect);
	return 0;
}