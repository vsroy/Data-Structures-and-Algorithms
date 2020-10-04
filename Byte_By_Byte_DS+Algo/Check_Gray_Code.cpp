/*Given two integers, write a function to determine whether or not their binary representations differ by a single bit.*/
#include<iostream>
using namespace std;

bool IsPowerOf2(unsigned int x)
{
	// First x in the below expression is 
	// for the case when x is 0 
	return x && (!(x & (x - 1)));
}

// function to check whether the two numbers 
// differ at one bit position only 
bool differAtOneBitPos(unsigned int a, unsigned int b)
{
	return IsPowerOf2(a ^ b);
}

int main()
{
	unsigned int a = 13, b = 9;
	cout << differAtOneBitPos(a, b);
	return 0;
}