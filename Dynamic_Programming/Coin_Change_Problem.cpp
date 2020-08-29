/*Given a value N, find the number of ways to make change for N cents, if we have infinite supply of each of S = { S1, S2, .. , Sm} valued coins. 
The order of coins doesn’t matter. For example, for N = 4 and S = {1,2,3}, there are four solutions: {1,1,1,1},{1,1,2},{2,2},{1,3}. 
So output should be 4. For N = 10 and S = {2, 5, 3, 6}, there are five solutions: {2,2,2,2,2}, {2,2,3,3}, {2,2,6}, {2,3,5} and {5,5}. 
So the output should be 5.*/
#include<iostream>
#include<vector>
using namespace std;


int Count(vector<int> S, int m, int n)
{
	int i, j, x, y;

	// We need n+1 rows as the table  
	// is constructed in bottom up 
	// manner using the base case 0 
	// value case (n = 0) 
	vector<vector<int>> table(n + 1, vector<int>(m, 0));


	// Fill the enteries for 0 
	// value case (n = 0) 
	for (i = 0; i < m; i++)
		table[0][i] = 1;

	// Fill rest of the table entries  
	// in bottom up manner  
	for (i = 1; i < n + 1; i++)
	{
		for (j = 0; j < m; j++)
		{
			// Count of solutions including S[j] 
			x = (i - S[j] >= 0) ? table[i - S[j]][j] : 0;

			// Count of solutions excluding S[j] 
			y = (j >= 1) ? table[i][j - 1] : 0;

			// total count 
			table[i][j] = x + y;
		}
	}
	return table[n][m - 1];
}

int main()
{
	vector<int> coins{ 1, 2, 3 };
	cout << Count(coins,coins.size(),4);
	return 0;
}