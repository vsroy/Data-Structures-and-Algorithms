/*Given an unsorted array of integers, find a subarray which adds to a given number. 
If there are more than one subarrays with the sum as the given number, print any of the*/
#include<iostream>
#include<vector>
#include<map>
using namespace std;

void SubArrayWithGivenSum(vector<int> ipVect, int target)
{
	int n = ipVect.size();
	int currentSum = 0;
	map<int, int> hashMap;
	for (int i = 0; i < n; i++)
	{
		currentSum += ipVect[i];
		if (currentSum == target)
		{
			cout << "Sum found between indices 0 to " << i;
			return;
		}

		if (hashMap.find(currentSum - target) != hashMap.end())
		{
			cout << "Sum found between indices " << hashMap[currentSum - target] + 1 << " and " << i;
			return;
		}

		hashMap[currentSum] = i;
	}
	cout << "No result exists";
}

int main()
{
	vector<int> ipVect{ 10, 2, -2, -20, 10 };
	SubArrayWithGivenSum(ipVect,-10);
	return 0;
}