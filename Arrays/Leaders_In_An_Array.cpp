/*Given an array of positive integers. Your task is to find the leaders in the array.
Note: An element of array is leader if it is greater than or equal to all the elements to its right side. 
Also, the rightmost element is always a leader. */

#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

vector<int> leaders(vector<int> ipVect)
{
	vector<int> resultVect;
	int n = ipVect.size();

	int max_so_far = ipVect[n - 1];
	resultVect.push_back(max_so_far);

	for (int i = n - 2; i >= 0; i--)
	{
		if (ipVect[i] > max_so_far)
		{
			max_so_far = ipVect[i];
			resultVect.push_back(max_so_far);
		}
	}
	return resultVect;
}

int main()
{
	vector<int> ipVect{ 16, 17, 4, 3, 5, 2 };
	vector<int> resultVect = leaders(ipVect);

	reverse(resultVect.begin(), resultVect.end());

	for (auto i : resultVect)
		cout << i << " ";

	return 0;
}