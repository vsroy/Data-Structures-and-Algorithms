/*Given two strings str1 and str2, find if str1 is a subsequence of str2. A subsequence is a sequence that can be derived 
from another sequence by deleting some elements without changing the order of the remaining elements (source: wiki). 
Expected time complexity is linear.*/
#include<iostream>
#include<string>
using namespace std;

bool ValidateSubsequence(string sub, string super)
{
	int sub_length = sub.length();
	int super_length = super.length();

	int i = 0, j = 0;
	for (; i < super_length && j < sub_length; i++)
		if (sub[j] == super[i])
			j++;

	if (j == sub_length)
		return true;
	else
		return false;
}

int main()
{
	string super = "geeksforgeeks";
	string sub = "gksrek";

	cout << ValidateSubsequence(sub, super);

	return 0;
}