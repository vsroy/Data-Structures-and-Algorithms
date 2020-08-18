/*Given an array of integers. Find the minimum number of swaps required to sort the array in non-decreasing order.*/
/*Solution fo this - https://www.geeksforgeeks.org/minimum-number-swaps-required-sort-array/*/
#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;

// Function returns the minimum number of swaps 
// required to sort the array 
int MinSwaps(vector<int>& ipVect)
{
	//Create an array of pairs where first elment is the array item and second element is the position of the item
	vector<pair<int, int>> position;
	
	for (int i = 0; i < ipVect.size(); i++)
		position.push_back(make_pair(ipVect[i], i));

	//Sort the position vector to get the correct position of the vector in the sorted array
	sort(ipVect.begin(), ipVect.end());

	//To keep track of all visited elements, initalize all elements as not visited/false
	vector<int> visited(ipVect.size(),0);

	//Initialize the result;
	int ans = 0;

	//Traverse the array elements
	for (int i = 0; i < ipVect.size(); i++)
	{
		//If already visited/at correct place, continue
		if (visited[i] || position[i].second == i)
			continue;
		
		//Find out the number of nodes in this cycle and add in ans
		int cycle_size = 0;
		int j = i;
		while (!visited[j])
		{
			visited[j] = 1;

			//Move to the next node
			j = position[j].second;
			cycle_size++;
		}

		//Update the answer by adding to the current cycle
		if (cycle_size > 0)
			ans += cycle_size - 1;
	}
	return ans;
}

int main()
{
	vector<int> ipVect{1,5,4,3,2};
	cout << MinSwaps(ipVect);
	return 0;
}