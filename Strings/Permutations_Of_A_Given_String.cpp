#include<iostream>
#include<string>
using namespace std;

void Swap(int&a, int& b)
{
	int temp = a;
	a = b;
	b = temp;
}


void Permute(string& a, int l, int r)
{
	//Base case. We have reached the end. No need to permute
	if (l == r)
		cout << a << endl;
	else
	{
		for (int i = l; i <= r; i++)
		{
			//Swapping done
			swap(a[l], a[i]);

			//Permute further
			Permute(a, l + 1, r);

			//Backtrack
			swap(a[l], a[i]);
		}
	}
}

int main()
{
	string a = "ABC";
	Permute(a,0,a.length()-1);
	return 0;
}