/*Given an array of integers A and a sum B, find all unique combinations in A where the sum is equal to B.
Each number in A may only be used once in the combination.*/
#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

void CombinationUtil(int sum, int l, int K, vector<int> local, vector<int> ipVect)
{
	//If we get the desired sum, we print the combination
	if (sum == K)
	{
		for (int i = 0; i < local.size(); i++)
			cout << local[i];
		cout << endl;
	}

	//For all the other combinations,
		for (int i = l; i < ipVect.size(); i++)
		{
			// Check if the sum exceeds K 
			if (sum + ipVect[i] > K)
				continue;

			// Check if it is repeated or not 
			if (i && ipVect[i] == ipVect[i - 1] && i > l)
				continue;

			// Take the element into the combination 
			local.push_back(ipVect[i]);

			//Recursive Call
			CombinationUtil(sum + ipVect[i], i + 1, K, local, ipVect);

			// Remove element from the combination 
			local.pop_back();
		}
}

void Combination(vector<int>& ipVect, int K)
{
	sort(ipVect.begin(), ipVect.end());

	//Store the final combination
	vector<int> local;

	CombinationUtil(0,0,K,local,ipVect);
}

int main()
{
	vector<int> ipVect{ 10, 1, 2, 7, 6, 1, 5 };
	int K = 8;

	Combination(ipVect, K);
	return 0;
}