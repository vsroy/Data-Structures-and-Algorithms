/*Given an array of distinct integers. The task is to count all the triplets such that sum of two elements equals the third element.*/

#include<iostream>
#include<vector>
#include<unordered_map>
#include<algorithm>
using namespace std;

int countWays(vector<int> arr)
{
	int n = arr.size();
	unordered_map<int, int> freq;
	int max_val = 0;
	
	for (int i = 0; i < n; i++)
		max_val = max(max_val, arr[i]);
	
	for (int i = 0; i < n; i++)
		freq[arr[i]]++;

	int ans = 0; // stores the number of ways  

	// Case 1: 0, 0, 0  
	ans += freq[0] * (freq[0] - 1) * (freq[0] - 2) / 6;

	// Case 2: 0, x, x  
	for (int i = 1; i <= max_val; i++)
		ans += freq[0] * freq[i] * (freq[i] - 1) / 2;

	// Case 3: x, x, 2*x  
	for (int i = 1; 2 * i <= max_val; i++)
		ans += freq[i] * (freq[i] - 1) / 2 * freq[2 * i];

	// Case 4: x, y, x + y  
	// iterate through all pairs (x, y)  
	for (int i = 1; i <= max_val; i++) {
		for (int j = i + 1; i + j <= max_val; j++)
			ans += freq[i] * freq[j] * freq[i + j];
	}

	return ans;
}

int main()
{
	vector<int> ipVect{ 1,2,3,4,5 };
	cout << countWays(ipVect);
	return 0;
}