/*Given two arrays of integers, write a program to check if a pair of values (one value from each array) exists 
such that swapping the elements of the pair will make the sum of two arrays equal.*/
#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int Sum(vector<int> vect1)
{
	int sum = 0;
	for (int i = 0; i < vect1.size(); i++)
		sum += vect1[i];
	return sum;
}

int GetTarget(vector<int> vect1, vector<int> vect2)
{
	// Calculation of sums from both arrays 
	int sum1 = Sum(vect1);
	int sum2 = Sum(vect2);

	// because that the target must be an integer 
	if ((sum1 - sum2) % 2 != 0)
		return 0;
	else
		return ((sum1 - sum2) / 2);
}

void FindPairSwapValues(vector<int> vect1, vector<int> vect2)
{
	//Sort the vectors first
	sort(vect1.begin(), vect1.end());
	sort(vect2.begin(), vect2.end());

	// Note that target can be negative 
	int target = GetTarget(vect1, vect2);

	if (target == 0)
		return;

	int i = 0, j = 0;
	while (i < vect1.size() && j < vect2.size())
	{
		int diff = vect1[i] - vect2[j];
		if (diff == target)
		{
			cout << vect1[i] << " " << vect2[j];
			return;
		}
		// Look for a greater value in vect1
		else if (diff < target)
			i++;
		// Look for a greater value in vect2
		else
			j++;
	}
}

int main()
{
	vector<int> vect1{ 4, 1, 2, 1, 1, 2 };
	vector<int> vect2{ 1, 6, 3, 3 };

	FindPairSwapValues(vect1, vect2);
	
	return 0;
}