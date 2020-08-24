/*Given an array of integers. Complete the partition() function used for the implementation of Quick Sort.*/
#include<iostream>
#include<vector>
using namespace std;

void Swap(int&a, int& b)
{
	int temp = a;
	a = b;
	b = temp;
}

int Partition(vector<int>& ipVect, int low, int high)
{
	int pivot = ipVect[high];

	int i = low-1;
	for (int j = low; j < high; j++)
	{
		if (ipVect[j] < pivot)
		{
			i++;
			Swap(ipVect[i], ipVect[j]);
		}
	}
	i++;

	//The elements are partitioned around the pivot after this swap
	Swap(ipVect[i], ipVect[high]);
	return i;
}

void QuickSort(vector<int>& ipVect, int low, int high)
{
	if (low < high)
	{
		int mid = Partition(ipVect, low, high);
		QuickSort(ipVect, low, mid - 1);
		QuickSort(ipVect, mid + 1, high);
	}
}

void PrintArray(vector<int>& ipVect)
{
	for (int i = 0; i < ipVect.size(); i++)
		cout << ipVect[i] << " ";
}

int main()
{
	vector<int> ipVect{ 10, 7, 8, 9, 1, 5 };
	int low = 0, high = ipVect.size() - 1;
	QuickSort(ipVect, low, high);
	PrintArray(ipVect);
	return 0;
}