/*Given a N X N matrix (M) filled with 1, 0, 2, 3. The task is to find whether there is a path possible from source to destination, 
while traversing through blank cells only. You can traverse up, down, right and left.
A value of cell 1 means Source.
A value of cell 2 means Destination.
A value of cell 3 means Blank cell.
A value of cell 0 means Blank Wall.
Note: there is only single source and single destination.*/
#include<iostream>
#include<list>
#include<vector>
using namespace std;

class Graph {
	int V;
	list<int>* adj;

public:
	Graph(int V)
	{
		this->V = V;
		adj = new list<int>[V];
	}
	void addEdge(int s, int d);
	bool BFS(int s, int d);
};

// add edge to graph 
void Graph::addEdge(int s, int d)
{
	adj[s].push_back(d);
}

// BFS function to find path 
// from source to sink 
bool Graph::BFS(int s, int d)
{
	// Base case 
	if (s == d)
		return true;

	// Mark all the vertices as not visited 
	bool* visited = new bool[V];
	for (int i = 0; i < V; i++)
		visited[i] = false;

	// Create a queue for BFS 
	list<int> queue;

	// Mark the current node as visited and 
	// enqueue it 
	visited[s] = true;
	queue.push_back(s);

	// it will be used to get all adjacent 
	// vertices of a vertex 
	list<int>::iterator i;

	while (!queue.empty())
	{
		// Dequeue a vertex from queue 
		s = queue.front();
		queue.pop_front();

		// Get all adjacent vertices of the 
		// dequeued vertex s. If a adjacent has 
		// not been visited, then mark it visited 
		// and enqueue it 
		for (
			i = adj[s].begin(); i != adj[s].end(); ++i) {
			// If this adjacent node is the 
			// destination node, then return true 
			if (*i == d)
				return true;
			else
			{
				if (!visited[*i])
					visited[*i] = true;
				queue.push_back(*i);
			}
		}
	}
	//If BFS is complete without finding destination
	return false;
}

bool isSafe(int i, int j, vector<vector<int>>& ipVect)
{
	int N = ipVect[0].size();
	if (
		(i < 0 || i >= N)
		|| (j < 0 || j >= N)
		|| ipVect[i][j] == 0)
		return false;
	return true;
}

// Returns true if there is 
// a path from a source (a 
// cell with value 1) to a 
// destination (a cell with 
// value 2) 
bool FindPath(vector<vector<int>> ipVect)
{
	int rows = ipVect.size();
	int columns = ipVect[0].size();

	//source and destination
	int s, d;

	int V = columns * columns + 2;
	Graph g(V);

	// create graph with n*n node 
	// each cell consider as node 
	// Number of current vertex 
	int k = 1;
	for (int i = 0; i < columns; i++)
	{
		for (int j = 0; j < columns; j++)
		{
			if (ipVect[i][j] != 0)
			{
				// connect all 4 adjacent 
				// cell to current cell 
				if (isSafe(i, j + 1, ipVect))
					g.addEdge(k, k + 1);
				if (isSafe(i, j - 1, ipVect))
					g.addEdge(k, k - 1);
				if (i < columns - 1 && isSafe(i + 1, j, ipVect))
					g.addEdge(k, k + columns);
				if (i > 0 && isSafe(i - 1, j, ipVect))
					g.addEdge(k, k - columns);
			}
			//Source Index
			if (ipVect[i][j] == 1)
				s = k;

			//Destination Index
			if (ipVect[i][j] == 2)
				d = k;

			k++;
		}
	}
	// find path Using BFS 
	return g.BFS(s, d);
}

int main()
{
	vector<vector<int>> ipVect{ { 0, 3, 0, 1 },
	{ 3, 0, 3, 3 },
	{ 2, 3, 3, 3 },
	{ 0, 3, 3, 3 } };

	(FindPath(ipVect) == true) ? cout << "Yes" : cout << "No" << endl;

	return 0;
}