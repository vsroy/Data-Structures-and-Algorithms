/*Given a string S, find the longest palindromic substring in S. Substring of string S: S[ i . . . . j ] where 0 ≤ i ≤ j < len(S). 
Palindrome string: A string which reads the same backwards. More formally, S is palindrome if reverse(S) = S. Incase of conflict, 
return the substring which occurs first ( with the least starting index ).*/
//Solution for this problem - https://www.geeksforgeeks.org/longest-palindrome-substring-set-1/

#include<iostream>
#include<vector>
#include<string>
using namespace std;

void printSubStr(string str, int low, int high)
{
	for (int i = low; i <= high; ++i)
		cout << str[i];
}

int longestPalSubstr(string str)
{
	int n = str.length();

	//Initialize vector of length n x n
	vector<vector<int>> dpVect(n,vector<int> (n,0));

	int maxLength = 1;

	//All substring of length 1 are plaindromes
	for (int i = 0; i < n; i++)
		dpVect[i][i] = 1;

	//Check for substring of length 2
	int start = 0;
	for (int i = 0; i < n - 1; ++i)
	{
		if (str[i] == str[i + 1])
		{
			dpVect[i][i + 1] = 1;
			start = i;
			maxLength = 2;
		}
	}

	//Check for length greater than 2
	for (int k = 3; k <= n; k++)
	{
		// Get the ending index of substring from 
		// starting index i and length k 
		for (int i = 0; i < n - k + 1; i++)
		{
			// checking for sub-string from ith index to 
			// jth index iff str[i+1] to str[j-1] is a 
			// palindrome 
			int j = i + k - 1;
			if (dpVect[i + 1][j - 1] && str[i] == str[j])
			{
				dpVect[i][j] = true;
				if (k > maxLength)
				{
					start = i;
					maxLength = k;
				}
			}
		}
	}
	printSubStr(str, start, start + maxLength - 1);
	return maxLength;
}

int main()
{
	string str = "forgeeksskeegfor";
	cout << endl << "max Length = " << longestPalSubstr(str);
	return 0;
}