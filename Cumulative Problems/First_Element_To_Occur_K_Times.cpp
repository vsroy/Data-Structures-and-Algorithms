/*Given an array of N integers. The task is to find the first element that occurs K number of times. If no element occurs K times the print -1.*/
#include<iostream>
#include<unordered_map>
#include<vector>
using namespace std;

int FirstElementKtimes(vector<int> vect1, int k)
{
	unordered_map<int, int> hashMap;

	for (int i = 0; i < vect1.size(); i++)
		hashMap[vect1[i]]++;

	unordered_map<int, int>::iterator it;
	for (it = hashMap.begin(); it != hashMap.end(); it++)
	{
		if (it->second == k)
			return it->first;
	}
	return -1;
}

int main()
{
	vector<int> ipVect{ 1, 7, 4, 3, 4, 8, 7 };
	cout << FirstElementKtimes(ipVect,2);
	return 0;
}