/*Given an n x n matrix and a number x, find the position of x in the matrix if it is present in it. Otherwise, print “Not Found”. 
In the given matrix, every row and column is sorted in increasing order. The designed algorithm should have linear time complexity.*/
#include<iostream>
#include<vector>
using namespace std;

/* Searches the element x in mat[][]. If the
element is found, then prints its position
and returns true, otherwise prints "not found"
and returns false */
int Search(vector<vector<int>> arr, int val)
{
	//Getting the right most column from the matrix
	int n = arr[0].size() - 1;

	//Return if matrix is empty
	if (n == 0)
		return -1;

	//Retrieve the smallest and largest value from the matrix
	int smallest = arr[0][0], largest = arr[n - 1][n - 1];

	//Check if we can actually find the value in the matrix
	if (val < smallest || val > largest)
		return -1;

	int i = 0, j = n - 1;
	
	//Check whether we are within row and column bounds
	while (i < n && j >= 0)
	{
		if (arr[i][j] == val)
		{
			cout << "Found at " << i << " and " << j << endl;
			return 1;
		}
		else
		{
			if (val > arr[i][j])
				i++;
			else
				j--;
		}
	}
	cout << "Element not found";
	return -1;
}

int main()
{
	vector<vector<int>> arr{ { 10, 20, 30, 40 },
	{ 15, 25, 35, 45 },
	{ 27, 29, 37, 48 },
	{ 32, 33, 39, 50 } };

	cout << Search(arr,29);
	return 0;
}