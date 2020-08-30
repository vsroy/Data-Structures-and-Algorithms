/*Given an array containing N words consisting of lowercase characters. Your task is to find the most frequent word in the array. 
If multiple words have same frequency, then print the word whose first occurence occurs last in the array as compared 
to the other strings with same frequency.*/
#include<iostream>
#include<string>
#include<unordered_map>
using namespace std;

string MostStringOccurrences(vector<string> ipVect)
{
	unordered_map<string, int> hashString;

	//Put all strings inside ipVect and increase count
	for (int i = 0; i < ipVect.size(); i++)
		hashString[ipVect[i]]++;

	//Now count the number of occurrences from the hash map
	int max_freq = INT_MIN;
	string maxString;
	unordered_map<string, int>::iterator it;
	for (it = hashString.begin(); it != hashString.end(); it++)
	{
		if (it->second > max_freq)
		{
			max_freq = it->second;
			maxString = it->first;
		}
	}
	return maxString;
}

int main()
{
	vector<string> ipVect{ "geeks", "for", "geeks", "a",
		"portal", "to", "learn", "can", "be",
		"computer", "science", "zoom", "yup",
		"fire", "in", "be", "data", "geeks" };
	cout << MostStringOccurrences(ipVect);
	return 0;
}