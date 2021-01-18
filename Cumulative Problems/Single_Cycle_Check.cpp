/*Given an array arr[0..n-1] of positive and negative numbers we need to find if there is a cycle in array with given rules of movements. 
If a number at an i index is positive, then move arr[i]%n forward steps, i.e., next index to visit is (i + arr[i])%n. 
Conversely, if it’s negative, move backward arr[i]%n steps i.e., next index to visit is (i – arr[i])%n. Here n is size of array. 
If value of arr[i]%n is zero, then it means no move from index i.*/
#include<iostream>
#include<vector>
using namespace std;

bool isCycleRec(int v, vector<int>adj[], vector<bool> &visited, vector<bool> &recur)
{
	visited[v] = true;
	recur[v] = true;

	for (int i = 0; i < adj[v].size(); i++)
	{
		if (visited[adj[v][i]] == false)
			if (isCycleRec(adj[v][i], adj, visited, recur))
				return true;
			else if (visited[adj[v][i]] == true && recur[adj[v][i]] == true)
				return true;
	}
	recur[v] = false;
	return false;
}

//Returns true if vector has a cycle
bool IsCycle(vector<int> arr)
{
	int n = arr.size();

	//Create a graph using given moves in array
	vector<int>* adj = new vector<int>[n];
	for (int i = 0; i < n; i++)
		if (i != (arr[i] + i + n) % n)
			adj[i].push_back((arr[i] + i + n) % n);

	//Do DFS traversal of graph to detect cycle
	vector<bool> visited(n, false);
	vector<bool> recur(n, false);

	for (int i = 0; i < n; i++)
		if (visited[i] == false)
			if (isCycleRec(i, adj, visited, recur))
				return true;
	return true;
}

int main()
{
	vector<int> arr{ 2, -1, 1, 2, 2 };
	cout << IsCycle(arr);
	return 0;
}