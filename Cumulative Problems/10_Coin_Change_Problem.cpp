/*Given a value N, find the number of ways to make change for N cents, if we have infinite supply of each of S = { S1, S2, .. , Sm} valued coins. 
The order of coins doesn’t matter. For example, for N = 4 and S = {1,2,3}, there are four solutions: {1,1,1,1},{1,1,2},{2,2},{1,3}. 
So output should be 4. For N = 10 and S = {2, 5, 3, 6}, there are five solutions: {2,2,2,2,2}, {2,2,3,3}, {2,2,6}, {2,3,5} and {5,5}. 
So the output should be 5.*/
/*Program to find number of ways to make change*/
#include<iostream>
#include<vector>
using namespace std;

int CoinChangeWays(const vector<int>& coins, int N)
{
	int m = coins.size();

	int x, y;
	//Create a 2D array
	vector<vector<int>> dp_vect(N+1, vector<int>(m, 0));

	//For values of N = 0, where there is only 1 possibility of coin change, first row will be 1
	for (int i = 0; i < m; i++)
		dp_vect[0][i] = 1;

	//Now, fill up table values in bottom-up manner
	for (int i = 1; i <= N; i++)
	{
		for (int j = 0; j < m; j++)
		{
			//Count of solution including coins[j]
			x = (i - coins[j] >= 0) ? dp_vect[i - coins[j]][j] : 0;

			//Count of solution excluding coins[j]
			y = (j >= 1) ? dp_vect[i][j - 1] : 0;

			//total count
			dp_vect[i][j] = x + y;
		}
	}
	return dp_vect[N][m - 1];
}

int main()
{
	vector<int> coins{ 1, 2, 3 };
	cout << CoinChangeWays(coins, 4);
	return 0;
}