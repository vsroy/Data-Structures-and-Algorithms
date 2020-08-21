/*Given an array consisting cost of toys. Given an integer K depicting the amount with you. Maximise the number of toys you can have with K amount.*/
#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int MaximizeToys(vector<int> cost, int k)
{
	int res = 0;
	int count = 0;
	sort(cost.begin(), cost.end());

	for (int i = 0; i < cost.size(); i++)
	{
		if ((res + cost[i]) <= k)
		{
			res += cost[i];
			count++;
		}
		else
			return count;
	}
}

int main()
{
	vector<int> ipVect{ 1, 12, 5, 111, 200, 1000, 10, 9, 12, 15 };
	cout << MaximizeToys(ipVect,50);
	return 0;
}