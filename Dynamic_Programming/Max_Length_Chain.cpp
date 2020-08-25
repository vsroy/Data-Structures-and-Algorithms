/*You are given N pairs of numbers. In every pair, the first number is always smaller than the second number. 
A pair (c, d) can follow another pair (a, b) if b < c. Chain of pairs can be formed in this fashion. 
You have to find the longest chain which can be formed from the given set of pairs. */
#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

bool PairSort(pair<int, int> pair1, pair<int, int>pair2)
{
	return pair1.first < pair2.first;
}

int MaxLengthChain(vector<pair<int,int>> ipvect)
{
	int size = ipvect.size();

	//Initializing a vector where max length chain till each element is 1
	vector<int> dpVect;
	for (int i = 0; i < ipvect.size(); i++)
		dpVect.push_back(1);

	//Sort the vector on the basis of the second element of each pair
	sort(ipvect.begin(), ipvect.end(), PairSort);

	//Traverse the chain array twice and compare each pair and update the max length chain array till that element
	for (int i = 1; i < size; i++)
	{
		for (int j = 0; j < i; j++)
		{
			if (ipvect[j].second < ipvect[i].first && dpVect[i] < dpVect[j] + 1)
				dpVect[i] = dpVect[j] + 1;
		}	
	}

	//Noe traverse the mcl array and pick the largest of all the values
	int res = INT_MIN;

	for (int i = 0; i < size; i++)
		if (dpVect[i] > res)
			res = dpVect[i];

	return res;
}

int main()
{
	vector<pair<int, int>> ipVect{ { 5, 24 }, { 15, 25 }, { 27, 40 }, { 50, 60 } };
	cout << MaxLengthChain(ipVect);
	return 0;
}