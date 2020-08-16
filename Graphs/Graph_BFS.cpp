/*Given a directed graph. The task is to do Breadth First Search of this graph.*/
#include<iostream>
#include<list>
#include<queue>
using namespace std;

// Graph class represents a directed graph 
// using adjacency list representation 
class Graph
{
	//Number of vertices
	int V;

	// Pointer to an array containing 
	// adjacency lists 
	list<int>* adj;

public:
	Graph(int v);	//Constructor

	// function to add an edge to graph 
	void addEdge(int v, int w);

	// BFS traversal of the vertices 
	// reachable from v
	void BFS(int v);
};

Graph::Graph(int v)
{
	this->V = v;
	adj = new list<int>[V];
}

void Graph::addEdge(int v, int w)
{
	adj[v].push_back(w);
}

void Graph::BFS(int v)
{
	// Mark all the vertices as not visited 
	bool* visited = new bool[V];
	for (int i = 0; i < V; i++)
		visited[i] = false;

	//Create a queue for BFS
	queue<int> bfsQ;
	visited[v] = true;
	bfsQ.push(v);

	list<int>::iterator it;

	while (!bfsQ.empty())
	{
		int front = bfsQ.front();
		cout << front << " ";
		bfsQ.pop();


		// Get all adjacent vertices of the dequeued 
		// vertex s. If a adjacent has not been visited,  
		// then mark it visited and enqueue it 
		for (it = adj[front].begin(); it != adj[front].end(); it++)
		{
			if (!visited[*it])
			{
				visited[*it] = true;
				bfsQ.push(*it);
			}			
		}
	}
}

int main()
{
	// Create a graph given in the above diagram 
	Graph g(4);
	g.addEdge(0, 1);
	g.addEdge(0, 2);
	g.addEdge(1, 2);
	g.addEdge(2, 0);
	g.addEdge(2, 3);
	g.addEdge(3, 3);

	cout << "Following is Depth First Traversal"
		" (starting from vertex 2) \n";
	g.BFS(2);

	return 0;
}