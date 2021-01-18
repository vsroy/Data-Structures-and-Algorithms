/*Given an array A of size N containing 0s, 1s, and 2s; you need to sort the array in ascending order.*/
#include<iostream>
#include<vector>
using namespace std;

void swap(int& a, int& b)
{
	int temp = a;
	a = b;
	b = temp;
}

void Sort012(vector<int>& ipVect)
{
	int low = 0;
	int mid = 0;
	int high = ipVect.size() - 1;
	
	while (mid <= high)
	{
	        if(ipVect[mid] == 0)
			{
				swap(ipVect[low], ipVect[mid]);
				low++; mid++;
			
			}

			else if(ipVect[mid] == 1)
			{
				mid++;
			}

			else
			{
				swap(ipVect[high], ipVect[mid]);
				high--;
            }
	}
}

int main()
{
	vector<int> ipVect{ 0, 1, 1, 0, 1, 2, 1, 2, 0, 0, 0, 1 };
	Sort012(ipVect);
	
	for (auto i : ipVect)
		cout << i << " ";
	return 0;
}