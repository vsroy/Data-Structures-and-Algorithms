/*We are given two sorted array. We need to merge these two arrays such that the initial numbers (after complete sorting) 
are in the first array and the remaining numbers are in the second array. Extra space allowed in O(1).*/

#include<iostream>
#include<vector>
using namespace std;

void merge(vector<int>& vect1, vector<int>& vect2)
{
	int m = vect1.size();
	int n = vect2.size();

	/*Traverse vect 2 from end to start and then if there are any bigger elements in vect 1 , replace it with that*/
	for (int i = n - 1; i >= 0; i--)
	{
		int last = vect1[m - 1];
		int j;
		for (j = m - 2; j >= 0 && vect1[j] > vect2[i]; j--)
			vect1[j + 1] = vect1[j];

		//If there is a greater element
		if (j != m - 2 && last > vect2[i])
		{
			vect1[j + 1] = vect2[i];
			vect2[i] = last;
		}
	}
}

int main()
{
	vector<int> ipvect1{ 1, 5, 9, 10, 15, 20 };
	vector<int> ipvect2{ 2, 3, 8, 13 };
	merge(ipvect1, ipvect2);

	for (auto i : ipvect1)
		cout << i << " ";
	for (auto i : ipvect2)
		cout << i << " ";
	
	return 0;
}