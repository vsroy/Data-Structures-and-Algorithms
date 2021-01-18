/*Given a 2D array, print it in spiral form.*/
#include<iostream>
#include<vector>
using namespace std;

void PrintSpiralForm(vector<vector<int>> a)
{
	int m = a.size();
	int n = a[0].size();

	int i=0, k=0, l =0;
	/*
	k = starting row index
	m = ending row index
	l = starting column index
	n = ending column index	
	i = iterator
	*/
	
	//Print the first row from the remaining rows
	while (k < m && l < n) {
		/* Print the first row from
		the remaining rows */
		for (i = l; i < n; ++i) {
			cout << a[k][i] << " ";
		}
		k++;

		/* Print the last column
		from the remaining columns */
		for (i = k; i < m; ++i) {
			cout << a[i][n - 1] << " ";
		}
		n--;

		/* Print the last row from
		the remaining rows */
		if (k < m) {
			for (i = n - 1; i >= l; --i) {
				cout << a[m - 1][i] << " ";
			}
			m--;
		}

		/* Print the first column from
		the remaining columns */
		if (l < n) {
			for (i = m - 1; i >= k; --i) {
				cout << a[i][l] << " ";
			}
			l++;
		}
	}
}

int main()
{
	vector<vector<int>> arr { { 1, 2, 3, 4, 5, 6 }, 
                    { 7, 8, 9, 10, 11, 12 }, 
                    { 13, 14, 15, 16, 17, 18 } }; 

	PrintSpiralForm(arr);
	return 0;
}