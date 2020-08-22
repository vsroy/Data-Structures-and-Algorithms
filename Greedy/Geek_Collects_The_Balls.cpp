/*There are two parallel roads, each containing N and M buckets, respectively. Each bucket may contain some balls. 
The buckets on both roads are kept in such a way that they are sorted according 
to the number of balls in them. Geek starts from the end of the road which has the bucket with a lower number of balls
(i.e. if buckets are sorted in increasing order, then geek will start from the left side of the road).
The geek can change the road only at the point of intersection(which means, buckets with the same number of balls on two roads). 
Now you need to help Geek to collect the maximum number of balls.*/
#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int MaxBallsCollected(vector<int> vect1, vector<int> vect2)
{
	int n = vect1.size();
	int m = vect2.size();
	int first = 0, second = 0, res = 0;

	int i = 0, j = 0;
	while (i < n && j < m)
	{
		if (vect1[i] < vect2[j])
		{
			first += vect1[i];
			i++;
		}
		else if (vect1[i] > vect2[j])
		{
			second += vect2[i]; j++;
		}
		else
		{
			res += max(first, second) + vect1[i];
			first = 0, second = 0;
			int temp = vect1[i];
			++i;
			temp = vect2[j];
			++j;
			while (i < n && vect1[i] == temp)
				res += vect1[i++];
			while (j < m && vect2[j] == temp)
				res += vect2[j++];
		}
	}
	
	while (i < n)
		first += vect1[i++];
	while (j < m)
		second += vect2[j++];

	res += max(first, second);
	return res;
}

int main()
{
	vector<int> vect1{1,4,5,6,8};
	vector<int> vect2{2,3,4,6,9};
	cout << MaxBallsCollected(vect1, vect2);
	return 0;
}