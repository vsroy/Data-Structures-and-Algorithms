/*The cost of a stock on each day is given in an array, find the max profit that you can make by buying and selling in those days. 
For example, if the given array is {100, 180, 260, 310, 40, 535, 695}, the maximum profit can earned by buying on day 0, selling on day 3. 
Again buy on day 4 and sell on day 6. If the given array of prices is sorted in decreasing order, then profit cannot be earned at all.*/
#include<iostream>
#include<vector>
using namespace std;

void StockBuySell(vector<int> arr)
{
	int start = 0, end = 0;
	int n = arr.size();

	if (arr.size() <= 0)
		return;

	int i = 0;
	while (i < n - 1)
	{
		// Find Local Minima 
		// Note that the limit is (n-2) as we are 
		// comparing present element to the next element 

		while ((i < n - 1) && arr[i + 1] <= arr[i])
			i++;

		// If we reached the end, break 
		// as no further solution possible 
		if (i == n - 1)
			break;
		
		// Store the index of minima 
		start = i++;

		// Find Local Maxima 
		// Note that the limit is (n-1) as we are 
		// comparing to previous element 
		while (i < n && arr[i] >= arr[i-1])
			i++;

		//Store the local maxima
		end = i - 1;

		cout << "Buy on day " << start << " and sell on day " << end << endl;
	}
}

int main()
{
	vector<int> arr{ 100, 180, 260, 310, 40, 535, 695 };
	StockBuySell(arr);
	return 0;
}