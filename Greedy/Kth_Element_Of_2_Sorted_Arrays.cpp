#include<iostream>
#include<vector>
using namespace std;

int Find(vector<int>& vect1, vector<int>& vect2, int req)
{
	int size1 = vect1.size(), size2 = vect2.size();
	int k = 0;
	int count1 = 0, count2 = 0;

	while (count1 < size1 && count2 < size2)
	{
		if (vect1[count1] < vect2[count2])
		{
			k++;
			if (k == req)
				return vect1[count1];
			count1++;
		}
		else
		{
			k++;
			if (k == req)
				return vect2[count2];
			count2++;
		}
	}

	while (count1 < size1)
	{
		k++;
		if (k == req)
			return vect1[count1];
		count1++;
	}

	while (count2 < size2)
	{
		k++;
		if (k == req)
			return vect2[count2];
		count2++;
	}
	return -1;
}

int main()
{
	vector<int> vect1{ 2, 3, 6, 7, 9 };
	vector<int> vect2{ 1, 4, 8, 10 };

	cout << Find(vect1,vect2,5);
	return 0;
}