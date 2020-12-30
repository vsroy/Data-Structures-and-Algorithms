/*You are given a number N. You have to find the number of operations required to reach N from 0. You have 2 operations available:
Double the number
Add one to the number*/
//Solution
/*Instead of going from beginning to destination we can start moving from the destination to initial position and keep track of the cost of jumps.
If N is odd then the only valid move that could lead us here is N-1 to N with a cost of P.
If N is even then we calculate cost of going from N to N/2 position with both the moves and take the minimum of them.
When N equals 0, we return our total calculated cost.*/
#include<iostream>
using namespace  std;

//Function to return min cost to reach destination
int MinCost(int N, int add, int multiply)
{
	//Initialize cost
	int cost = 0;

	//We go backwards till we reach initial position
	while (N > 0)
	{
		//If number is odd
		if (N % 2 == 1)
		{
			cost += add;
			N--;
		}
		else
		{	//If number is even
			int temp = N / 2;

			//If cost of jumping by moving 1 step at a time(N/2 times) is less than one shot N/2 time jump  
			if (temp * add > multiply)
				cost += multiply;
			else
				cost += temp * add;
			N /= 2;
		}
	}
	return cost;
}

int main()
{
	cout << MinCost(9,5,1);
	return 0;
}