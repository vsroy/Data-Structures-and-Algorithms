/*Given an array of integers where each element represents the max number of steps that can be made forward from that element. 
The task is to find the minimum number of jumps to reach the end of the array (starting from the first element). If an element is 0, 
then cannot move through that element.*/
#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int MinJumps(vector<int> arr)
{
	int n = arr.size();
	// jumps[n-1] will hold the result 
	vector<int> jumps(n, 0);
	int i, j;

	if (n == 0 || arr[0] == 0)
		return INT_MAX;

	jumps[0] = 0;

	// Find the minimum number of jumps to reach arr[i] 
	// from arr[0], and assign this value to jumps[i] 
	for (i = 1; i < n; i++) {
		jumps[i] = INT_MAX;
		for (j = 0; j < i; j++) {
			if (i <= j + arr[j] && jumps[j] != INT_MAX) {
				jumps[i] = min(jumps[i], jumps[j] + 1);
				break;
			}
		}
	}
	return jumps[n - 1];
}

int main()
{
	vector<int> ipvect{ 1, 3, 6, 1, 0, 9 };
	cout << MinJumps(ipvect);
	return 0;
}
