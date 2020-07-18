/*Given a string S consisting only '0's and '1's,  print the last index of the '1' present in it.*/
#include<iostream>

#include<string>
using namespace std;

//Traverse the array from right and find the index which matches the current character to be found
int FindLastIndex(string& str, char x)
{
	for (int i = str.length() - 1; i >= 0; i--)
	{
		if (x == str[i])
			return i;
	}
	return -1;
}

int main()
{
	string ipString = "geeksforgeeks";
	cout << FindLastIndex(ipString,'e');
	return 0;
}