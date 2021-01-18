/*Given an array C of size N-1 and given that there are numbers from 1 to N with one element missing, the missing number is to be found.*/
#include<iostream>
#include<vector>
using namespace std;

int getMissingNumber(vector<int> ipVect)
{ 
	int n = ipVect.size();
	int total = ((n + 1) * (n + 2)) / 2;

	int currSum = 0;
	for (int i = 0; i < ipVect.size(); i++)
		currSum += ipVect[i];
	total = total - currSum;

	//Alternate solution
	/*
	for (int i = 2; i <= (n + 1); i++)
	{
		total += i;
		total = total - ipVect[i - 2];
	}
	*/
	return total;
}

int main()
{
	vector<int> ipVect{ 1, 2, 3, 5 };
	cout << getMissingNumber(ipVect);
	return 0;
}