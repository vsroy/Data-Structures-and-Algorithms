/*Given two strings str1 and str2 and below operations that can performed on str1. Find minimum number of edits (operations) required 
to convert ‘str1’ into ‘str2’.
Insert
Remove
Replace
All of the above operations are of equal cost.*/
#include<iostream>
#include<vector>
#include<string>
#include<algorithm>
using namespace std;

int EditDistance(string str1, string str2)
{
	int m = str1.length(), n = str2.length();

	// Create a table to store results of subproblems
	vector<vector<int>> dpVect(m, vector<int>(n, 0));

	// Fill d[][] in bottom up manner
	for (int i = 0; i <= m; i++)
	{
		for (int j = 0; j < n; j++)
		{
			// If first string is empty, only option is to 
			// insert all characters of second string
			if (i == 0)
				dpVect[i][j] = j;	 // Min. operations = j 

			// If second string is empty, only option is to 
			// remove all characters of second string 
			else if (j == 0)
				dpVect[i][j] = i;

			// If last characters are same, ignore last char 
			// and recur for remaining string 
			else if (str1[i - 1] == str2[j - 1])
				dpVect[i][j] = dpVect[i - 1][j - 1];

			// If the last character is different, consider all 
			// possibilities and find the minimum 
			else
				dpVect[i][j] = 1 + min(dpVect[i - 1][j], min(dpVect[i][j - 1], dpVect[i - 1][j - 1]));	//min of insert, remove and replace
		}
	}
	return dpVect[m][n];
}

int main()
{
	string str1 = "sunday";
	string str2 = "saturday";

	cout << EditDistance(str1,str2);
	return 0;
}