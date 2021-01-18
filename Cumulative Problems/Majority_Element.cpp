/*Given an array A of N elements. Find the majority element in the array. A majority element in an array A of size N is an 
element that appears more than N/2 times in the array.*/
//Solution - using Moore's voting algorithm
//https://www.geeksforgeeks.org/majority-element/
#include<iostream>
#include<vector>
using namespace std;

int FindMajorityElement(vector<int> ipvect)
{
	int size = ipvect.size();

	int majority_index = 0, count = 1;
	for (int i = 1; i < size; i++)
	{
		if (ipvect[i] == ipvect[majority_index])
			count++;
		else
			count--;
		if (count == 0)
		{
			majority_index = i;
			count = 1;
		}
	}

	int candidate = ipvect[majority_index];
	count = 0;
	//We got the index now, we have to check occurrences
	for (int i = 0; i < size; i++)
	{
		if (ipvect[i] == candidate)
		{
			count++;
			if (count > size / 2)
				return candidate;
		}
	}
	return -1;
}

int main()
{
	vector<int> ipVect{ 2, 2, 2, 2, 5, 5, 2, 3, 3 };
	cout << FindMajorityElement(ipVect);
	return 0;
}