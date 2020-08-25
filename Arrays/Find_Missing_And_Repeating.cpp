/*Given an unsorted array of size N of positive integers. One number 'A' from set {1, 2, …N} is missing and one number 'B' occurs twice in array. 
Find these two numbers.*/
//Solution
/*Traverse the array. While traversing, use the absolute value of every element as an index and make the value at this 
index as negative to mark it visited. If something is already marked negative then this is the repeating element. 
To find missing, traverse the array again and look for a positive value.*/
#include<iostream>
#include<vector>
using namespace std;

void PrintMissingRepeatingElements(vector<int>& ipVect)
{
	for (int i = 0; i < ipVect.size(); i++)
	{
		//Find the index which we will make negative
		int index = abs(ipVect[i]) - 1;
		if (ipVect[index] > 0)
			ipVect[index] = -ipVect[index];
		//Already found a negative value at the index. Index is the answer.
		else
			cout << "Repeating element is " << abs(index) + 1 << endl;
	}

	for (int i = 0; i < ipVect.size(); i++)
		if (ipVect[i] > 0)
			cout << "Missing element is " << i + 1;
}

int main()
{
	vector<int> ipVect{ 7, 3, 4, 5, 5, 6, 2 };
	PrintMissingRepeatingElements(ipVect);
	return 0;
}