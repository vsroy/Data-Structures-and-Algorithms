/*The n-queens puzzle is the problem of placing n queens on an n�n chessboard such that no two queens attack each other. 
Given an integer n, print all distinct solutions to the n-queens puzzle. Each solution contains distinct board configurations of the n-queens� 
placement, where the solutions are a permutation of [1,2,3..n] in increasing order, here the number in the ith place 
denotes that the ith-column queen is placed in the row with that number. For eg below figure represents a chessboard [3 1 4 2].*/
#include<iostream>
#include<vector>
using namespace std;
#define N 4

void PrintSolution(vector<vector<int>>& board)
{
	for (int i = 0; i < N; i++)
		for (int j = 0; j < N; j++)
			cout << board[i][j];
	cout << endl;
}

/* A utility function to check if a queen can
be placed on board[row][col]. Note that this
function is called when "col" queens are
already placed in columns from 0 to col -1.
So we need to check only left side for
attacking queens */
bool IsSafe(vector<vector<int>>& board, int row, int col)
{
	/* Check this row on left side */
	for (int i = 0; i < col; i++)
		if (board[i][col] == 1)
			return false;

	/* Check upper diagonal on left side */
	for (int i = row, j = col; i >= 0 && j >= 0; i--, j--)
		if (board[i][j] == 1)
			return false;

	/*Check for lower diagonal on left side*/
	for (int i = row, j = col; i < N && j >= 0; i++, j--)
		if (board[i][j])
			return false;

	return true;
}


/* A recursive utility function to solve N
Queen problem */
bool SolveNQueen(vector<vector<int>>& board, int col)
{
	/* base case: If all queens are placed
	then return true */
	if (col >= N)
		return true;

	/* Consider this column and try placing
	this queen in all rows one by one */
	for (int i = 0; i < N; i++)
	{
		if (IsSafe(board, i, col))
		{
			/* Place this queen in board[i][col] */
			board[i][col] = 1;

			/* recur to place rest of the queens */
			if (SolveNQueen(board, col + 1))
				return true;
			
			/* If placing queen in board[i][col]
			doesn't lead to a solution, then
			remove queen from board[i][col] */
			board[i][col] = 0;
		}
	}
	return false;
}

int main()
{
	vector<vector<int>> board = { { 0, 0, 0, 0 },
	{ 0, 0, 0, 0 },
	{ 0, 0, 0, 0 },
	{ 0, 0, 0, 0 } };

	if (SolveNQueen(board, 0) == false) {
		printf("Solution does not exist");
		return false;
	}

	PrintSolution(board);
	return true;
}