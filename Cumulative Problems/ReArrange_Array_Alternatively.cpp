/*Given a sorted array of positive integers, rearrange the array alternately i.e first element 
should be the maximum value, second minimum value, third-second max, fourth-second min and so on.*/

#include<iostream>
#include<vector>
using namespace std;

// Prints max at first position, min at second position 
// second max at third position, second min at fourth 
// position and so on. 
void rearrange(vector<int>& arr)
{
	int n = arr.size();
	// initialize index of first minimum and first 
	// maximum element 
	int max_idx = n - 1, min_idx = 0;

	// store maximum element of array 
	int max_elem = arr[n - 1] + 1;

	// traverse array elements 
	for (int i = 0; i < n; i++) {
		// at even index : we have to put maximum element 
		if (i % 2 == 0) {
			arr[i] += (arr[max_idx] % max_elem) * max_elem;
			max_idx--;
		}

		// at odd index : we have to put minimum element 
		else {
			arr[i] += (arr[min_idx] % max_elem) * max_elem;
			min_idx++;
		}
	}

	// array elements back to it's original form 
	for (int i = 0; i < n; i++)
		arr[i] = arr[i] / max_elem;
}

int main()
{
	vector<int> ipVect{ 1, 2, 3, 4, 5, 6, 7, 8, 9 };
	rearrange(ipVect);


	for (auto i : ipVect)
		cout << i << " ";
	return 0;
}