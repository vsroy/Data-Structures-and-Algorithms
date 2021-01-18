/*Given an array A (distinct elements) of size N. Rearrange the elements of array in zig-zag fashion. 
The converted array should be in form a < b > c < d > e < f. The relative order of elements is same in the 
output i.e you have to iterate on the original array only.*/

#include<iostream>
#include<vector>
using namespace std;

void swap(int& a, int& b)
{
	int temp = a;
	a = b;
	b = temp;
}

void ConvertToZigZag(vector<int>& ipArray)
{
	bool flag = true;
	/*
	'<' for true
	'>' for false
	*/
	for (int i = 0; i < ipArray.size() - 1; i++)
	{
		if (flag)
		{
			if (ipArray[i] > ipArray[i + 1])
				swap(ipArray[i], ipArray[i + 1]);
		}
		else
		{
			if (ipArray[i] < ipArray[i + 1])
				swap(ipArray[i], ipArray[i + 1]);
		}
		flag = !flag;
	}
}

int main()
{
	vector<int> ipVect{ 4, 3, 7, 8, 6, 2, 1};
	ConvertToZigZag(ipVect);

	for (auto i : ipVect)
		cout << i << " ";
	return 0;
}