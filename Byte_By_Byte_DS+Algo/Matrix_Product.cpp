/*Given a matrix, find the path from top left to bottom right with the greatest product by moving only down and right.*/
#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int MatrixProduct(vector<vector<int>> matrix)
{
	int rows = matrix.size();
	int columns = matrix[0].size();

	//Create caches of min and max product of a given cell
	vector<vector<int>> minCache(rows, vector<int>(columns, 0));
	vector<vector<int>> maxCache(rows, vector<int>(columns, 0));

	// Fill caches. We start at the top  left and iteratively find the greatest
	// at smallest path to each subsequent cell by considering the greatest and
	// smallest path to the cells above and to the left of the current cell
	for (int i = 0; i < rows; i++)
	{
		for (int j = 0; j < columns; j++)
		{
			int minVal = INT_MAX;
			int maxVal = INT_MIN;

			// If you're in the top left corner, just copy to cache
			if (i == 0 && j == 0)
			{
				maxVal = matrix[i][j];
				minVal = matrix[i][j];
			}

			//If we are not at the top consider the value above
			if (i > 0)
			{
				int tempMax = max(matrix[i][j] * maxCache[i - 1][j], matrix[i][j] * minCache[i - 1][j]);
				maxVal = max(tempMax, maxVal);

				int tempMin = min(matrix[i][j] * maxCache[i - 1][j], matrix[i][j] * minCache[i - 1][j]);
				minVal = min(tempMin, maxVal);
			}

			//If we are not at the top consider the value left
			if (j > 0)
			{
				int tempMax = max(matrix[i][j] * maxCache[i][j - 1], matrix[i][j] * minCache[i][j - 1]);
				maxVal = max(maxVal, tempMax);

				int tempMin = min(matrix[i][j] * maxCache[i][j - 1], matrix[i][j] * minCache[i][j - 1]);
				minVal = min(minVal, tempMin);
			}
			maxCache[i][j] = maxVal;
			minCache[i][j] = minVal;
		}
	}
	return maxCache[rows - 1][columns - 1];
}

int main()
{
	return 0;
}