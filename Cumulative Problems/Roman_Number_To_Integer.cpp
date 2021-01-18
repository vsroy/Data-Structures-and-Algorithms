/*Given an string in roman no format (s)  your task is to convert it to integer .*/
#include<iostream>
using namespace std;

int value(char r)
{
	if (r == 'I')
		return 1;
	if (r == 'V')
		return 5;
	if (r == 'X')
		return 10;
	if (r == 'L')
		return 50;
	if (r == 'C')
		return 100;
	if (r == 'D')
		return 500;
	if (r == 'M')
		return 1000;

	return -1;
}

int romanToDecimal(string& str)
{
	//Initialize result
	int res = 0;

	//Traverse Input
	for (int i = 0; i < str.length(); i++)
	{
		//Getting the value of the current character
		int s1 = value(str[i]);

		//Getting the value of str[i+1]
		if (i + 1 < str.length())
		{
			int s2 = value(str[i + 1]);

			//Comparing both values
			if (s1 >= s2)
			{
				//If value of the current symbol is greater than or equal to the next symbol
				res = res + s1;
			}
			else
			{
				//If value of the current symbol is less than the next symbol
				res = res + s2 - s1;
				i++;
			}
		}
		else
		{
			//If current element is the last element
			res = res + s1;
		}
	}
	return res;
}

int main()
{
	string str = "MCMIV";
	cout << "Integer form of Roman Numeral is "
		<< romanToDecimal(str) << endl;

	return 0;
}