/*Given two arrays of integers, compute the pair of values (one value in each array) with the smallest (non-negative) difference. Return the difference.*/
#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int FindSmallestDifference(vector<int> vect1, vector<int> vect2)
{
	int m = vect1.size();
	int n = vect2.size();
	
	//First sort the vectors	
	sort(vect1.begin(),vect1.end());
	sort(vect2.begin(),vect2.end());
	
	//Initialize counters
	int i=0, j=0;
	
	int res = INT_MAX;
	while(i < m && j < n)
	{
		int diff = abs(vect1[i]-vect2[j]);
		res = min(res, diff);
		
		if(vect1[i] < vect2[j])
			i++;
		else
			j++;			
	}
	return res;
}

int main()
{
	vector<int> vect1{1, 2, 11, 5};
	vector<int> vect2{4, 12, 19, 23, 127, 235};
	
	cout <<  FindSmallestDifference(vect1, vect2);

	return 0;
}