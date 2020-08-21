/*Given an array A[ ] denoting heights of N towers and a positive integer K, modify the heights of each tower either by 
increasing or decreasing them by K only once and then find out the minimum difference of the heights of shortest and longest towers.*/
#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

void Swap(int& a, int& b)
{
	int temp = a;
	a = b;
	b = temp;
}

// Modifies the array by subtracting/adding 
// k to every element such that the difference 
// between maximum and minimum is minimized 
int GetMinDiff(vector<int> arr, int k)
{
	int size = arr.size();

	if (arr.size() == 1)
		return 0;

	sort(arr.begin(), arr.end());

	// Initialize result 
	int ans = arr[size - 1] - arr[0];

	//Handle corner elements
	int small = arr[0] + k;
	int big = arr[size - 1] - k;

	if (small > big)
		Swap(small, big);

	//Traverse middle elements
	for (int i = 1; i < size - 1; i++)
	{
		int subtract = arr[i] - k;
		int add = arr[i] + k;

		// If both subtraction and addition 
		// do not change diff 
		if (subtract >= small || add <= big)
			continue;

		// Either subtraction causes a smaller 
		// number or addition causes a greater 
		// number. Update small or big using 
		// greedy approach (If big - subtract 
		// causes smaller diff, update small 
		// Else update big) 
		if (big - subtract <= add - small)
			small = subtract;
		else
			big = add;
	}
	return min(ans, big - small);
}

int main()
{
	vector<int> ipvect{ 4, 6 };
	cout << GetMinDiff(ipvect,10);
	return 0;
}