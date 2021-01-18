/*Given two integers, write a function to sum the numbers without using any arithmetic operators.*/
#include<iostream>
using namespace std;

int Add(int x, int y)
{
	//While there is no carry
	while (y != 0)
	{
		//Carry now contains common set bits of x and y
		int carry = x & y;

		//Sum of the bits of x and y where at least one of the bits is not set
		x = x ^ y;

		//Carry is shifted by 1 so that adding it to x gives us the required sum
		y = carry << 1;
	}
	return x;
}

int main()
{
	cout << Add(15, 5);
	return 0;
}