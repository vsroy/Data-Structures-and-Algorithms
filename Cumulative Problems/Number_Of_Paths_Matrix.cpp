/*The problem is to count all the possible paths from top left to bottom right of a MxN matrix with the constraints that 
from each cell you can either move to right or down.*/
#include<iostream>
using namespace std;

int NumberOfPaths(int x, int y)
{
	// If either given row number is first or given column 
	// number is first 
	if (x == 1 || y == 1)
		return 1;

	// If diagonal movements are allowed then the last 
	// addition is required. 
	return NumberOfPaths(x - 1,y) + NumberOfPaths(x,y - 1);
	//+NumberOfPaths(x - 1, y - 1);
}

int main()
{
	cout << NumberOfPaths(3, 3);
	return 0;
}