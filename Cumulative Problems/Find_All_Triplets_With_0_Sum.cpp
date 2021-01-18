/*Given an array of distinct elements. The task is to find triplets in the array whose sum is zero.*/
#include<iostream>
#include<unordered_set>
using namespace std;

// function to print triplets with 0 sum 
void FindTriplets(vector<int> arr)
{
	int n = arr.size();
	bool found = false;
	for (int i = 0; i < n - 1; i++)
	{
		// Find all pairs with sum equals to 
		// "-arr[i]" 
		unordered_set<int> s;
		for (int j = i + 1; j < n; j++)
		{
			int x = -(arr[i] + arr[j]);
			if (s.find(x) != s.end())
			{
				printf("%d %d %d\n", x, arr[i], arr[j]);
				found = true;
			}
			else
				s.insert(arr[j]);
		}
	}
}

int main()
{
	vector<int> arr{ 0, -1, 2, -3, 1 };
	FindTriplets(arr);
	return 0;
}