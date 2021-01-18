/*Given a string, the task is to remove duplicates from it. Expected time complexity O(n) where n is length of input 
string and extra space O(1) under the assumption that there are total 256 possible characters in a string.*/

#include<iostream>
#include<string>
using namespace std;

void RemoveDuplicates(string& ipString)
{
	string tempString = "";

	for (int i = 0; i < ipString.size(); i++)
	{
		if (tempString.find(ipString[i]) == string::npos)
			tempString += ipString[i];
	}

	ipString = tempString;
}

int main()
{
	string ipString = "geeksforgeeks";
	RemoveDuplicates(ipString);
	cout << ipString;
	return 0;
}