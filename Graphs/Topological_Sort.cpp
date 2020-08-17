/*Given a Directed Graph. Find any Topological Sorting of that Graph.*/
#include<iostream>
#include<list>
#include<stack>
using namespace std;

class Graph
{
	int V;
	list<int>* adj;
	void TopologicalSortUtil(bool visited[], int v, stack<int>& graphStack);

public:
	Graph(int v);
	void addEdge(int v, int w);
	void TopologicalSort();
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

void Graph::TopologicalSortUtil(bool visited[], int v, stack<int>& graphStack)
{
	visited[v] = true;

	// Recur for all the vertices  
	// adjacent to this vertex 
	list<int>::iterator it;
	for (it = adj[v].begin(); it != adj[v].end(); ++it)
	{
		if (!visited[*it])
			TopologicalSortUtil(visited, *it, graphStack);
	}

	//Push the current vertex to stack where whose all neighours are visited or it does not point to any vertex
	graphStack.push(v);
}

void Graph::TopologicalSort()
{
	stack<int> graphStack;

	bool* visited = new bool[V];
	for (int i = 0; i < V; i++)
		visited[i] = false;

	// Call the recursive helper function 
	// to store Topological 
	// Sort starting from all  
	// vertices one by one
	for (int i = 0; i < V; i++)
	{
		if (!visited[i])
			TopologicalSortUtil(visited,i,graphStack);
	}
	while (!graphStack.empty())
	{
		cout << graphStack.top() << " ";
		graphStack.pop();
	}
}

int main()
{
	// Create a graph given in the above diagram 
	Graph g(6);
	g.addEdge(5, 2);
	g.addEdge(5, 0);
	g.addEdge(4, 0);
	g.addEdge(4, 1);
	g.addEdge(2, 3);
	g.addEdge(3, 1);

	cout << "Following is a Topological Sort of the given graph \n";
	g.TopologicalSort();

	return 0;
}