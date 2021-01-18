/*Perform basic operations on a binary heap*/
#include<iostream>
#include<vector>
using namespace std;

void Swap(int& a, int& b)
{
	int temp = a;
	a = b;
	b = temp;
}

void PrintHeapElements(vector<int>& ipVect)
{
	cout << "\n Heap Elements are ";
	for (int i = 0; i < ipVect.size(); i++)
		cout << ipVect[i] << " ";
}

int parent(int child)
{
	return (child - 1) / 2;
}

void Heapify(vector<int>& ipVect, int i, int n)
{
	int largest = i;
	int leftChild = 2 * i + 1;
	int rightChild = 2 * i + 2;

	if (leftChild < n && ipVect[leftChild] > ipVect[largest])
		largest = leftChild;

	if (rightChild  < n && ipVect[rightChild] > ipVect[largest])
		largest = rightChild;

	if (largest != i)
	{
		Swap(ipVect[i], ipVect[largest]);
		//recursively heapify for the largets child
		Heapify(ipVect, largest, n);
	}
}

void ExtactMin(vector<int>& ipVect)
{
	int n = ipVect.size();

	//Storing the min element so that we can return it later
	int minElement = ipVect[0];

	//Swapping the first and last elements so that we can pop out the min element
	Swap(ipVect[0], ipVect[n - 1]);
	ipVect.pop_back();
	n--;

	Heapify(ipVect, n, 0);
}

void DecreaseKey(vector<int>& ipVect, int i, int new_val)
{
	ipVect[i] = new_val;
	while (i != 0 && ipVect[parent(i)] > ipVect[i])
	{
		Swap(ipVect[parent(i)], ipVect[i]);
		i = parent(i);
	}
}

void DeleteKey(vector<int>& ipVect, int i)
{
	DecreaseKey(ipVect, i, INT_MIN);
	ExtactMin(ipVect);
}

void HeapSort(vector<int>& ipVect)
{
	int n = ipVect.size();

	//First perform the heapify operation. Build the heap
	for (int i = n / 2 - 1; i >= 0; i--)
		Heapify(ipVect, i, n);

	for (int i = n - 1; i > 0; i--)
	{
		//For every iteration, the largest element in the vector will be kept at position i
		swap(ipVect[0], ipVect[i]);

		//Call Heapify the reduced heap
		Heapify(ipVect, 0, i);
	}
}

void KthLargestElement(vector<int>& ipVect, int k)
{
	if (ipVect.size() < k)
		cout << "\nNumber of elements in the heap is less than k so no kth largest element";
	else
	{
		cout << "\nKth Largest Element is " << ipVect[ipVect.size() - k];
	}
}

void InsertElement(vector<int>& ipVect, int x)
{
	ipVect.push_back(x);

	//Insert element at the end of heap
	int i = ipVect.size() - 1;

	//While parent is greater than the child which should not be the case of a min heap,
	//Swap parent and child
	while (i != 0 && ipVect[parent(i)] > ipVect[i])
	{
		Swap(ipVect[parent(i)], ipVect[i]);
		i = parent(i);
	}
	HeapSort(ipVect);
	//PrintHeapElements(ipVect);
	KthLargestElement(ipVect, 4);
}

int main()
{
	vector<int> ipVect;
	InsertElement(ipVect, 1);
	InsertElement(ipVect, 2);
	InsertElement(ipVect, 3);
	InsertElement(ipVect, 4);
	InsertElement(ipVect, 5);
	InsertElement(ipVect, 6);
	return 0;
}