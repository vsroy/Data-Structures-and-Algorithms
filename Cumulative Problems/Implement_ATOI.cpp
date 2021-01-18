/*Your task  is to implement the function atoi. The function takes a string(str) as argument and converts it to an integer and returns it.*/

#include<iostream>
#include<string>
using namespace std;

int ATOI(string str)
{
	int n = str.length();
	int lengthIndex = n-1;
	int stringIndex = 0;
	
	if (str[0] == '-')
	{
		stringIndex++;
		lengthIndex--;
	}
	
	int totalResult = 0;

	for (int i = lengthIndex; i >= 0; i--)
	{
		int multiplier = pow(10, i);
		int currentResult = str[stringIndex] - '0';
		if (currentResult < 0 || currentResult > 9)
			return -1;
		currentResult = currentResult * multiplier;
		totalResult += currentResult;
		stringIndex++;
	}

	if (str[0] == '-')
		totalResult = 0 - totalResult;
	return totalResult;
}

int main()
{
	string ipString = "-123";
	cout << ATOI(ipString);
	return 0;
}