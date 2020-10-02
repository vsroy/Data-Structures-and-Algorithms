/*Given an input amount of change x, write a function to determine the minimum number of coins required to make that amount of change.*/
#include<iostream>
#include<vector>
using namespace std;

// m is size of coins array (number of different coins) 
int minCoins(vector<int> coins, int m, int V)
{
	// table[i] will be storing the minimum number of coins 
	// required for i value.  So table[V] will have result 
	vector<int> table(V + 1);

	// Base case (If given value V is 0) 
	table[0] = 0;

	// Initialize all table values as Infinite 
	for (int i = 0; i <= V; i++)
		table[i] = INT_MAX;

	// Compute minimum coins required for all 
	// values from 1 to V 
	for (int i = 0; i < V; i++)
	{
		for (int j = 0; j < m; j++)
		{
			//Go through all coins smaller than i
			if (coins[j] <= i)
			{
				int sub_res = table[i - coins[j]];
				if (sub_res != INT_MAX && sub_res + 1 < table[i])
					table[i] = sub_res + 1;
			}
		}
	}
	return table[V];
}

// Driver program to test above function 
int main()
{
	vector<int> coins{ 9, 6, 5, 1 };
	int V = 11;
	cout << "Minimum coins required is "
		<< minCoins(coins, coins.size(), V);
	return 0;
}