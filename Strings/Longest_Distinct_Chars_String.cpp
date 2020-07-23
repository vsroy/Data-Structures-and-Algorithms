/*Given a string S, find length of the longest substring with all distinct characters.  For example, 
for input "abca", the output is 3 as "abc" is the longest substring with all distinct characters.*/

#include<iostream>
#include<string>
#include<vector>
using namespace std;

int LongestDistinctCharacters(string str)
{
	
	vector<int> hashVect(256, 0);
	int index = 0;
	
	int maxSoFar = 0;
	int currentCount = 0;
	
	while (index < str.length())
	{
		if (hashVect[str[index]] == 0)
		{
			hashVect[str[index]] = 1;
			currentCount++;
		}
		else
		{
			std::fill(hashVect.begin(), hashVect.end(),0);
			if (currentCount > maxSoFar)
				maxSoFar = currentCount;
			hashVect[str[index]] = 1;
			currentCount = 0; 
			currentCount++;
		}
		index++;
	}
	if (currentCount > maxSoFar)
		maxSoFar = currentCount;
	return maxSoFar;
}

int main()
{
	string str = "abababcdefababcdab";
	cout << LongestDistinctCharacters(str);
	return 0;
}