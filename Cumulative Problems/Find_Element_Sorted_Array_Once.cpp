/*Given a sorted array A, size N, of integers; every element appears twice except for one. Find that element that appears once in array.*/

/*An Efficient Solution can find the required element in O(Log n) time. The idea is to use Binary Search. Below is an observation in the input array.
All elements before the required have the first occurrence at even index (0, 2, ..) and next occurrence at odd index (1, 3, …). 
And all elements after the required elements have the first occurrence at odd index and next occurrence at even index.*/

#include<iostream>
#include<vector>
using namespace std;

void Search(vector<int>& ipVect, int low, int high)
{
	if (low > high)
		return;

	if (low == high)
	{
		cout << "Required element is " << ipVect[low];
		return;
	}

	int mid = (low + high) / 2;

	// If mid is even and element next to mid is 
	// same as mid, then output element lies on 
	// right side, else on left side 
	if (mid % 2 == 0)	//Mid is even, we will check next element
	{
		if (ipVect[mid] == ipVect[mid + 1])
			Search(ipVect, mid + 2, high);
		else
			Search(ipVect, low, mid);
	}
	else
	{
		if (ipVect[mid] == ipVect[mid - 1])
			Search(ipVect, mid + 1, high);
		else
			Search(ipVect, low, mid - 1);
	}
}
 
int main()
{
	vector<int> ipVect{ 1, 1, 3, 3, 4, 5, 5, 7, 7, 8, 8 };
	Search(ipVect,0,ipVect.size()-1);
	return 0;
}