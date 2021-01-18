/*Given a binary matrix, find out the maximum size square sub-matrix with all 1s.*/
#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;

void PrintSquareSubMatrix(vector<vector<int>> matrix)
{
	int rows = matrix.size();
	int columns = matrix[0].size();

	//Create sum array
	vector<vector<int>> sum(rows, vector<int>(columns, 0));

	/*Set first column and row of sum array*/
	for (int i = 0; i < rows; i++)
		sum[i][0] = matrix[i][0];

	for (int j = 0; j < columns; j++)
		sum[0][j] = matrix[0][j];

	//Construct the other entries of sum array based on the below algo
	for (int i = 0; i < rows; i++)
	{
		for (int j = 0; j < columns; j++)
		{
			if (matrix[i][j] == 1)
				sum[i][j] = min(min(sum[i - 1][j], sum[i][j - 1]),sum[i - 1][j - 1]) + 1;
			else
				sum[i][j] = 0;
		}
	}

	//Find the maximum subentry and indexes of the maximum subentry
	int max_s = sum[0][0], max_i = 0, max_j = 0;
	for (int i = 0; i < rows; i++)
	{
		for (int j = 0; j < columns; j++)
		{
			if (max_s < sum[i][j])
			{
				max_s = sum[i][j];
				max_i = i;
				max_j = j;
			}
		}
	}

	cout << "Max size of the submatrix is ";
	for (int i = max_i; i > max_i - max_s; i--)
	{
		for (int j = max_j; i > max_j - max_s; j--)
		{
			cout << matrix[i][j] << " ";
		}
		cout << endl;
	}
}

int main()
{
	return 0;
}