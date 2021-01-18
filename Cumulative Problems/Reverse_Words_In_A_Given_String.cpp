/*Given a String of length S, reverse the whole string without reversing the individual words in it. Words are separated by dots.*/

#include<iostream>
#include<string>
#include<algorithm>
using namespace std;

void ReverseWords(string& str)
{
	int start = 0;

	for (int end = 0; end < str.length(); end++)
	{
		if (str[end] == ' ')
		{
			reverse(str.begin() + start, str.begin() + end);
			start = end + 1;
		}
	}

	/*Reverse the last word*/
	reverse(str.begin() + start, str.end());

	/*Reverse the entire string*/
	reverse(str.begin(),str.end());
}

int main()
{
	string str = "so like this program very much";
	ReverseWords(str);
	cout << str;
	return 0;
}