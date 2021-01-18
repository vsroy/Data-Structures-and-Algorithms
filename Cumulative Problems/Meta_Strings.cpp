/*Given two strings, the task is to check whether these strings are meta strings or not. 
Meta strings are the strings which can be made equal by exactly one swap in any of the strings. Equal string are not considered here as Meta strings.*/
#include<iostream>
#include<string>
using namespace std;

bool CheckMetaStrings(string str1, string str2)
{
	int len1 = str1.length();
	int len2 = str2.length();

	// Return false if both are not of equal length 
	if (len1 != len2)
		return false;

	// To store indexes of previously mismatched 
	// characters 
	int prev = -1, current = -1;

	int count = 0;
	for (int i = 0; i < len1; i++)
	{
		//If current char does not match
		if (str1[i] != str2[i])
		{
			count++;

			if (count > 2)
				return false;

			//Store both unmatched characters of both strings
			prev = current;
			current = i;
		}
	}
	// Check if previous unmatched of string1 
	// is equal to curr unmatched of string2 
	// and also check for curr unmatched character, 
	// if both are same, then return true 
	// Check if they can be swapped also to get the result
	return (count == 2 && str1[prev] == str2[current] && str1[current] == str2[prev]);
}

int main()
{
	string str1 = "converse";
	string str2 = "conserve";

	cout << CheckMetaStrings(str1, str2);
	return 0;
}