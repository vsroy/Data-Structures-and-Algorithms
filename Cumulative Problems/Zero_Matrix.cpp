/*Given a boolean matrix, update it so that if any cell is true, all the cells in that row and column are true.*/
#include<iostream>
#include<vector>
using namespace std;

void FillZeros(vector<vector<int>> arr)
{
	int rows = arr.size();
	int columns = arr[0].size();

	bool firstRowZero = false;
	bool firstColZero = false;

	for (int i = 0; i < rows; i++)
		if (arr[i][0] == 0)
			firstColZero = true;

	for (int j = 0; j < columns; j++)
		if (arr[0][j] == 0)
			firstRowZero = true;


	//Make the correponding row zero first which for which the cell is zero
	for (int i = 1; i < rows; i++)
	{
		for (int j = 1; j < columns; j++)
		{
			//Make the row and column as zero for which the element is zero
			if (arr[i][j] == 0)
			{
				arr[0][j] = 0;
				arr[i][0] = 0;
			}
		}
	}

	//Now, for every non zero element, if the corresponding row/column is zero, make the element zero
	for (int i = 1; i < rows; i++)
	{
		for (int j = 1; j < columns; j++)
		{
			if (arr[i][j] != 0)
			{
				if (arr[i][0] == 0)
				{
					firstColZero = true;
					arr[i][j] = 0;
				}
				else if (arr[0][j] == 0)
				{
					firstRowZero = true;
					arr[i][j] = 0;
				}
			}
		}
	}

	//Now, check if the first column and first row is zero or not, if yes, make them zero
	if (firstColZero)
		for (int i = 0; i < rows; i++)
			arr[i][0] = 0;

	if (firstRowZero)
		for (int j = 0; j < columns; j++)
			arr[0][j] = 0;
}

int main()
{
	return 0;
}