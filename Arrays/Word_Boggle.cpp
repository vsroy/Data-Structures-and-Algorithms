/*Given a dictionary, a method to do lookup in dictionary and a M x N board where every cell has one character. 
Find all possible words that can be formed by a sequence of adjacent characters. Note that we can move to any of 8 adjacent characters, 
but a word should not have multiple instances of same cell.*/
#include<iostream>
#include<vector>
#include<string>
using namespace std;

vector<string> dict{ "GEEKS", "FOR", "QUIZ", "GO" };

bool Found(string str)
{
	for (auto i : dict)
		if (i == str)
			return true;
		else
			return false;
}

void FindWordsUtil(vector<vector<int>> boggle, vector<vector<bool>>& visited, int i, int j, string& str)
{
	int m = boggle.size();
	int n = boggle[0].size();

	visited[i][j] = true;
	str += boggle[i][j];
	
	//If we have found the word
	if (Found(str))
		cout << str;

	//Traverse in all the 8 directions
	for (int row = i - 1; row <= i + 1 && row < m; row++) 
        for (int col = j - 1; col <= j + 1 && col < n; col++) 
            if (row >= 0 && col >= 0 && !visited[row][col]) 
                FindWordsUtil(boggle, visited, row, col, str); 

	// Erase current character from string and mark visited 
	// of current cell as false 
	visited[i][j] = false;
	str.erase(str.length()-1);
}

void FindWords(vector<vector<int>> boggle)
{
	int m = boggle.size();
	int n = boggle[0].size();

	// Mark all characters as not visited 
	vector<vector<bool>> visited(m, vector<bool>(n, false));
	
	// Initialize current string 
	string str = "";

	// Consider every character and look for all words 
	// starting with this character 
	for (int i = 0; i < m; i++)
		for (int i = 0; i < n; i++)
			FindWordsUtil(boggle, visited, 0, 0, str);
}

int main()
{
	vector<vector<int>> boggle{ { 'G', 'I', 'Z' },
	{ 'U', 'E', 'K' },
	{ 'Q', 'S', 'E' } };

	FindWords(boggle);

	return 0;
};
