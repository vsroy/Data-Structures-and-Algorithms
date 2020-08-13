/*Given two unsorted arrays A of size N and B of size M of distinct elements, the task is to find all pairs from both arrays whose sum is equal to X.*/
#include<iostream>
#include<unordered_set>
using namespace std;

void FindAllPairs(vector<int> vect1, vector<int> vect2, int k)
{
	unordered_set<int> hashSet;
	
	//Navigate first vector and insert into the hash set
	for (int i = 0; i < vect1.size(); i++)
		hashSet.insert(vect1[i]);

	//Traverse second vector and find the corresponding number in first vector
	for (int i = 0; i < vect2.size(); i++)
	{
		if (hashSet.find(k - vect2[i]) != hashSet.end())
			cout << k - vect2[i] << " " << vect2[i] << endl;
	}
}

int main()
{
	vector<int> vect1{ 0,2 };
	vector<int> vect2{ 1,3 };
	FindAllPairs(vect1, vect2, 3);
	return 0;
}