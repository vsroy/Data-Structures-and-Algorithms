/*Given a Directed Graph. Check whether it contains any cycle or not.*/
#include<iostream>
#include<list>
using namespace std;

class Graph
{
	int V;
	list<int>* adj;
	bool IsCyclicUtil(int v, bool visited[], bool* recursionCall);

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
}

bool Graph::IsCyclicUtil(int v, bool visited[], bool* recursionStack)
{
	if (!visited[v])
	{
		// Mark the current node as visited 
		visited[v] = true;
		recursionStack[v] = true;

		// Recur for all the vertices adjacent to this vertex 
		list<int>::iterator it;
		for (it = adj[v].begin(); it != adj[v].end(); ++it)
		{
			if (!visited[*it] && IsCyclicUtil(*it, visited, recursionStack))
				return true;
			else if (recursionStack[*it])
				return true;
		}
	}
	recursionStack[v] = false;
	return false;
}

bool Graph::IsCyclic()
{
	// Mark all the vertices as not visited and not part of recursion 
	// stack 
	bool* visited = new bool[V];
	bool* recusrionStack = new bool[V];
	for (int i = 0; i < V; i++)
	{
		visited[i] = false;
		recusrionStack[i] = false;
	}
		

	// Call the recursive helper function to detect cycle in different 
	// DFS trees 
	for (int i = 0; i < V; i++)
		if (IsCyclicUtil(i, visited,recusrionStack))
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