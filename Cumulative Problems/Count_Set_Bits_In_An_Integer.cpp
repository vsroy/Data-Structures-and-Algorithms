/*Given an integer, write a function to compute the number of ones in the binary representation of the number.*/
#include<iostream>
using namespace std;

int count_set_bits(unsigned int n)
{
	int count = 0;

	while (n)
	{
		//Increment count by '&'ing with current bit
		count = count + (n & 1);

		//Right shift the value of n to set the next bit
		n = n >> 1;
	}
	return count;
}

int main()
{
	unsigned int n = 13;
	cout << count_set_bits(n);
	return 0;
}