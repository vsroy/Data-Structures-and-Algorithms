/*Given an array arr[] of positive integers. Find the length of the longest sub-sequence such that elements in the 
subsequence are consecutive integers, the consecutive numbers can be in any order.*/
#include<iostream>
#include<vector>
#include<unordered_set>
using namespace std;

int max(int a, int b)
{
	return (a >= b ? a : b);
}

int FindLongestCommonSubsequence(vector<int> ipVect)
{
	int result = 0;

	//Initialize the set
	unordered_set<int> hashSet;

	//Insert the elements into the set one by one
	for (int i = 0; i < ipVect.size(); i++)
		hashSet.insert(ipVect[i]);

	//Now traverse the input vector again
	for (int i = 0; i < ipVect.size(); i++)
	{
		// if current element is the starting 
		// element of a sequence 
		if (hashSet.find(ipVect[i] - 1) == hashSet.end())
		{
			// Then check for next elements 
			// in the sequence 
			int j = ipVect[i];
			while (hashSet.find(j) != hashSet.end())
				j++;
			// update  optimal length if 
			// this length is more 
			result = max(result, j - ipVect[i]);
		}
	}
	return result;
}

int main()
{
	vector<int> ipVect{ 1, 9, 3, 10, 4, 20, 2 };
	cout << FindLongestCommonSubsequence(ipVect);
	return 0;
}