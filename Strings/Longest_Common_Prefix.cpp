/*Given a array of N strings, find the longest common prefix among all strings present in the array.*/
#include<iostream>
#include<vector>
#include<string>
using namespace std;


string LongestCommonPrefix(vector<string>& ipVect)
{
	int minLength = INT_MAX;

	//Getting the minimum length out of all the strings in the array
	for (int i = 0; i < ipVect.size(); i++)
		if (ipVect[i].length() < minLength)
			minLength = ipVect[i].length();

	string resultString = "";
	int i = 0;
	while (i < minLength)
	{
		char currChar = ipVect[0][i];
		for (int j = 0; j < ipVect.size(); j++)
		{
			if (ipVect[j][i] != currChar)
				return resultString;
		}
		resultString += currChar;
		i++;
	}
	return resultString;
}


int main()
{
	//vector<string> ipVect{ "apple", "ape", "april" };
	vector<string> ipVect{ "geeksforgeeks", "geeks",
		"geek", "geezer" };
	cout << LongestCommonPrefix(ipVect);
	return 0;
}