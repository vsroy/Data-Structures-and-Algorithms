/*Given an array of integers, write a function that returns true if there is a triplet (a, b, c) that satisfies a2 + b2 = c2.*/
#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

bool TripletExists(vector<int> ipVect)
{
	int n = ipVect.size();
	//First replace the elements by their squares
	for (int i = 0; i < n; i++)
		ipVect[i] = ipVect[i] * ipVect[i];

	//Then sort the array
	sort(ipVect.begin(), ipVect.end());

	//Start from the end of the array and for every element find the pair that equates to it
	for (int i = n - 1; i >= 2; i--)
	{
		int start = 0, end = i - 1;
		while (start < end)
		{
			if (ipVect[start] + ipVect[end] == ipVect[i])
				return true;
			else
			{
				if (ipVect[start] + ipVect[end] < ipVect[i])
					start++;
				else
					end--;
			}
		}
	}
	return false;
}

int main()
{
	vector<int> ipVect{ 3, 1, 4, 6, 5 };
	cout << TripletExists(ipVect);
	return 0;
}