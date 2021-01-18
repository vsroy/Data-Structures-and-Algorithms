/*Given two strings a and b consisting of lowercase characters. The task is to check whether two given strings are anagram of each other or not. 
An anagram of a string is another string that contains same characters, only the order of characters can be different. 
For example, “act” and “tac” are anagram of each other.*/

#include<iostream>
#include<string>
#include<vector>
using namespace std;

bool CheckAnagram(string first, string second)
{
	vector<int> hashVect(26, 0);
	if (first.length() != second.length())
		return false;

	for (int i = 0; i < first.length(); i++)
	{
		hashVect[first[i] - 'a']++;
		hashVect[second[i] - 'a']--;
	}

	for (int i = 0; i < hashVect.size(); i++)
		if (hashVect[i] != 0)
			return false;
	return true;
}

int main()
{
	cout << CheckAnagram("listen", "silent");
	return 0;
}