/*Giving a dictionary and a string ‘str’, find the longest string in dictionary which can be formed by deleting some characters of the given ‘str’.*/
#include<iostream>
#include<vector>
#include<string>
using namespace std;

bool IsSubsequence(string subset, string superset)
{
	int subsetCounter = 0;
	int count = 0;
	for (int i = 0; i < superset.length() && subsetCounter<subset.length(); i++)
		if (superset[i] == subset[subsetCounter])
			count++;
	
	if (count == subsetCounter)
		return true;
	else
		return false;
}

// Returns the longest string in dictionary which is a 
// subsequence of str. 
string findLongestString(vector <string > dict, string str)
{
	int maxLength = INT_MIN;
	string maxString = "";

	for (int i = 0; i < dict.size(); i++)
	{
		if (IsSubsequence(dict[i], str))
		{
			if (dict[i].length()>maxLength)
			{
				maxLength = dict[i].length();
				maxString = dict[i];
			}
		}
	}
	return maxString;
}

int main()
{
	vector <string > dict = { "ale", "apple", "monkey", "plea" };
	string str = "abpcplea";
	cout << findLongestString(dict, str) << endl;
	return 0;
}