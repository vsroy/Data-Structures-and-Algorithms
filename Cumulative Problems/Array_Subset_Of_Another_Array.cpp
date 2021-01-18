/*Given two arrays: arr1[0..m-1] of size m and arr2[0..n-1] of size n. Task is to check whether arr2[] is a subset of arr1[] or not. 
Both the arrays can be both unsorted or sorted. It may be assumed that elements in both array are distinct.*/
#include<iostream>
#include<vector>
#include<map>
using namespace std;

bool CheckSubset(vector<int> vect1, vector<int> vect2)
{
	map<int, int> hashMap;
	
	if (vect2.size() > vect1.size())
		return false;

	//First hash the count of the elements on vect1 in hashMap
	for (int i = 0; i < vect1.size(); i++)
		hashMap[vect1[i]]++;

	//Not traverse vect2 and check if every element exists in hashmap and reduce the count
	for (int i = 0; i < vect2.size(); i++)
	{
		if (hashMap.find(vect2[i]) != hashMap.end())
		{
			if (hashMap[vect2[i]] == 0)
				return false;
			else
				hashMap[vect2[i]]--;
		}
		else
			return false;
	}
	return true;
}


int main()
{
	vector<int> vect1{ 10, 5, 2, 23, 19 };
	vector<int> vect2{ 19, 5, 3 };
	cout << CheckSubset(vect1, vect2);
	return 0;
}