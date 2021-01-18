/*Given an unsorted array of integers, find a subarray which adds to a given number. If there are 
more than one subarrays with the sum as the given number, print any of them*/

#include<iostream>
#include<unordered_map>
#include<vector>
using namespace std;

void subArraySum(vector<int> ipVect, int sum)
{
	int n = ipVect.size();
	int curSum = 0;
	unordered_map<int, int> ipMap;
	for (int i = 0; i < n; i++)
	{
		curSum += ipVect[i];

		if (curSum == sum)
		{
			cout << "Sum found between indexes 0 and " << i;
			return;
		}

		if (ipMap.find(curSum - sum) != ipMap.end())
		{
			int startIndex = ipMap[curSum - sum];
			cout << "Sum found between indexes " << startIndex << " and " << i;
			return;
		}

		ipMap[curSum] = i;
	}
	cout << "Could not find a subarray with the given sum";
}

int main()
{
	vector<int> ipVect{ 10, 2, -2, -20, 10 };
	subArraySum(ipVect, -10);
	return 0;
}