/*Given two arrays X and Y of positive integers, find number of pairs such that xy > yx (raised to power of) 
where x is an element from X and y is an element from Y.*/
//Solution to this program can be found in the link - https://www.geeksforgeeks.org/find-number-pairs-xy-yx/

#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int count(int x, vector<int>& vect2, vector<int>& countY)
{
	// If x is 0, then there cannot be any value in Y such that 
	// x^Y[i] > Y[i]^x 
	if (x == 0)
		return 0;

	// If x is 1, then the number of pais is equal to number of 
	// zeroes in Y[] 
	if (x == 1)
		return countY[0];

	
	// Find number of elements in Y[] with values greater than x 
	// upper_bound() gets address of first greater element in Y[0..n-1] 
	int totalElements = 0;
	for (int i = 0; i < vect2.size(); i++)
	{
		if (vect2[i] > x)
			totalElements++;
	}
	int ans = totalElements;

	// If we have reached here, then x must be greater than 1, 
	// increase number of pairs for y=0 and y=1 
	ans += countY[0] + countY[1];

	// Decrease number of pairs for x=2 and (y=4 or y=3) 
	if (x == 2)
		ans -= countY[3] + countY[4];

	// Increase number of pairs for x=3 and y=2 
	if (x == 3)
		ans += countY[2];

	return ans;
}

int countPairs(vector<int> vect1, vector<int> vect2)
{
	/*This stores the exception conditions. Counts of 0,1,2,3,4 of vect2*/
	vector<int> countY(5);

	for (int i = 0; i < vect2.size(); i++)
	{
		if (vect2[i] < 5)
			countY[vect2[i]]++;
	}

	//Sort vect2 so that we can do binary search for it
	sort(vect2.begin(), vect2.end());

	//Initizlize the result
	int total_pairs = 0;

	//Take every element of vect2 and count pairs with it
	for (int i = 0; i < vect1.size(); i++)
		total_pairs += count(vect1[i], vect2, countY);
	
	return total_pairs;
}

int main()
{
	vector<int> vect1{2,1,6};
	vector<int> vect2{1,5};

	cout << countPairs(vect1,vect2);
	return 0;
}