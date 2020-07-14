/*Given an array A of N positive numbers. The task is to find the position where equilibrium first occurs in the array. 
Equilibrium position in an array is a position such that the sum of elements before it is equal to the sum of elements after it.*/

#include<iostream>
#include<vector>
using namespace std;

int equilibrium(vector<int> ipVect)
{
	int totalSum = 0;
	
	for (int i = 0; i < ipVect.size(); i++)
		totalSum += ipVect[i];

	/*Once we have total sum add the left sum for every element and and subtract left element from total sum*/
	int totalSumSec = 0;
	for (int i = 0; i < ipVect.size(); i++)
	{
		/*Remaining sum is sum to the right of i*/
		totalSum -= ipVect[i];
		if (totalSumSec == totalSum)
			return i;
		totalSumSec += ipVect[i];
	}
	return -1;
}

int main()
{
	vector<int> ipVect{ -7, 1, 5, 2, -4, 3, 0 };
	cout << equilibrium(ipVect);
	return 0;
}