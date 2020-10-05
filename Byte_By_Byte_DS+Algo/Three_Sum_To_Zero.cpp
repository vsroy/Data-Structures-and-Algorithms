/*Given a list of integers, write a function that returns all sets of 3 numbers in the list, a, b, and c, so that a + b + c == 0.*/
#include<iostream>
#include<vector>
#include<unordered_set>
using namespace std;

void ThreeSum(vector<int> arr)
{
	int n = arr.size();

	for (int i = 0; i < n - 1; i++)
	{
		//Find all pairs with sum = -arr[i]
		unordered_set<int> hash;
		for (int j = i + 1; j < n; j++)
		{
			int x = -(arr[i] + arr[j]);
			if (hash.find(x) != hash.end())
				cout << x << " " << arr[i] << " " << arr[j] << " " << endl;
			else hash.insert(arr[j]);
		}
	}
}

int main()
{

}