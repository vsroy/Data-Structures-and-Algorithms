/*Given an array A and an integer K. Find the maximum for each and every contiguous subarray of size K.*/
#include<iostream>
#include<deque>
#include<vector>
using namespace std;

void PrintKMax(vector<int>& ipVect, int k)
{
	// Create a Double Ended Queue, Qi that will store indexes of array elements 
	// The queue will store indexes of useful elements in every window and it will 
	// maintain decreasing order of values from front to rear in Qi, i.e., 
	// arr[Qi.front[]] to arr[Qi.rear()] are sorted in decreasing order 
	deque<int> kMaxQ(k);

	/* Process first k (or first window) elements of array */
	int i;
	for (i = 0; i < k; ++i)
	{
		// For every element, the previous smaller elements are useless so 
		// remove them from Qi 
		while (!kMaxQ.empty() && ipVect[i] >= ipVect[kMaxQ.back()])
			kMaxQ.pop_back();	//Remove from rear

		//Add new element to the rear of the Q
		kMaxQ.push_back(i);
	}

	// Process rest of the elements, i.e., from arr[k] to arr[n-1] 
	for (; i < ipVect.size(); ++i)
	{
		// The element at the front of the queue is the largest element of 
		// previous window, so print it 
		cout << ipVect[kMaxQ.front()] << " ";

		//Remove the elements which are out of this window
		while ((!kMaxQ.empty()) && kMaxQ.front() <= i - k)
			kMaxQ.pop_front(); // Remove from front of queue 

		// Remove all elements smaller than the currently 
		// being added element (remove useless elements) 
		while ((!kMaxQ.empty()) && ipVect[i] >= ipVect[kMaxQ.back()])
			kMaxQ.pop_back();

		// Add current element at the rear of Qi 
		kMaxQ.push_back(i);
	}

	// Print the maximum element of last window 
	cout << ipVect[kMaxQ.front()];
}

int main()
{
	vector<int> ipVect{ 12, 1, 78, 90, 57, 89, 56 };
	PrintKMax(ipVect, 3);
	return 0;
}