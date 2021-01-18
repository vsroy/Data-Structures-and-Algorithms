/*Given an array A[] of integers, sort the array according to frequency of elements. That is elements that have higher frequency come first. 
If frequencies of two elements are same, then smaller number comes first.*/
#include<iostream>
#include<vector>
#include<unordered_map>
#include<algorithm>
using namespace std;

bool fcompare(pair<int, pair<int, int> > p,
	pair<int, pair<int, int> > p1)
{
	if (p.second.second != p1.second.second)
		return (p.second.second > p1.second.second);
	else
		return (p.second.first < p1.second.first);
}

void SortElementsByFrequencies(vector<int>& ipVect)
{
	unordered_map<int, pair<int, int> > hashMap; // hash map 
	for (int i = 0; i < ipVect.size(); i++)
	{
		if (hashMap.find(ipVect[i]) != hashMap.end())
			hashMap[ipVect[i]].second++;
		else
			hashMap[ipVect[i]] = make_pair(i, 1);
	}// store the count of all the elements in the hashmap 


	// Iterator to Traverse the Hashmap 
	auto it = hashMap.begin();

	// Vector to store the Final Sortted order 
	vector<pair<int, pair<int, int> > > hashVect;
	for (it; it != hashMap.end(); ++it)
		hashVect.push_back(make_pair(it->first, it->second));

	sort(hashVect.begin(), hashVect.end(), fcompare);

	// Printing the Sorted sequence 
	for (int i = 0; i < hashVect.size(); i++)
	{
		int count = hashVect[i].second.second;
		while (count--)
			cout << hashVect[i].first << " ";
	}
}

int main()
{
	vector<int> ipVect{ 2, 5, 2, 6, -1, 5, 8, 8, 8 };
	SortElementsByFrequencies(ipVect);
	return 0;
}