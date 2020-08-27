/*You are given weights and values of N items, put these items in a knapsack of capacity W to get the maximum total value in the knapsack. 
Note that we have only one quantity of each item.
In other words, given two integer arrays val[0..N-1] and wt[0..N-1] which represent values and weights associated with N items respectively. 
Also given an integer W which represents knapsack capacity, find out the maximum value subset of val[] such that sum of 
the weights of this subset is smaller than or equal to W. You cannot break an item, either pick the complete item, or don’t pick it (0-1 property).*/
#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int KnapSack(int W, vector<int> weights, vector<int> values)
{
	int items = weights.size();

	//Creating the dp array of size number_of_items x weights;

	vector<vector<int>> dpVect(items + 1, vector<int>(W + 1, 0));

	// Build table K[][] in bottom up manner 
	for (int i = 0; i <= items; i++)
	{
		for (int j = 0; j <= W; j++)
		{
			if (i == 0 || j == 0)
				dpVect[i][j] = 0;
			else if (weights[i - 1] <= j)
			{
				dpVect[i][j] = max(values[i - 1] + dpVect[i - 1][j - weights[i - 1]],
					dpVect[i - 1][j]);
			}
			else
				dpVect[i][j] = dpVect[i - 1][j];
		}
	}
	return dpVect[items][W];
}

int main()
{
	vector<int> weights{ 10, 20, 30 };
	vector<int> values{ 60, 100, 120 };

	KnapSack(50, weights, values);

	return 0;
}