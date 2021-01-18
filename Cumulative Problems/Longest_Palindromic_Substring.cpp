/*Given a string, find the longest substring which is palindrome.*/
#include<iostream>
#include<string>
#include<vector>
using namespace std;

// Function to print a substring str[low..high] 
void PrintSubstring(string str, int low, int high)
{
	for (int i = low; i < high; i++)
		cout << str[i];
}

// This function prints the 
// longest palindrome substring 
// It also returns the length 
// of the longest palindrome 
int LongestPalindromicSubstring(string str)
{
	// get length of input string 
	int n = str.length();

	// table[i][j] will be false if substring 
	// str[i..j] is not palindrome. 
	// Else table[i][j] will be true 
	vector<vector<int>> table(n, vector<int>(n, 0));

	// All substrings of length 1 
	// are palindromes 
	int maxLength = 1;

	for (int i = 0; i < n; i++)
		table[i][i] = 1;

	//Check for substring of length 2
	int start = 0;
	for (int i = 0; i < n - 1; i++)
	{ 
		if (str[i] == str[i + 1])
		{
			table[i][i + 1] = true;
			start = i;
			maxLength = 2;
		}
	}

	// Check for lengths greater than 2. 
	// k is length of substring 
	for (int k = 3; k <= n; k++)
	{
		//Fix the starting index
		for (int i = 0; i < n - k + 1; i++)
		{
			int j = i + k - 1;

			// checking for sub-string from ith index to 
			// jth index iff str[i+1] to str[j-1] is a 
			// palindrome
			if (table[i + 1][j - 1] == 1 && str[i] == str[j])
			{
				table[i][j] = true;
				if (k > maxLength)
				{
					start = i;
					maxLength = k;
				}
			}
		}
	}

	cout << "Longest palindromic substring is ";
	PrintSubstring(str, start, start + maxLength);

	return maxLength;
}

int main()
{
	string str = "forgeeksskeegfor";
	cout << LongestPalindromicSubstring(str);
	return 0;
}