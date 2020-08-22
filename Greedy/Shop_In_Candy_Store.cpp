/*In a candy store there are N different types of candies available and the prices of all the N different types of candies are provided. 
There is also an attractive offer by candy store. 
We can buy a single candy from the store and get at-most K other candies (all are different types) for free.
Find minimum amount of money we have to spend to buy all the N different candies.
Find maximum amount of money we have to spend to buy all the N different candies.
In both the cases we must utilize the offer and get maximum possible candies back. If k or more candies are available,
we must take k candies for every candy purchase. If less than k candies are available, we must take all candies for a candy purchase.*/
#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int FindMinCost(vector<int> ipVect, int k)
{
	int n = ipVect.size();
	int res = 0;
	for (int i = 0; i < n; i++)
	{
		//Buy current candy
		res += ipVect[i];

		//And take k candies for every candy bought
		n = n - k;
	}
	return res;
}

int FindMaxCost(vector<int> ipVect, int k)
{
	int n = ipVect.size();

	int res = 0, index = 0;

	for (int i = n - 1; i >= index; i--)
	{
		// Buy candy with maximum amount 
		res += ipVect[i];

		// And get k candies for free from 
		// the starting 
		index += k;
	}
	return res;
}

int main()
{
	vector<int> ipVect{3,2,1,4};
	sort(ipVect.begin(), ipVect.end());
	cout << FindMinCost(ipVect, 2) << endl;
	cout << FindMaxCost(ipVect, 2) << endl;

	return 0;
}