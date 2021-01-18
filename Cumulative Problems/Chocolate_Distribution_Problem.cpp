/*Given an array A of positive integers of size N, where each value represents number of chocolates in a packet. 
Each packet can have variable number of chocolates. 
There are M students, the task is to distribute chocolate packets such that :
1. Each student gets one packet.
2. The difference between the number of chocolates given to the students having packet 
with maximum chocolates and student having packet with minimum chocolates is minimum.*/

#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int findMinDiff(vector<int> ipVect, int students)
{
	int packets = ipVect.size();

	/*If there are no packets or of there are no students*/
	if (packets == 0 || students == 0)
		return 0;

	/*If number of students are more than no of packets, then there is no solution*/
	if (students > packets)
		return -1;

	//Sort the packets by the number of chocolates they contain
	sort(ipVect.begin(), ipVect.end());

	int min_diff = INT_MAX;

	/*We difference of min and max values of current sliding window and check if it is smaller than min val so far*/
	for (int i = 0; (i + students - 1) < packets; i++)
	{
		int curMin = ipVect[i + students - 1] - ipVect[i];
		if (curMin < min_diff)
			min_diff = curMin;
	}
	return min_diff;
}

int main()
{
	vector<int> ipVect{ 12, 4, 7, 9, 2, 23, 25, 41,
		30, 40, 28, 42, 30, 44, 48,
		43, 50 };
	cout << findMinDiff(ipVect,7);
	return 0;
}