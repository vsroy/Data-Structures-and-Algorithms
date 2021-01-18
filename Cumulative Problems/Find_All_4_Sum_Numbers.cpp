#include<iostream>
#include<vector>
#include<unordered_map>
using namespace std;

void Find4SumNumbers(vector<int> ipVect, int sum)
{
	int n = ipVect.size();
	unordered_map<int, pair<int, int>> hashMap;

	//First find sum of all possible pair of elements
	for (int i = 0; i < n; i++)
	{
		for (int j = i + 1; j < n; j++)
			hashMap[ipVect[i] + ipVect[j]] = {i,j};
	}

	//Iterate and find another pair which when added to the above pair gives the sum
	for (int i = 0; i < n; i++)
	{
		for (int j = i + 1; j < n; j++)
		{
			int remainingSum = sum - (ipVect[i] + ipVect[j]);

			//If we have got the other pair
			if (hashMap.find(remainingSum) != hashMap.end())
			{
				pair<int, int> p = hashMap[remainingSum];

				//Check if we are repeating the same elements
				if (p.first != i && p.second != i && p.first != j && p.second != j)
				{
					cout << ipVect[p.first] << " " << ipVect[p.second] << " " << ipVect[i] << " " << ipVect[j];
					return;
				}
			}
		}
	}
}

int main()
{
	vector<int> ipVect{ 10, 20, 30, 40, 1, 2 };
	Find4SumNumbers(ipVect, 91);
	return 0;
}