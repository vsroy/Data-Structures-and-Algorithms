﻿/*Given the total number of persons n and a number k which indicates that k-1 persons
are skipped and kth person is killed in circle in a fixed direction.​
The task is to choose the safe place in the circle so that when you perform these operations 
starting from 1st place in the circle, you are the last one remaining and survive.*/
#include<iostream>
using namespace std;
int Josephus(int n, int k)
{
	if (n == 1)
		return 1;
	else
		/* The position returned by josephus(n - 1, k)
		is adjusted because the recursive call
		josephus(n - 1, k) considers the
		original position k % n + 1 as position 1 */
		return (Josephus(n - 1, k) + k - 1) % n + 1;
}

int main()
{
	int n = 14;
	int k = 2;
	cout << "The chosen place is " << Josephus(n, k);
	return 0;
}