/*Given a Matrix consisting of 0s and 1s. Find the number of islands of connected 1s present in the matrix. */
#include<iostream>
#include<vector>
using namespace std;

int IsSafe(vector<vector<int>>& ipVect, int row, int column, vector<vector<int>>& visited)
{
	int rows = ipVect.size();
	int columns = ipVect[0].size();
	
	// row number is in range, column 
	// number is in range and value is 1 
	// and not yet visited 
	return (
		row >= 0 &&
		row < rows &&
		column >= 0 &&
		column < columns &&
		!visited[row][column] &&
		ipVect[row][column]
		);
}

// A utility function to do DFS for a 
// 2D boolean matrix. It only considers 
// the 8 neighbours as adjacent vertices 
void DFS(vector<vector<int>>& ipVect,int row,int column,vector<vector<int>>& visited)
{
	// These arrays are used to get 
	// row and column numbers of 8 
	// neighbours of a given cell 
	static int rowNbr[] = { -1, -1, -1, 0, 0, 1, 1, 1 };
	static int colNbr[] = { -1, 0, 1, -1, 1, -1, 0, 1 };

	visited[row][column] = 1;

	//recur for all connected neighbours
	for (int i = 0; i < 8; i++)
	{
		if (IsSafe(ipVect, row + rowNbr[i], column + colNbr[i], visited))
			DFS(ipVect, row + rowNbr[i], column + colNbr[i], visited);
	}
}

int CountIslands(vector<vector<int>>& ipVect)
{
	int rows = ipVect.size();
	int columns = ipVect[0].size();
	// Make a int array to mark visited cells. 
	// Initially all cells are unvisited 
	vector<vector<int>> visited(rows,vector<int>(columns,0));

	// Initialize count as 0 and 
	// travese through the all cells of 
	// given matrix 
	int count = 0;
	for (int i = 0; i < rows; i++)
	{
		for (int j = 0; j < columns; j++)
		{
			if (ipVect[i][j] && !visited[i][j])
			{
				// visited yet, then new island found 
				// Visit all cells in this island. 
				DFS(ipVect, i, j, visited);

				//Increment island count
				count++;
			}
		}
	}
	return count;
}

int main()
{
	vector<vector<int>> ipVect = { { 1, 1, 0, 0, 0 },
	{ 0, 1, 0, 0, 1 },
	{ 1, 0, 0, 1, 1 },
	{ 0, 0, 0, 0, 0 },
	{ 1, 0, 1, 0, 1 } };

	cout << "Number of islands is: " << CountIslands(ipVect);

	return 0;
}