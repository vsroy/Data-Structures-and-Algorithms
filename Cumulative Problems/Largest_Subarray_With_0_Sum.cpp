/*Given an array having both positive and negative integers. The task is to compute the length of the largest subarray with sum 0.*/
#include<iostream>
#include<unordered_map>
#include<vector>
using namespace std;

int max(int a, int b)
{
	return (a >= b ? a : b);
}

int MaxLen(vector<int> ipVect)
{
	//Initialize result
	int max_len = 0;

	//Initialize sum of elements
	int sum = 0;

	//Initialize map to store previous sums
	unordered_map<int, int> hashMap;
	
	for (int i = 0; i < ipVect.size(); i++)
	{
		sum += ipVect[i];
		
		//This is for the first element if it is 0
		if (ipVect[i] == 0 && max_len == 0)
			max_len = 1;
		
		//This is if we find sum 0 so far, it means that max length of subarray is from 0 to i
		if (sum == 0)
			max_len = i + 1;

		//Look for the sum in the Hash Table
		if (hashMap.find(sum) != hashMap.end())
		{
			max_len = max(max_len, i - hashMap[sum]);	// If this sum is seen before, then update max_len 
		}
		else
			hashMap[sum] = i;
	}
	return max_len;
}

int main()
{
	vector<int> ipVect{ 15, -2, 2, -8, 1, 7, 10, 23 };
	cout << MaxLen(ipVect);
	return 0;
}