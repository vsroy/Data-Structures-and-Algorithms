/*Given a matrix of dimension r*c where each cell in the matrix can have values 0, 1 or 2 which has the following meaning:
0 : Empty cell
1 : Cells have fresh oranges
2 : Cells have rotten oranges
So, we have to determine what is the minimum time required to rot all oranges. A rotten orange at index [i,j] 
can rot other fresh orange at indexes [i-1,j], [i+1,j], 
[i,j-1], [i,j+1] (up, down, left and right) in unit time. If it is impossible to rot every orange then simply return -1.*/

#include<iostream>
#include<vector>
#include<queue>
using namespace std;

struct ele
{
	int x, y;
};

// function to check whether a cell is valid / invalid 
bool isvalid(int i, int j, int R, int C)
{
	return (i >= 0 && j >= 0 && i < R && j < C);
}

bool checkall(vector<vector<int>> arr, int R, int C)
{
	for (int i = 0; i<R; i++)
		for (int j = 0; j<C; j++)
			if (arr[i][j] == 1)
				return true;
	return false;
}

int RotOranges(vector<vector<int>> ipVect)
{
	int rows = ipVect.size();
	int columns = ipVect[0].size();
	// Create a queue of cells 
	queue<ele> orangeQ;
	int ans = 0;

	ele temp;
	// Store all the cells having rotten orange in first time frame 
	for (int i = 0; i < rows; i++)
	{
		for (int j = 0; j < columns; j++)
		{
			if (ipVect[i][j] == 2)
			{
				temp.x = i; temp.y = j;
				orangeQ.push(temp);
			}
		}
	}

	int size = orangeQ.size();
	int count = 0;
	
	while (!orangeQ.empty())
	{
		// This flag is used to determine whether even a single fresh 
		// orange gets rotten due to rotten oranges in current time 
		// frame so we can increase the count of the required time. 
		bool flag = false;
		int size = orangeQ.size();
		int count = 0;
		
		while (count < size)
		{
			temp = orangeQ.front();

			// Check right adjacent cell that if it can be rotten 
			if (isvalid(temp.x + 1, temp.y, rows,columns) && ipVect[temp.x + 1][temp.y] == 1)
			{
				// if this is the first orange to get rotten, increase 
				// count and set the flag. 
				if (!flag) ans++, flag = true;

				// Make the orange rotten 
				ipVect[temp.x + 1][temp.y] = 2;

				// push the adjacent orange to Queue 
				temp.x++;
				orangeQ.push(temp);
				temp.x--; // Move back to current cell 
			}

			// Check left adjacent cell that if it can be rotten 
			if (isvalid(temp.x - 1, temp.y, rows,columns) && ipVect[temp.x - 1][temp.y] == 1) {
				if (!flag) ans++, flag = true;
				ipVect[temp.x - 1][temp.y] = 2;
				temp.x--;
				orangeQ.push(temp); // push this cell to Queue 
				temp.x++;
			}

			// Check top adjacent cell that if it can be rotten 
			if (isvalid(temp.x, temp.y + 1, rows, columns) && ipVect[temp.x][temp.y + 1] == 1) {
				if (!flag) ans++, flag = true;
				ipVect[temp.x][temp.y + 1] = 2;
				temp.y++;
				orangeQ.push(temp); // Push this cell to Queue 
				temp.y--;
			}

			// Check bottom adjacent cell if it can be rotten 
			if (isvalid(temp.x, temp.y - 1, rows, columns) && ipVect[temp.x][temp.y - 1] == 1) {
				if (!flag) ans++, flag = true;
				ipVect[temp.x][temp.y - 1] = 2;
				temp.y--;
				orangeQ.push(temp); // push this cell to Queue 
			}

			orangeQ.pop();
			count++;
		}
		// If Queue was empty than no rotten oranges left to process so exit 
	}
	// Return -1 if all arranges could not rot, otherwise -1. 
	return (checkall(ipVect,rows,columns)) ? -1 : ans;
}

int main()
{
	vector<vector<int>> ipVect{ { 2, 1, 0, 2, 1 },
	{ 1, 0, 1, 2, 1 },
	{ 1, 0, 0, 2, 1 } };
	int ans = RotOranges(ipVect);
	if (ans == -1)
		cout << "All oranges cannot rotn";
	else
		cout << "Time required for all oranges to rot => " << ans << endl;
	return 0;
}