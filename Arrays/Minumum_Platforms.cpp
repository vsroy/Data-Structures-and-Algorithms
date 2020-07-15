/*Given arrival and departure times of all trains that reach a railway station. Your task is to find the minimum number 
of platforms required for the railway station so that no train waits.*/

#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int findPlatform(vector<int> arrival, vector<int> departures)
{
	/*First sort elements according to arrival or departures*/
	sort(arrival.begin(), arrival.end());
	sort(departures.begin(), departures.end());

	int max_plat_so_far = 1;

	int i = 1, j = 0;
	int totalPlatforms = 1;
	while (i < arrival.size() && j < departures.size())
	{
		if (arrival[i] <= departures[j])
		{
			totalPlatforms++;
			i++;
		}
		else
		{
			totalPlatforms--;
			j++;
		}
		if (totalPlatforms > max_plat_so_far)
			max_plat_so_far = totalPlatforms;
	}
	return max_plat_so_far;
}

int main()
{
	vector<int> arrivalVect{ 900, 940, 950, 1100, 1500, 1800 };
	vector<int> departureVect{ 910, 1200, 1120, 1130, 1900, 2000 };

	cout << findPlatform(arrivalVect, departureVect);
	return 0;
}