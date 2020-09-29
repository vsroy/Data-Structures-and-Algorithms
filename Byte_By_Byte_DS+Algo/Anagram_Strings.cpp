/*Write a function to check whether two given strings are anagram of each other or not. An anagram of a string is another 
string that contains same characters, only the order of characters can be different. For example, “abcd” and “dabc” are anagram of each other.*/
#include<iostream>
#include<vector>
#include<string>
using namespace std;

#define NO_CHARS 256

bool CheckAnagram(string str1, string str2)
{
	if (str1.length() != str2.length())
		return false;

	int len = str1.length();

	vector<int> hash(NO_CHARS);

	for (int i = 0; i < len; i++)
	{
		hash[str1[i]]++;
		hash[str2[i]]--;
	}

	for (int i = 0; i < NO_CHARS; i++)
		if (hash[i] != 0)
			return false;

	return true;
}

int main()
{

}