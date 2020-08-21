/*You are given two arrays, A and B, of equal size N. The task is to find the minimum value of A[0] * B[0] + A[1] * B[1] +…+ A[N-1] * B[N-1], 
where shuffling of elements of arrays A and B is allowed.*/
#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int MinSumOfProduuct(vector<int> vect1, vector<int> vect2)
{
	if (vect1.size() != vect2.size())
		return -1;

	int n = vect1.size();

	sort(vect1.begin(), vect1.end());
	sort(vect2.begin(), vect2.end());

	int result = 0;

	for (int i = 0; i < n; i++)
	{
		int product = vect1[i] * vect2[n - 1 - i];
		result += product;
	}
	return result;
}

int main()
{
	vector<int> vect1{6,1,9,5,4};
	vector<int> vect2{3,4,8,2,4 };
	cout << MinSumOfProduuct(vect1,vect2);
	return 0;
}