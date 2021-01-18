/*Given two numbers 'N' and 'S' , find the largest number that can be formed with 'N' digits and whose sum of digits should be equals to 'S'.*/
#include<iostream>
#include<vector>
using namespace std;

void FindLargestNumber(int digits, int sum)
{
	vector<int> resultVect;

	if (sum <= 0 && digits == 1)
	{
		cout << "Not possible";
		return;
	}

	if (sum > 9 * digits)
	{
		cout << "Not possible";
		return;
	}

	for (int i = 0; i < digits; i++)
	{
		if (sum >= 9)
		{
			resultVect.push_back(9);
			sum = sum - 9;
		}
		else
		{
			resultVect.push_back(sum);
			sum = 0;
		}
	}

	cout << "Largest Number is ";
	for (int i = 0; i < resultVect.size(); i++)
		cout << resultVect[i];
	
}

int main()
{
	FindLargestNumber(3,20);
	return 0;
}