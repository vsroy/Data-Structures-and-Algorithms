/*Given a string str and another string patt. Find the character in patt that is present at the minimum index in str. 
If no character of patt is present in str then print ‘No character present’.*/
#include<iostream>
#include<string>
#include<set>
using namespace std;

char MinIndexedCharcter(string& str, string& patt)
{
	//Creatng the hashset
	set<char> hashSet;

	//Traversing the elements of str and inserting into hash
	for (int i = 0; i < patt.length(); i++)
		hashSet.insert(patt[i]);

	//Traversing the pattern and finding the first occurence of an element in pattern in str
	for (int i = 0; i < str.length(); i++)
	{
		if (hashSet.find(str[i]) != hashSet.end())
			return str[i];
	}
	//If there are no common elements
	return '$';
}


int main()
{
	string str = "adcffaet";
	string patt = "onkl";

	cout << MinIndexedCharcter(str, patt);
	return 0;
}