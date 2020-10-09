/*Given a non-empty string of lowercase letters and a non-negative integer value representing a key, write a function that returns a new 
string obtained by shifting every letter in the input string by k positions in the alphabet, where k is the key. 
Note that letters should "wrap" around the alphabet; in other words, the letter "z" shifted by 1 returns the letter "a".*/
#include<iostream>
#include<string>
using namespace std;

string ConvertToCaesarCypher(string str, int skip)
{
	for (int i = 0; i < str.length(); i++)
	{
		int val = str[i] - 'A';
		val = (val + skip) % 26;
		char new_char = char(val) + 'A';
		str[i] = new_char;
	}
	return str;
}

int main()
{
	string raw_string = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
	cout << ConvertToCaesarCypher(raw_string,23);
	return 0;
}