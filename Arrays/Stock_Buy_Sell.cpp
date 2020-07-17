/*The cost of stock on each day is given in an array A[] of size N. Find all the days on which you buy and 
sell the stock so that in between those days your profit is maximum.*/

#include<iostream>
#include<vector>
using namespace std;

void StockBuySell(vector<int> ipVect)
{
	int n = ipVect.size();

	if (n == 1)
		return;

	int i = 0;
	
	//Loop till the second last element of the array
	while (i < n - 1)
	{

		//Find local minima
		while ((i < n - 1) && (ipVect[i + 1] <= ipVect[i]))
			i++;

		//If we reached the end, there is no solution possible
		if (i == n - 1)
			break;

		int buy = i++;
		
		//Find local maximum
		while ((i < n) && (ipVect[i]) >= ipVect[i - 1])
			i++;

		int sell = i - 1;

		cout << "Buy on day " << buy << " and sell on day " << sell << endl;
	}
}

int main()
{
	vector<int> ipVect{ 100, 180, 260, 310, 40, 535, 695 };
	StockBuySell(ipVect);
	return 0;
}