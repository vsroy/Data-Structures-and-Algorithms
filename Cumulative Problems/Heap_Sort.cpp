/*Given an array of size N. The task is to sort the array elements by completing functions heapify() and buildHeap() 
which are used to implement Heap Sort.*/
#include<iostream>
#include<vector>
using namespace std;

void Swap(int& a, int& b)
{
	int temp = a;
	a = b;
	b = temp;
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

void Print(vector<int> ipVect)
{
	for (int i = 0; i < ipVect.size(); i++)
		cout << ipVect[i] << " ";
}

int main()
{
	vector<int> ipVect{ 12, 11, 13, 5, 6, 7 };
	HeapSort(ipVect);
	Print(ipVect);
	return 0;
}