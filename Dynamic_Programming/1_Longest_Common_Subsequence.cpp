/*Given two sequences, find the length of longest subsequence present in both of them. Both the strings are of uppercase.*/
#include<iostream>
#include<vector>
#include<string>
#include<algorithm>
using namespace std;

int LCS(string X, string Y)
{
	int m = X.length(), n = Y.length();

	vector<vector<int>> L(m+1, vector<int>(n+1, 0));

	/* Following steps build L[m+1][n+1] in
	bottom up fashion. Note that L[i][j]
	contains length of LCS of X[0..i-1]
	and Y[0..j-1] */

	for (int i = 0; i <= m; i++)
	{
		for (int j = 0; j <= n; j++)
		{
			if (i == 0 || j == 0)
				L[i][j] = 0;
			else if (X[i - 1] == Y[j - 1])
				L[i][j] = L[i - 1][j - 1] + 1;
			else
				L[i][j] = max(L[i - 1][j], L[i][j - 1]);
		}
	}
	return L[m][n];
}

int main()
{
	string str1 = "AGGTAB";
	string str2 = "GXTXAYB";
	cout << LCS(str1, str2);
	return 0;
}