/*Given a 2D screen, location of a pixel in the screen ie(x,y) and a color(K), your task is to replace color of 
the given pixel and all adjacent(excluding diagonally adjacent) same colored pixels with the given color K.*/
#include<iostream>
#include<vector>
using namespace std;

void FloodFillUtil(vector<vector<int>>& ipVect, int x, int y, int newC, int oldC)
{
	int rows = ipVect.size(), columns = ipVect[0].size();
	
	if (x < 0 || x >= rows || y < 0 || y >= columns)
		return;
	if (ipVect[x][y] != oldC)
		return;
	if (ipVect[x][y] == newC)
		return;

	// Replace the color at (x, y) 
	ipVect[x][y] = newC;

	//Recur for the adjacent elements excluding the diagonal elements
	FloodFillUtil(ipVect, x + 1, y, newC, oldC);
	FloodFillUtil(ipVect, x, y+1, newC, oldC);
	FloodFillUtil(ipVect, x - 1, y, newC, oldC);
	FloodFillUtil(ipVect, x, y-1, newC, oldC);
}

void FloodFill(vector<vector<int>>& ipVect,  int x, int y, int newC)
{
	FloodFillUtil(ipVect, x, y, newC, ipVect[x][y]);
}

int main()
{
	vector<vector<int>> ipVect { { 1, 1, 1, 1, 1, 1, 1, 1 },
	{ 1, 1, 1, 1, 1, 1, 0, 0 },
	{ 1, 0, 0, 1, 1, 0, 1, 1 },
	{ 1, 2, 2, 2, 2, 0, 1, 0 },
	{ 1, 1, 1, 2, 2, 0, 1, 0 },
	{ 1, 1, 1, 2, 2, 2, 2, 0 },
	{ 1, 1, 1, 1, 1, 2, 1, 1 },
	{ 1, 1, 1, 1, 1, 2, 2, 1 },
	};

	int x = 4, y = 4, newC = 3;

	FloodFill(ipVect, x, y, newC);

	//Vector after implementing flood fill
	for (int i = 0; i < ipVect.size(); i++)
	{
		for (int j = 0; j < ipVect[i].size(); j++)
			cout << ipVect[i][j] << " ";
		cout << endl;
	}

	return 0;
}
