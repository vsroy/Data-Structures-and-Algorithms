#include<iostream>
#include<vector>
using namespace std;

/*This program will solve sub array with current sum for positive numbers*/
int subArraySum(vector<int> ipVect, int sum)
{
	int curSum = ipVect[0], start = 0;

	/*variable start will hold elements from the start index and i of the last index of the subset*/
	for (int i = 1; i <= ipVect.size(); i++)
	{
		/*As long as the current sum exceeds the target sum, we remove elements from the start*/
		while (curSum > sum && start < i - 1)
		{
			curSum = curSum - ipVect[start];
			start++;
		}

		/*If we find the target sum, then all elements between start and i will fall under the subset*/
		if (curSum == sum)
		{
			cout << "Sum found between indexes " << start  << " and " << i - 1;
			return 1;
		}

		/*We add the elements to the current sum*/
		if (i < ipVect.size())
			curSum += ipVect[i];
	}
}

int main()
{
	vector<int> ipVect{ 15, 2, 4, 8, 9, 5, 10, 23 };
	subArraySum(ipVect, 23);
	return 0;
}