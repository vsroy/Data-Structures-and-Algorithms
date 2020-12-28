/*Given a sequence A of size N, find the length of the longest increasing subsequence from a given sequence .
The longest increasing subsequence means to find a subsequence of a given sequence in which the subsequence's elements are in sorted order, 
lowest to highest, and in which the subsequence is as long as possible. This subsequence is not necessarily contiguous, or unique.*/
#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int LongestIncreasingSubsequence(vector<int> vect1)
{
	int size = vect1.size();
	vector<int> dpVect(size,0);

	//Fill the dp array all with 1's
	for (int i = 0; i < size; i++)
		dpVect[i] = 1;

	for (int i = 1; i < size; i++)
	{
		for (int j = 0; j < i; j++)
		{
			if (vect1[i] > vect1[j] && dpVect[j] + 1 > dpVect[i])
				dpVect[i] = dpVect[j] + 1;
		}
	}

	//Find out the max element that will give length of the longest increasing subsequence
	int max_element = INT_MIN;
	for (int i = 0; i < size; i++)
		max_element = max(max_element, dpVect[i]);
	return max_element;
}

int main()
{
	vector<int> ipVect{ 10, 22, 9, 33, 21, 50, 41, 60 };
	cout << LongestIncreasingSubsequence(ipVect);
	return 0;
}
