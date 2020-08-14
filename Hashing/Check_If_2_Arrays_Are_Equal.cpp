/*Given two arrays A and B of equal size, the task is to find if given arrays are equal or not. Two arrays are said to be equal if 
both of them contain same set of elements, arrangements (or permutation) of elements may be different though.*/
#include<iostream>
#include<vector>
#include<map>
using namespace std;

bool CheckArrayEquality(vector<int> vect1, vector<int> vect2)
{
	if (vect1.size() != vect2.size())
		return false;

	map<int, int> hashMap;
	
	//Traverse both the vectors and increase/decrease the element count in the hash map
	for (int i = 0; i < vect1.size(); i++)
	{
		hashMap[vect1[i]]++;
		hashMap[vect2[i]]--;
	}

	//Traverse the hash map. The cumulative count of all elements in the hashmap should be 0
	map<int, int>::iterator it;
	for (it = hashMap.begin(); it != hashMap.end(); it++)
	{
		if (it->second != 0)
			return false;
	}
	return true;
}

int main()
{
	vector<int> vect1{ 1, 2, 5, 4, 0 };
	vector<int> vect2{ 2, 8, 5, 0, 1 };
	cout << CheckArrayEquality(vect1,vect2);
	return 0;
}