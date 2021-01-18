/*Given a square grid of size N, each cell of which contains integer cost which represents a cost to traverse through that cell, 
we need to find a path from top left cell to bottom right cell by which total cost incurred is minimum. You can move 
in 4 directions : up, down, left an right.*/
#include<iostream>
#include<queue>
#include<vector>
using namespace std;

//8 possible moves
int dx[] = {1, -1, 0, 0, 1, 1, -1, -1};
int dy[] = { 0, 0, 1, -1, 1, -1, 1, -1 };

/* The data structure to store the coordinates of \\
the unit square and the cost of path from the top left. */
struct Cell
{
	int x;
	int y;
	int cost;
};

/* The compare class to be used by a Min Heap.
* The greater than condition is used as this
is for a Min Heap based on priority_queue.
*/
class MyComparision
{
public:
	bool operator()(const Cell& lhs, const Cell& rhs) const
	{
		return(lhs.cost > rhs.cost);
	}
};

/* To verify whether a move is within the boundary. */
bool IsSafe(int x, int y, int rows, int columns)
{
	return x >= 0 && x < rows && y >= 0 && y < columns;
}

/* This solution is based on Dijkstra’s shortest path algorithm
* For each unit square being visited, we examine all
possible next moves in 8 directions,
*    calculate the accumulated cost of path for each
next move, adjust the cost of path of the adjacent
units to the minimum as needed.
*    then add the valid next moves into a Min Heap.
* The Min Heap pops out the next move with the minimum
accumulated cost of path.
* Once the iteration reaches the last unit at the lower
right corner, the minimum cost path will be returned.
*/
int MinCost(vector<vector<int>> cost,int m, int n)
{
	int rows = cost.size();
	int columns = cost[0].size();

	/* the array to store the accumulated cost
	of path from top left corner */
	vector<vector<int>> dp(rows, vector<int>(columns, 0));

	/* the array to record whether a unit
	square has been visited */
	vector<vector<int>> visited(rows, vector<int>(columns, 0));

	/* Initialize these two arrays, set path cost
	to maximum integer value, each unit as not visited */
	for (int i = 0; i < rows; i++) {
		for (int j = 0; j < columns; j++) {
			dp[i][j] = INT_MAX;
			visited[i][j] = false;
		}
	}

	/* Define a reverse priority queue.
	* Priority queue is a heap based implementation.
	* The default behavior of a priority queue is
	to have the maximum element at the top.
	* The compare class is used in the definition of the Min Heap.
	*/
	priority_queue<Cell, vector<Cell>, MyComparision> pq;

	/* initialize the starting top left unit with the
	cost and add it to the queue as the first move. */
	dp[0][0] = cost[0][0];

	pq.push({ 0, 0, cost[0][0] });

	while (!pq.empty())
	{
		/* pop a move from the queue, ignore the units
		already visited */
		Cell cell = pq.top();
		pq.pop();
		int x = cell.x;
		int y = cell.y;
		if (visited[x][y]) continue;

		/* mark the current unit as visited */
		visited[x][y] = true;

		/* examine all non-visited adjacent units in 8 directions
		* calculate the accumulated cost of path for
		each next move from this unit,
		* adjust the cost of path for each next adjacent
		units to the minimum if possible.
		*/

		for (int i = 0; i < 8; i++) 
		{
			int next_x = x + dx[i];
			int next_y = y + dy[i];
			if (IsSafe(next_x, next_y,rows,columns) && !visited[next_x][next_y]) 
			{
				dp[next_x][next_y] = min(dp[next_x][next_y],
					dp[x][y] + cost[next_x][next_y]);
				pq.push({ next_x, next_y, dp[next_x][next_y] });
			}
		}
	}

	/* return the minimum cost path at the lower
	right corner */
	return dp[m][n];
}

int main()
{
	vector<vector<int>> cost{ { 1, 8, 8, 1, 5 },
	{ 4, 1, 1, 8, 1 },
	{ 4, 2, 8, 8, 1 },
	{ 1, 5, 8, 8, 1 } };

	cout << MinCost(cost, 3, 4);
	return 0;
}