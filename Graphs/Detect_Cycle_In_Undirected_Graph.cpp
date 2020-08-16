/*Given a Undirected Graph. Check whether it contains a cycle or not. */
#include<iostream>
#include<list>
using namespace std;

class Graph
{
	int V;
	list<int>* adj;
	bool IsCyclicUtil(int v, bool visited[], int parent);

public:
	Graph(int v);
	void addEdge(int v, int w);
	bool IsCyclic();
};

Graph::Graph(int v)
{
	this->V = v;
	adj = new list<int>[V];
}

void Graph::addEdge(int v, int w)
{
	adj[v].push_back(w);
	adj[w].push_back(v);
}

bool Graph::IsCyclicUtil(int v, bool visited[], int parent)
{
	// Mark the current node as visited 
	visited[v] = true;

	// Recur for all the vertices adjacent to this vertex 
	list<int>::iterator it;
	for (it = adj[v].begin(); it != adj[v].end(); it++)
	{
		// If an adjacent is not visited, then recur for that adjacent 
		if (!visited[*it])
		{
			if (IsCyclicUtil(*it, visited, v))
				return true;
		}
		// If an adjacent is visited and not parent of current vertex, 
		// then there is a cycle. 
		else if (*it != parent)
			return true;
	}
	return false;
}

bool Graph::IsCyclic()
{
	// Mark all the vertices as not visited and not part of recursion 
	// stack 
	bool* visited = new bool[V];
	for (int i = 0; i < V; i++)
		visited[i] = false;

	// Call the recursive helper function to detect cycle in different 
	// DFS trees 
	for (int i = 0; i < V; i++)
		if (!visited[i])	// Don't recur for u if it is already visited 
			if (IsCyclicUtil(i, visited, -1))
				return true;

	return false;
}

int main()
{
	Graph g1(5);
	g1.addEdge(1, 0);
	g1.addEdge(0, 2);
	g1.addEdge(2, 1);
	g1.addEdge(0, 3);
	g1.addEdge(3, 4);
	g1.IsCyclic() ? cout << "Graph contains cycle\n" :
		cout << "Graph doesn't contain cycle\n";

	Graph g2(3);
	g2.addEdge(0, 1);
	g2.addEdge(1, 2);
	g2.IsCyclic() ? cout << "Graph contains cycle\n" :
		cout << "Graph doesn't contain cycle\n";

	return 0;
}