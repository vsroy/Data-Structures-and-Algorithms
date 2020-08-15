/*Given a string S and text T. Output the smallest window in the string S having all characters of the text T. 
Both the string S and text T contains lowercase english alphabets.*/

#include<iostream>
#include<map>
#include<string>
using namespace std;

int SmallestWindow(string str, string pat)
{
	int strLength = str.length();
	int patLength = pat.length();


	if (strLength < patLength)
		return -1;

	map<char, int> hashStr;
	map<char, int> hashPat;

	// store occurrence ofs characters of pattern 
	for (int i = 0; i < patLength; i++)
		hashPat[pat[i]]++;

	int start = 0, start_index = -1, min_len = INT_MAX;
	//Count the number of characters
	int count = 0;

	for (int i = 0; i < strLength; i++)
	{
		// count occurrence of characters of string 
		hashStr[str[i]]++;

		// If string's char matches with pattern's char 
		// then increment count 
		if (hashPat[str[i]] != 0 && (hashStr[str[i]] <= hashPat[str[i]]))
			count++;

		//If all characters are matched, 
		if (count == patLength)
		{
			// Try to minimize the window i.e., check if 
			// any character is occurring more no. of times 
			// than its occurrence in pattern, if yes 
			// then remove it from starting and also remove 
			// the useless characters. 
			while (hashStr[str[start]] > hashPat[str[start]] || hashPat[str[start]] == 0)
			{
				if (hashStr[str[start]] > hashPat[str[start]])
					hashStr[str[start]]--;
				start++;
			}

			//Update window size
			int len_window = i - start + 1;
			if (len_window < min_len)
			{
				min_len = len_window;
				start_index = start;
			}
		}
	}
	if (start_index == -1)
		return -1;
	else
		return min_len;
}

int main()
{
	return 0;
}