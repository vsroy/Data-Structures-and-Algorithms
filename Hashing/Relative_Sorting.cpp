/*Given two arrays A1[] and A2[] of size N and M respectively. The task is to sort A1 in such a way that the relative order 
among the elements will be same as those in A2. For the elements not present in A2, append them at last in sorted order. 
It is also given that the number of elements in A2[] are smaller than or equal to number of elements in A1[] and A2[] has all distinct elements.*/

#include<iostream>
#include<vector>
#include<map>
using namespace std;

void RelativeSort(vector<int>& vect1, vector<int>& vect2)
{
	map<int, int> relativeMap;

	//Storing the frequencies of the elements in the first vector
	for (int i = 0; i < vect1.size(); i++)
		relativeMap[vect1[i]]++;

	vect1.clear();

	//Now traversing the second vector and retrieving the elements from the map
	for (int i = 0; i < vect2.size(); i++)
	{
		while (relativeMap[vect2[i]] != 0)
		{
			vect1.push_back(vect2[i]);
			relativeMap[vect2[i]]--;
		}
	}

	//Pushing the remaining elements from the map
	map<int, int>::iterator it;
	for (it = relativeMap.begin(); it != relativeMap.end(); it++)
	{
		while (it->second != 0)
		{
			vect1.push_back(it->first);
			it->second--;
		}
	}
}

int main()
{
	vector<int> vect1{ 2, 6, 7, 5, 2, 6, 8, 4 };
	vector<int> vect2{ 2, 6, 4, 5 };

	RelativeSort(vect1, vect2);

	for (int i = 0; i < vect1.size(); i++)
		cout << vect1[i] << " ";

	return 0;
}