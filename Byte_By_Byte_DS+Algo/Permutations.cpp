/*Write a function that returns all permutations of a given list.*/
#include<iostream>
#include<vector>
using namespace std;

void Swap(int& a, int& b)
{
	int temp = a;
	a = b;
	b = temp;
}

void PrintVector(vector<int> arr)
{
	for (int i = 0; i < arr.size(); i++)
		cout << arr[i] << " ";
	cout << endl;
}

void FindPermutations(vector<int> arr, int left, int right)
{
	//Base Case
	if (left == right)
		PrintVector(arr);

	for (int i = left; i <= right; i++)
	{
		//Swapping done
		Swap(arr[i], arr[left]);

		//Recursion called
		FindPermutations(arr, left + 1, right);

		//Swapped back 
		Swap(arr[i], arr[left]);
	}
}

int main()
{
	vector<int> arr{1,2,3};
	
	FindPermutations(arr, 0, arr.size() - 1);
	
	return 0;
}