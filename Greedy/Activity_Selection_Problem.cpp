/*Given N activities with their start and finish times. Select the maximum number of 
activities that can be performed by a single person, assuming that a person can only work on a single activity at a time.*/
#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

bool SortVector(pair<int, int> pair1, pair<int, int> pair2)
{
	return (pair1.second < pair2.second);
}

void PrintActivities(vector<pair<int,int>> ipVect)
{
	sort(ipVect.begin(), ipVect.end(), SortVector);

	//First activity is always printed
	cout << ipVect[0].first << " " << ipVect[0].second << endl;

	int i = 0;
	//Consider the rest of the activities
	for (int j = 1; j < ipVect.size(); j++)
	{
		if (ipVect[j].first >= ipVect[i].second)
		{
			cout << ipVect[j].first << " " << ipVect[j].second << endl;
			i = j;
		}
	}
}

int main()
{
	vector<pair<int, int>> ipvect{ { 5, 9 }, { 1, 2 }, { 3, 4 }, { 0, 6 },
	{ 5, 7 }, { 8, 9 } };
	PrintActivities(ipvect);
	return 0;
}