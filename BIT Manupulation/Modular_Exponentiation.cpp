/*Given three numbers x, y and p, compute (xy) % p.*/
#include<iostream>
using namespace std;

/* Iterative Function to calculate (x^y)%p in O(log y) */
int power(int x, unsigned int y, int p)
{
	int res = 1;	//Initialize result

	x = x % p;	// Update x if it is more than or  
                // equal to p 

	if (x == 0)	// In case x is divisible by p; 
		return 0;

	while (y > 0)
	{
		//If y is odd, multiply x with result
		if (y & 1)
			res = (res*x) % p;

		//y must be even now
		y = y >> 1;	//y = y/2
		x = (x*x) % p;
	}
	return res;
}

int main()
{
	int x = 2;
	int y = 5;
	int p = 13;
	cout << power(x, y, p);
	return 0;
}