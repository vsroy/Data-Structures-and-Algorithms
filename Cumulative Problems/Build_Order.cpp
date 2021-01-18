/*Given a list of packages that need to be built and the dependencies for each package, determine a valid order in which to build the packages.*/
#include<iostream>
#include<vector>
#include<unordered_set>
#include<queue>
using namespace std;

//Here, we make dependencies list
vector<unordered_set<int>> make_graph(vector<pair<int,int>>& prerequisites, int& numTasks)
{
	vector<unordered_set<int>> graph(numTasks);

	for (auto pairCombo : prerequisites)
		graph[pairCombo.second].insert(pairCombo.second);

	return graph;
}

//Will compute the in-degree of every vertex
vector<int> compute_indegree(vector<unordered_set<int>>& graph)
{
	vector<int> degree(graph.size(), 0);
	for (auto graph_item : graph)
	{
		for (int dependency : graph_item)
			degree[dependency]++;
	}
	return degree;
}


vector<int> FindOrder(int numTasks, vector<pair<int,int>> prerequisites)
{
	vector<unordered_set<int>> graph = make_graph(prerequisites, numTasks);

	//Find vertices of zero degree
	vector<int> degree = compute_indegree(graph);

	//Find vertices of zero degree
	queue<int> zeroes;
	for (int i = 0; i < numTasks; i++)
		if (!degree[i])
			zeroes.push(i);

	//Find vertices of zero degree starting with zero degree and reducing degrees of adjacent
	vector<int> topoSort;
	for (int i = 0; i < numTasks; i++)
	{
		if (zeroes.empty())
			return{};
		int zero = zeroes.front();
		zeroes.pop();

		topoSort.push_back(zero);
		for (int neigh : graph[zero])
			if (!--degree[neigh])
				zeroes.push(neigh);
	}
	return topoSort;
}

int main()
{
	int numTasks = 4;
	vector<pair<int, int>> prerequisites;
	prerequisites.push_back(make_pair(1, 0));
	prerequisites.push_back(make_pair(3, 1));
	prerequisites.push_back(make_pair(3, 2));

	vector<int> order = FindOrder(numTasks, prerequisites);
	for (int i : order)
		cout << i << " ";
	return 0;
}