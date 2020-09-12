/*Given a value V, if we want to make change for V cents, and we have infinite supply of each of C = { C1, C2, .. , Cm} valued coins, what is the minimum number of coins to make the change?*/
#include<iostream>
#include<vector>
using namespace std;
int FindMinCoins(vector<int> coins, int V)
{
	int m = coins.size();
	
	// table[i] will be storing the minimum number of coins 
    // required for i value.  So table[V] will have result 
	vector<int> table(V+1);
	
	// Base case (If given value V is 0) 
	table[0] = 0;

	// Initialize all table values as Infinite 
	for (int i = 1; i <= V; i++)
		table[i] = INT_MAX;

	// Compute minimum coins required for all 
	// values from 1 to V 
	for (int i = 1; i <= V; i++)
	{
		// Go through all coins smaller than i 
		for (int j = 0; j<m; j++)
			if (coins[j] <= i)
			{
				int sub_res = table[i - coins[j]];
				if (sub_res != INT_MAX && sub_res + 1 < table[i])
					table[i] = sub_res + 1;
			}
	}
	return table[V];
}

int main()
{
	vector<int> arr{9,6,5,1};
	cout << FindMinCoins(arr, 11);
	return 0;
}