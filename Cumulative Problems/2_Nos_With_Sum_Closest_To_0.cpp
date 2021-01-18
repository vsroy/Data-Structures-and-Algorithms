/*Given an integer array A of N elements. You need to find the sum of two elements such that sum is closest to zero.*/
#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;

bool compare(int x, int y)
{
	return abs(x) < abs(y);
}

void FindMinSum(vector<int>& ipVect)
{
	int n = ipVect.size();
	int min_sum = INT_MAX;

	//First sort the elements according to their absolute value
	sort(ipVect.begin(), ipVect.end(), compare);

	int first = 0, second = 0;
	for (int i = 1; i < n; i++)
	{
		// Absolute value shows how close it is to zero 
		if (abs(ipVect[i] + ipVect[i - 1]) <= min_sum)
		{
			// if found an even close value 
			// update min and store the index 
			min_sum = abs(ipVect[i] + ipVect[i - 1]);
			first = i - 1, second = i;
		}
	}
	cout << "The elements which form the min sum are " << ipVect[first] << " and " << ipVect[second] << endl;
	cout << "The sum of these elements are " << min_sum;
}

int main()
{
	vector<int> ipvect{ 1, 60, -10, 70, -80, 85 };
	FindMinSum(ipvect);
	return 0;
}