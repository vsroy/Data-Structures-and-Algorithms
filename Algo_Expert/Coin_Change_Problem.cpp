/*Given a value N, if we want to make change for N cents, and we have infinite supply of each of S = { S1, S2, .. , Sm} valued coins, 
how many ways can we make the change? The order of coins doesn’t matter.*/
#include<iostream>
#include<vector>
using namespace std;

int count(vector<int>& arr, int sum, int index)
{
	// If n is 0 then there is 1 solution  
	// (do not include any coin) 
	if (sum == 0)
		return 1;

	// If n is less than 0 then no  
	// solution exists 
	if (sum < 0)
		return 0;

	// If there are no coins and n  
	// is greater than 0, then no 
	// solution exist 
	if (index <= 0 && sum>0)
		return 0;

	return count(arr, sum, index - 1) + count(arr, sum - arr[index - 1], index);	
}

int main()
{
	vector<int> arr;
	cout << count(arr, 4, arr.size());
	return 0;
}