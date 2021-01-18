/*Given an array and a value, find if there is a triplet in array whose sum is equal to the given value. If there is such a triplet present in array, then print the triplet and return true. Else return false.*/
#include<iostream>
#include<unordered_set>
using namespace std;

bool FindTripletSum(vector<int> ipVect, int sum)
{
	int n = ipVect.size();
	//First loop through the elements
	for(int i=0;i<n-2;i++)
	{
		unordered_set<int> hashSet;
		//Initialize a set to store dictionary values
		//We fix i for the current loop. We loop from i+1
		for(int j=i+1;j<n;j++)
		{
			int currSum = -(ipVect[i] + ipVect[j]);
			if(hashSet.find(sum + currSum) != hashSet.end())
			{
				cout << "The Three numbers are " << ipVect[i] << " " << ipVect[j] << " & " << sum+currSum;
				return true;
			}
			else
				hashSet.insert(ipVect[j]);

		}
	}	
	return false;	
}

int main()
{
	//vector<int> ipVect{12, 3, 4, 1, 6, 9};
	vector<int> ipVect{ 1, 2, 3, 4, 5 };
	FindTripletSum(ipVect,9);
	return false;
}