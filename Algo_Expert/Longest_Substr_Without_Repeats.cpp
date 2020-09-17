#include<iostream>
#include<string>
#include<vector>
#include<algorithm>
using namespace std;
#define CHARS 256

int longestUniqueSubsttr(string str)
{
	int n = str.length();

	int res = 0;	//result

	//last index of all chars is initialized as -1
	vector<int> lastIndex(CHARS, -1);

	//Initialize start of current window
	int i = 0;

	//Move end of current window
	for (int j = 0; j < n; j++)
	{
		// Find the last index of str[j] 
		// Update i (starting index of current window) 
		// as maximum of current value of i and last 
		// index plus 1 
		i = max(i, lastIndex[str[j]] + 1);

		//Update res if we get a larger window
		res = max(res, j - i + 1);

		//Update the last index of j
		lastIndex[str[j]] = j;
	}
	return res;
}

int main()
{
	string str = "geeksforgeeks";
	cout << longestUniqueSubsttr(str);
	return 0;
}