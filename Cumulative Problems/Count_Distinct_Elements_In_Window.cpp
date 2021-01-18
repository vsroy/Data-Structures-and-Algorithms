/*Given an array of integers and a number K. Find the count of distinct elements in every window of size K in the array.*/
#include<iostream>
#include<map>
#include<vector>
using namespace std;

void CountDistinct(vector<int> ipVect, int k)
{
	map<int, int> hashMap;

	int dist_count = 0;
	//Traverse the first window and store count of every element in the hash map
	for (int i = 0; i < k; i++)
	{
		if (hashMap[ipVect[i]] == 0)
			dist_count++;
		hashMap[ipVect[i]]++;
	}

	//Print the count of the first window
	cout << dist_count << endl;

	//Traverse through the remaining array
	for (int i = k; i < ipVect.size(); i++)
	{
		// Remove first element of previous window 
		// If there was only one occurrence, then reduce distinct count.
		if (hashMap[ipVect[i - k]] == 1)
			dist_count--;

		// reduce count of the removed element 
		hashMap[ipVect[i - k]]--;

		// Add new element of current window 
		// If this element appears first time, 
		// increment distinct element count 
		if (hashMap[ipVect[i]] == 0)
			dist_count++;
		hashMap[ipVect[i]]++;

		cout << dist_count << endl;
	}
}

int main()
{
	vector<int> ipVect{ 1, 2, 1, 3, 4, 2, 3 };
	CountDistinct(ipVect,4);
	return 0;
}