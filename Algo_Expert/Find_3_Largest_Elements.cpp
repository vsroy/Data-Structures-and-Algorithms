/*Given an array with all distinct elements, find the largest three elements. Expected time complexity is O(n) and extra space is O(1).*/
#include<iostream>
#include<vector>
using namespace std;

void Print_3_Largest(vector<int> arr)
{
	if (arr.size() < 3)
	{
		cout << "Invalid Input";
		return;
	}
		
	int first = INT_MIN, second = INT_MIN, third = INT_MIN;

	for (int i = 0; i < arr.size(); i++)
	{
		if (arr[i] > first)
		{
			third = second;
			second = first;
			first = arr[i];
		}
		else if (arr[i] > second)
		{
			third = second;
			second = arr[i];
		}
		else if (arr[i] > third)
			third = arr[i];
	}

	cout << "The three largest elements are " << first << " " << second << " " << third;
}

int main()
{
	vector<int> arr{ 12, 13, 1, 10, 34, 1 };
	Print_3_Largest(arr);
	return 0;
}