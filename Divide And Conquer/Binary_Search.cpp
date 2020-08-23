/*Given a sorted array of integers and a key to be searched in the array. Print the position of the key in the array, if present. 
If it's not present in the array, report it. */
#include<iostream>
#include<vector>
using namespace std;

int BinarySeacrh(vector<int>& ipVect, int low, int high, int key)
{
	if (low > high)
		return -1;

	int mid = (low + high) / 2;
	if (key == ipVect[mid])
		return mid;

	if (key < ipVect[mid])
		return BinarySeacrh(ipVect, low, mid - 1, key);
	else
		return BinarySeacrh(ipVect, mid + 1, high, key);
}

int main()
{
	vector<int> ipVect{ 2, 3, 4, 10, 40 };
	int low = 0, high = ipVect.size() - 1;
	cout << BinarySeacrh(ipVect, low, high, 10);
	return 0;
}