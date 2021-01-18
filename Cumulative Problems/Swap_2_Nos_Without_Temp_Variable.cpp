/*Given two integers, write a function that swaps them without using any temporary variables.*/
#include<iostream>
using namespace std;

void Add2Nos(int a, int b)
{
	a = a + b;
	b = a - b;
	a = a - b;

	cout << "a = " << a << " and b = " << b;
}

int main()
{
	Add2Nos(10, 5);
	return 0;
}