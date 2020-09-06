/*Given a length n, count the number of strings of length n that can be made using ‘a’, ‘b’ and ‘c’ with at-most one ‘b’ and two ‘c’s allowed.*/
#include<iostream>
using namespace std;

// n is total number of characters. 
// bCount and cCount are counts of 'b' 
// and 'c' respectively. 
int countStr(int n, int bCount, int cCount)
{
	//Base cases
	if (bCount < 0 || cCount < 0)
		return 0; //Invalid case

	if (n == 0)	//No more characters left, we return the pattern
		return 1;

	if (bCount == 0 && cCount == 0)
		return 1;	//Only aaa can be formed

	// Three cases, we choose, a or b or c 
	// In all three cases n decreases by 1. 
	int res = countStr(n - 1, bCount, cCount);	//a is included
	res += countStr(n - 1, bCount - 1, cCount);	//b is included
	res += countStr(n - 1, bCount, cCount - 1);	//c is included
	return res;
}


int main()
{
	int n = 3;//Total number of characters
	cout << countStr(n, 1, 2);
	return 0;
}