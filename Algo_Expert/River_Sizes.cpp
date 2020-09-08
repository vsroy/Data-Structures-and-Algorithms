#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

void LengthMaxRiversUtil(vector<vector<int>>& ipVect, vector<vector<bool>>& visited, int i, int j, int& length)
{
	int rows = ipVect.size();
	int columns = ipVect[0].size();
	visited[i][j] = 1;
	length++;
	//Traverse all the cells adjoining the current cell
	for (int row = i - 1; row <= i + 1; row++)
		for (int col = i - 1; col <= i + 1; col++)
			if (row >= 0 && col >= 0 && row < rows && col < columns && !visited[row][col])
				LengthMaxRiversUtil(ipVect, visited, row, col, length);
}

int LengthMaxRivers(vector<vector<int>>& ipVect)
{
	int m = ipVect.size();
	int n = ipVect[0].size();
	int result = INT_MIN; 

	//Creating a vector array of m x n size
	vector<vector<bool>> visited(m,vector<bool>(n,0));	
	
	//Take every index as starting element 
	for(int i=0;i<m;i++)
	{
		for(int j=0;j<n;j++)
		{
			int length = 1;	
			LengthMaxRiversUtil(ipVect, visited, i, j, length);
			result = max(result, length);			
		}
	}
	return result;		
}


int main()
{
	vector<vector<int>> ipVect{ { 0, 0, 1, 1, 0 }, 
                     { 1, 0, 1, 1, 0 }, 
                     { 0, 1, 0, 0, 0 }, 
                     { 0, 0, 0, 0, 1 } }; 
	cout << LengthMaxRivers(ipVect);
	return 0;
}