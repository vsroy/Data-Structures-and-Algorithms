/*Given a boolean 2D matrix (0-based index), find whether there is path from (0,0) to (x,y) and if there is one path, 
print the minimum no of steps needed to reach it, else print -1 if the destination is not reachable. You may move 
in only four direction ie up, down, left and right. The path can only be created out of a cell if its value is 1.*/
#include<iostream>
#include<vector>
#include<queue>
using namespace std;

//Store the cell co-ordinates
struct Point
{int x; int y;};

//A data structure for queue used in BFS
struct queueNode
{
	Point pt;	//co-ordinates from the cell
	int dist;	//distance from the source
};

// return true if row number and column number 
// is in range 
bool IsValid(int row, int column, int rows, int columns)
{
	return (row >= 0 && row < rows && column >= 0 && column < columns);
}

// These arrays are used to get row and column 
// numbers of 4 neighbours of a given cell 
int rowNum[] = {-1,0,0,1};
int colNum[] = {0.-1,1,0};

// function to find the shortest path between 
// a given source cell to a destination cell. 
int BFS(vector<vector<int>> ipVect, Point src, Point dest)
{
	int rows = ipVect.size();
	int columns = ipVect[0].size();

	//Check if source and destination of matrix cell is 1
	if (!ipVect[src.x][src.y] || !ipVect[dest.x][dest.y])
		return -1;

	//Creating an mxn vector marking visited elements
	vector<vector<int>> visited(rows, vector<int>(columns, 0));

	//Marking source vertex as visited
	visited[src.x][src.y] = 1;

	//Create a queuenode for BFS
	queue<queueNode> q;

	//Distance from src to src is 0. Push to queue
	queueNode s = { src, 0 };
	q.push(s);

	//Do a BFS starting from source cell
	while (!q.empty())
	{
		queueNode curr = q.front();
		Point pt = curr.pt;

		// If we have reached the destination cell, 
		// we are done 
		if (pt.x == dest.x && pt.y == dest.y)
			return curr.dist;

		// Otherwise dequeue the front cell in the queue 
		// and enqueue its adjacent cells 
		q.pop();

		for (int i = 0; i < 4; i++)
		{
			int row = curr.pt.x + rowNum[i];
			int column = curr.pt.x + colNum[i];

			// if adjacent cell is valid, has path and 
			// not visited yet, enqueue it. 
			if (IsValid(row, column, rows, columns) && ipVect[row][column] && !visited[row][column])
			{
				// mark cell as visited and enqueue it 
				visited[row][column] = 1;
				queueNode adjacentCell = { { row, column }, curr.dist + 1 };
				q.push(adjacentCell);
			}
		}
	}
	// Return -1 if destination cannot be reached 
	return -1;
}

int main()
{
	vector<vector<int>>ipVect
	{
		{ 1, 0, 1, 1, 1, 1, 0, 1, 1, 1 },
		{ 1, 0, 1, 0, 1, 1, 1, 0, 1, 1 },
		{ 1, 1, 1, 0, 1, 1, 0, 1, 0, 1 },
		{ 0, 0, 0, 0, 1, 0, 0, 0, 0, 1 },
		{ 1, 1, 1, 0, 1, 1, 1, 0, 1, 0 },
		{ 1, 0, 1, 1, 1, 1, 0, 1, 0, 0 },
		{ 1, 0, 0, 0, 0, 0, 0, 0, 0, 1 },
		{ 1, 0, 1, 1, 1, 1, 0, 1, 1, 1 },
		{ 1, 1, 0, 0, 0, 0, 1, 0, 0, 1 }
	};

	Point source = { 0, 0 };
	Point dest = { 3, 4 };

	int dist = BFS(ipVect, source, dest);

	if (dist != INT_MAX)
		cout << "Shortest Path is " << dist;
	else
		cout << "Shortest Path doesn't exist";

	return 0;
}