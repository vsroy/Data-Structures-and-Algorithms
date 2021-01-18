/*You are given an array of integers. You need to print the total count of sub-arrays having their sum equal to 0*/
#include<iostream>
#include<unordered_map>
#include<vector>
using namespace std;

void PrintSubArrays(vector<int> vect1)
{
	unordered_map<int,vector<int>> hashMap;
	int currSum = 0;

	for (int i = 0; i < vect1.size(); i++)
	{
		currSum += vect1[i];

		// if sum is 0, we found a subarray starting 
		// from index 0 and ending at index i 
		if (currSum == 0)
			cout << 0 << " " << i << endl;

		// If sum already exists in the map there exists 
		// at-least one subarray ending at index i with 
		// 0 sum
		if (hashMap.find(currSum) != hashMap.end())
		{
			//If there is more than one element in the vector for which sum is zero, we traverse the elements in the vect
			vector<int> hashVect = hashMap[currSum];
			for (int j = 0; j < hashVect.size(); j++)
				cout << hashVect[j]+1 << " " << i << endl;
		}
		hashMap[currSum].push_back(i);
	}
}

int main()
{
	vector<int> ipVect{ 6, 3, -1, -3, 4, -2, 2, 4, 6, -12, -7 };
	PrintSubArrays(ipVect);
	return 0;
}