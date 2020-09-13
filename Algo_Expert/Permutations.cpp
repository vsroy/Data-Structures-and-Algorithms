/*Write a function that takes in an array of unique integers and returns an array of all permutations of those integers. If the input array is empty, your function should return an empty array.*/

#include<iostream>
#include<string>
#include<vector>
using namespace std;

void Swap(int& a, int& b)
{
	int temp = a;
	a = b;
	b = temp;
}

void PrintArray(vector<int>& arr)
{
	for (auto i : arr)
		cout << i << " ";
	cout << endl;
		
}

void PrintPermutations(vector<int> arr, int left, int right)
{
	if (left == right)
		PrintArray(arr);
	else
	{
		for (int i = left; i <= right; i++)
		{
			//Swap the fixed element and go for the next
			Swap(arr[i],arr[left]);

			//Swapping done
			PrintPermutations(arr, left + 1,right);

			//Backtrack
			Swap(arr[i], arr[left]);
		}
	}
}

int main()
{
	vector<int> arr{1,2,3};
	PrintPermutations(arr, 0, arr.size() - 1);
	return 0;
}