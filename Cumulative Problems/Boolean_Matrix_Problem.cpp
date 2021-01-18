/*Given a boolean matrix mat[M][N] of size M X N, 
modify it such that if a matrix cell mat[i][j] is 1 (or true) then make all the cells of ith row and jth column as 1.*/
#include<iostream>
#include<vector>
using namespace std;

void BooleanMatrix(vector<vector<int>>& mat)
{
	// variables to check if there are any 1 
	// in first row and column 
	bool row_flag = false;
	bool col_flag = false;

	int rows = mat.size(), columns = mat[0].size();
	//Updating the first row and column if 1 is encountered
	for (int i = 0; i < rows; i++)
	{
		for (int j = 0; j < columns; j++)
		{
			if (mat[0][j] == 1)
				row_flag = true;
			if (mat[i][0] == 1)
				col_flag = true;
			if (mat[i][j] == 1)
			{
				mat[0][j] = 1;
				mat[i][0] = 1;
			}
		}
	}

	// Modify the input matrix mat[] using the 
	// first row and first column of Matrix mat 
	for (int i = 0; i < rows; i++)
	{
		for (int j = 0; j < columns; j++)
		{
			if (mat[0][j] == 1 || mat[i][0] == 1)
				mat[i][j] = 1;

		}
	}

	// modify first row if there was any 1 
	if (row_flag = true)
		for (int j = 0; j < columns; j++)
			mat[0][j] = 1;


	// modify first columns if there was any 1 
	if (col_flag = true)
		for (int i = 0; i < rows; i++)
			mat[i][0] = 1;
}

int main()
{
	vector<vector<int>> ipvect{ { 1, 0, 0, 1 },
	{ 0, 0, 1, 0 },
	{ 0, 0, 0, 0 } };

	BooleanMatrix(ipvect);

	return 0;
}