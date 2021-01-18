/*Given an array of integers and a number k, write a function that returns true if given array can be divided into pairs 
such that sum of every pair is divisible by k.*/
#include<iostream>
#include<vector>
#include<unordered_map>
using namespace std;

bool CountPairs(vector<int> ipVect, int k)
{
	//A vector with odd number of elements will not have distinct pairs
	if (ipVect.size() % 2 != 0)
		return false;

	unordered_map<int, int> hashMap;

	//Fill up the map with remainder after k divides the current element
	for (int i = 0; i < ipVect.size(); i++)
	{
		int remainder = ipVect[i] % k;
		hashMap[remainder]++;
	}

	//Traverse the input vector again
	for (int i = 0; i < ipVect.size(); i++)
	{
		//Remainder of the current element
		int remainder = ipVect[i] % k;

		// If remainder with current element divides 
		// k into two halves.
		if (2 * remainder == k)
		{
			// Then there must be even occurrences of 
			// such remainder
			if (hashMap[remainder] % 2 != 0)
				return false;
		}
		// If remainder is 0, then there must be even  
		// elements with 0 remainder 
		else if (remainder == 0)
		{
			if (hashMap[remainder] % 2 != 0)
				return false;
		}
		else if (hashMap[remainder] != hashMap[k - remainder])
			return false;
	}
	return true;
}

int main()
{
	vector<int> ipVect{ 92, 75, 65, 48, 45, 35 };
	cout << CountPairs(ipVect, 10);
	return 0;
}