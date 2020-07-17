// C++ program to find maximum amount of water that can 
// be trapped within given set of bars. 
// Space Complexity : O(1) 

#include<iostream>
#include<vector>
using namespace std;

int findWater(vector<int> waterVect)
{
	int n = waterVect.size();
	
	//Array pointers that will traverse from left and right till they meet
	int low = 0;
	int high = n - 1;

	//Variables to store the max from left and max from right
	int max_left = 0;
	int max_right = 0;

	int result = 0;

	//Calculate the water trapped in the smaller element out of low and high first and then move accordingly
	while (low <= high)
	{
		if (waterVect[low] < waterVect[high])
		{
			if (waterVect[low] > max_left)
				max_left = waterVect[low];
			else
				result += max_left - waterVect[low];
			low++;
		}
		else
		{
			if (waterVect[high] > max_right)
				max_right = waterVect[high];
			else
				result += max_right - waterVect[high];
			high--;
		}
	}
	return result;
}

int main()
{
	vector<int> waterVect{ 0, 1, 0, 2, 1, 0, 1, 3, 2, 1, 2, 1 };
	cout << findWater(waterVect);
	return 0;
}
