/*Given an array arr[] of size N and an integer K which means there are N piles of coins and the ith contains arr[i] coins. 
The task is to adjust the number of coins in each pile such that for any two piles if a be the number of coins in the first pile 
and b be the number of coins in the second pile then |a – b| ≤ K.
One can remove coins from different piles to decrease the number of coins in those piles but cannot increase the number of\
coins in a pile by adding more coins. Find the minimum number of coins to be removed in order to satisfy the given condition.*/

#include<iostream>
#include<vector>
using namespace std;

void MinCoins(vector<int> ipVect, int k)
{
	int res = 0;

	//Find the min element
	int min = INT_MAX;
	for (int i = 0; i < ipVect.size(); i++)
	{
		if (ipVect[i] < min)
			min = ipVect[i];
	}

	//Now for every pile find the difference between min and coins in current pile, if diff > k, subtract k from diff
	for (int i = 0; i < ipVect.size(); i++)
	{
		int diff = ipVect[i] - min;
		if (diff > k)
			res += diff - k;
	}
	cout << res;
}

int main()
{
	vector<int> ipVect{ 1, 5, 1, 2, 5, 1 };

	MinCoins(ipVect,3);

	return 0;
}