/*Given a sorted and rotated array A of N distinct elements which is rotated at some point, and given an element K. 
The task is to find the index of the given element K in the array A.*/
#include<iostream>
#include<vector>
using namespace std;

int SearchInRotatedArray(vector<int>& ipVect, int low, int high, int key)
{
	if (low > high)
		return -1;

	int mid = (low + high) / 2;
	//Found the key
	if (key == ipVect[mid])
		return mid;

	//Check if left array is sorted
	if (ipVect[low] <= ipVect[mid])
	{
		//We can easily check if key lies in left sorted array by comparing key values with low and mid
		if (key >= ipVect[low] && key <= ipVect[mid])
			SearchInRotatedArray(ipVect, low, mid - 1, key);
		else
			SearchInRotatedArray(ipVect, mid + 1, high, key);
	}
	//Right array must be sorted
	else
	{
		if (key >= ipVect[mid] && key <= ipVect[high])
			SearchInRotatedArray(ipVect, mid + 1, high, key);
		else
			SearchInRotatedArray(ipVect, low, mid - 1, key);
	}
}

int main()
{
	vector<int> ipVect{ 4, 5, 6, 7, 8, 9, 1, 2, 3 };

	int low = 0, high = ipVect.size() - 1;
	cout << SearchInRotatedArray(ipVect, low, high, 6);
	return 0;
}