/*Find and print the uncommon characters of the two given strings S1 and S2. Here uncommon character means that either the character is present in 
one string or it is present in other string but not in both. The strings contains only lowercase characters and can contain duplicates.*/
#include<iostream>
#include<string>
#include<map>
#include<set>
using namespace std;

void FindUncommonCharacters(string str1, string str2)
{
	//Creating a map to store count of characters.
	map<char, int> hashMap;
	set<char> stringSet1;
	set<char> stringSet2;

	//Traversing string1 and string2 and inserting their occurrences in set
	for (int i = 0; i < str1.length(); i++)
		stringSet1.insert(str1[i]);

	for (int i = 0; i < str2.length(); i++)
		stringSet2.insert(str2[i]);

	set<char>::iterator it1;
	for (it1 = stringSet1.begin(); it1 != stringSet1.end(); it1++)
		hashMap[*it1]++;

	set<char>::iterator it2;
	for (it2 = stringSet2.begin(); it2 != stringSet2.end(); it2++)
		hashMap[*it2]++;

	//Now traversing the hashmap. All characters with 1 occurrence will be uncommon
	map<char, int>::iterator it;

	for (it = hashMap.begin(); it != hashMap.end(); it++)
		if (it->second == 1)
			cout << it->first << " ";
}

int main()
{
	string str1 = "characters";
	string str2 = "alphabets";
	FindUncommonCharacters(str1 ,str2);
	return 0;
}