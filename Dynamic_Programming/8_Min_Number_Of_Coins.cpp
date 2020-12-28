/*Given a value N, total sum you have. You have to make change for Rs. N, and there is infinite supply of each of the denominations 
in Indian currency, i.e., you have infinite supply of { 1, 2, 5, 10, 20, 50, 100, 200, 500, 2000} valued coins/notes, 
Find the minimum number of coins and/or notes needed to make the change for Rs N.*/
#include<iostream>
#include<vector>
using namespace std;

int MinCoins(vector<int>& coins, int V)
{
	//Base case
	if (V == 0)
		return 0;

	//Initialize result
	int res = INT_MAX;

	// Try every coin that has smaller value than V 
	for (int i = 0; i < coins.size(); i++)
	{
		if (coins[i] <= V)
		{
			int sub_res = MinCoins(coins, V - coins[i]);

			// Check for INT_MAX to avoid overflow and see if 
			// result can minimized 
			if (sub_res != INT_MAX && sub_res + 1 < res)
				res = sub_res + 1;
		}
	}
	return res;
}

int main()
{
	vector<int> coins{ 9, 6, 5, 1 };
	cout << MinCoins(coins,11);
	return 0;
}