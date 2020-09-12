/*Program to construct a Min Heap*/
#include<iostream>
#include<vector>
using namespace std;

void Swap(int& a, int& b)
{
	int temp = a;
	a = b;
	b = temp;
}

void MinHeapifyUtil(vector<int>& arr, int index, int size)
{
	int smallest = index;
	int rChild = 2*index+1;
	int lChild = 2*index+2;

	if(arr[lChild] < arr[index] && lChild < size)
		smallest = lChild;
	if(arr[rChild] < arr[smallest] && rChild < size)
		smallest = rChild;

	if(index != smallest)
	{
		Swap(arr[index],arr[smallest]);
		MinHeapifyUtil(arr, smallest, size);
	}

}

void MinHeapify(vector<int> arr)
{
	int n = arr.size();
	for (int i = n / 2 - 1; i >= 0; i--)
		MinHeapifyUtil(arr, i, n);

	//Now perform heap sort
	for(int i=n-1;i>=0;i--)
	{
		Swap(arr[0],arr[i]);
		MinHeapifyUtil(arr, 0, i);
	}
}

int main()
{
	vector<int> arr{12, 11, 13, 5, 6, 7};
	MinHeapify(arr);
	return 0;
}