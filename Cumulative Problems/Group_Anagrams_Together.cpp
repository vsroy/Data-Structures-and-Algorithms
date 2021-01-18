/*Given an array of words, print all anagrams together.*/
#include<iostream>
#include<vector>
#include<unordered_map>
#include<algorithm>
#include<string>
using namespace std;

void PrintAnagram(unordered_map<string, vector<string>> hash_map)
{
	unordered_map<string, vector<string>>::iterator it;

	for (it = hash_map.begin(); it != hash_map.end(); it++)
	{
		vector<string> tempVect = it->second;
		for (int i = 0; i < tempVect.size(); i++)
			cout << tempVect[i] << " ";
		cout << endl;
	}
}

void StoreAnagrams(vector<string>& vec)
{
	unordered_map<string, vector<string>> hash_map;

	for (int i = 0; i < vec.size(); i++)
	{
		string tempStr = vec[i];
		sort(tempStr.begin(), tempStr.end());

		//string does not exist in the map
		if (hash_map.find(tempStr) == hash_map.end())
		{
			vector<string> tempVect;
			tempVect.push_back(vec[i]);
			hash_map[tempStr] = tempVect;
		}
		else
			hash_map[tempStr].push_back(vec[i]);
	}

	PrintAnagram(hash_map);
}

int main()
{
	vector<string> arr;
	arr.push_back("geeksquiz");
	arr.push_back("geeksforgeeks");
	arr.push_back("abcd");
	arr.push_back("forgeeksgeeks");
	arr.push_back("zuiqkeegs");
	arr.push_back("cat");
	arr.push_back("act");
	arr.push_back("tca");

	StoreAnagrams(arr);
	return 0;
}