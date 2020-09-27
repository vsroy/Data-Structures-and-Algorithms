/*Find the length of maximum number of consecutive numbers jumbled up in an array.*/
#include<iostream>
#include<vector>
#include<algorithm>
#include<unordered_set>
using namespace std;

int MaxLengthConsecutiveNos(vector<int> arr)
{
	unordered_set<int> uSet;

	int result = 0;

	//First insert all the elements in the set
	for (int i = 0; i < arr.size(); i++)
		uSet.insert(arr[i]);

	//Now loop through the array again and find consecutive
	for (int i = 0; i < arr.size(); i++)
	{
		//If current element is the starting of a sequence
		if (uSet.find(arr[i] - 1) == uSet.end())
		{
			//We check for other consecutive elements
			int j = arr[i];

			//Increment till we find consecutive elements
			while (uSet.find(j) != uSet.end())
				j++;

			//Find the max so far of result
			result = max(result, j - arr[i]);
		}
	}
	return result;
}

int main()
{
	vector<int> arr{ 1, 94, 93, 1000, 5, 92, 78 };
	cout << MaxLengthConsecutiveNos(arr);
	return 0;
}