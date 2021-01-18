/*Given an array of integers where each value 1 <= x <= len(array), write a function that finds all the duplicates in the array.*/
#include<iostream>
#include<vector>
using namespace std;

void PrintDuplicates(vector<int> arr)
{
	//To find duplicates, we negate values if they are positive. If we find that a value is already negative, we print it as we have 
	//encountered it before
	cout << "Repeated elements are ";
	for (int i = 0; i < arr.size(); i++)
	{
		int index = abs(arr[i])-1;
		if (arr[index] < 0)
			cout << index + 1 << " ";
		else
			arr[index] = -arr[index];
	}

	cout << "\nMissing elements are";
	for (int i = 0; i < arr.size(); i++)
	{
		if (arr[i] >= 0)
			cout << i + 1 << " ";
	}
}

int main()
{
	vector<int> arr{3,3,3};
	PrintDuplicates(arr);
	return 0;
}