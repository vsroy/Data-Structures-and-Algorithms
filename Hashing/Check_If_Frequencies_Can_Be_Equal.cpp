/*Given a string s which contains lower alphabetic characters, the task is to check if its possible to remove at most 
one character from this string in such a way that frequency of each distinct character becomes same in the string.*/
#include<iostream>
#include<map>
#include<set>
#include<string>
using namespace std;

bool CheckForEqualFrequency(map<char, int>& hashMap)
{
	map<char, int>::iterator it = hashMap.begin();

	//Getting the first frequency of the hashMap
	int freq = it->second;

	for (it = hashMap.begin(); it != hashMap.end(); it++)
		if (it->second != freq)
			return false;

	return true;
}

bool CheckEqualFrequency(string str)
{
	map<char, int> hashMap;
	set<char> hashSet;

	//First insert the frequency of all elements in the map and put the characters in the set so that we do not repeat the characters
	for (int i = 0; i < str.length(); i++)
	{
		hashSet.insert(str[i]);
		hashMap[str[i]]++;
	}
	
	//Check if we have a uniform hashmap by default
	if (CheckForEqualFrequency(hashMap))
		return true;

	//Now, traverse the set, for every character, reduce the hash count by one and check for frequency.
	//If uniform, return true else increase the frequency and check next character
	set<char>::iterator it;
	for (it = hashSet.begin(); it != hashSet.end(); it++)
	{
		hashMap[*it]--;
		if (CheckForEqualFrequency(hashMap))
			return true;
		else
			hashMap[*it]++;
	}
	return false;
}

int main()
{
	string str = "xxxxyyzz";
	cout << CheckEqualFrequency(str);
	return 0;
}