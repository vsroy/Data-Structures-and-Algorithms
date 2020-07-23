/*Given a string, find the minimum number of characters to be inserted to convert it to palindrome.*/

#include<iostream>
#include<string>
#include<algorithm>
using namespace std;

// Recursive function to find   
// minimum number of insertions 
int FindMinInsertions(string& str, int left, int right)
{
	//Base Cases
	if (left > right) return INT_MAX;
	if (left == right) return 0;
	if (left == right - 1) return str[left] == str[right] ? 0 : 1;

	// Check if the first and last characters are 
	// same. On the basis of the comparison result,  
	// decide which subrpoblem(s) to call 

	if (str[left] == str[right])
		return FindMinInsertions(str, left + 1, right - 1);
	else
		return min(FindMinInsertions(str, left, right - 1), FindMinInsertions(str, left + 1, right)) + 1;
}

int main()
{
	string str = "geeks";
	cout << FindMinInsertions(str,0,str.length()-1);
	return 0;
}