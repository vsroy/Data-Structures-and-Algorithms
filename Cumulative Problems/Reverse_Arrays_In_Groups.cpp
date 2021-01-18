/*Given an array arr[] of positive integers of size N. Reverse every sub-array of K group elements.*/

#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

void swap(int& a, int& b)
{
	int temp = a;
	a = b;
	b = temp;
}

void reverseInGroups(vector<int>& ipArray, int k)
{
	int n = ipArray.size() - 1;
	for (int i = 0; i < ipArray.size(); i += k)
	{
		int left = i;

		// to handle case when k is not multiple of n 
		int right = min(i + k - 1, n);

		while (left < right)
			swap(ipArray[left++], ipArray[right--]);
	}
}

int main()
{
	vector<int> ipArray{ 1, 2, 3, 4, 5, 6, 7, 8 };
	reverseInGroups(ipArray, 3);
	for (auto i : ipArray)
		cout << i << " ";
	return 0;
}