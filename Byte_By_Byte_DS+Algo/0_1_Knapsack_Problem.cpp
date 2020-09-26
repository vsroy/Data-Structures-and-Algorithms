/*Given weights and values of n items, put these items in a knapsack of capacity W to get the maximum total value in the knapsack. 
In other words, given two integer arrays val[0..n-1] and wt[0..n-1] which represent values and weights associated with n items respectively. 
Also given an integer W which represents knapsack capacity, find out the maximum value subset of val[] such that sum of the weights of this 
subset is smaller than or equal to W. You cannot break an item, either pick the complete item or don’t pick it (0-1 property).*/
#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int Knapsack(int W, int n, vector<int> weights, vector<int> values)
{
	//Creating a 2d knapsack
	vector<vector<int>> knapsack(n+1, vector<int>(W+1, 0));

	//Build knapsack in botton up manner
	for (int i = 0; i <= n; i++)
	{
		for (int w = 0; w <= W; w++)
		{
			if (i == 0 || w == 0)
				knapsack[i][w] = 0;
			else if (weights[i - 1] > W)
				knapsack[i][w] = knapsack[i - 1][w];
			else
				knapsack[i][w] = max(values[i - 1] + knapsack[i - 1][w - weights[i - 1]], knapsack[i - 1][w]);
		}
	}
	return knapsack[n][W];
}

int main()
{

}