/*Given an n x m array where all rows and columns are in sorted order, write a function to determine whether the array contains an element x.*/
#include<iostream>
#include<vector>
using namespace std;

void FindElement(vector<vector<int>> arr, int x)
{
	int rows = arr.size();
	int columns = arr[0].size();

	int smallest = arr[0][0], largest = arr[rows - 1][columns - 1];

	if (x < smallest || x > largest)
	{
		cout << "Element is not present in the array";
		return;
	}

	int i = 0, j = columns - 1;
	while (i < rows && j >= columns)
	{
		if (arr[i][j] > x)
			j--;
		else if (arr[i][j] < x)
			i++;
		else
		{
			cout << "Element found at index " << i << " and  " << j;
			return;
		}
	}
	cout << "Element not found";
}

int main()
{
	return 0;
}