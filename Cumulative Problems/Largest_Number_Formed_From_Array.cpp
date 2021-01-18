/*Given a list of non negative integers, arrange them in such a manner that they form the largest number possible.
The result is going to be very large, hence return the result in the form of a string.*/

#include<iostream>
#include<vector>
#include<string>
#include<algorithm>
using namespace std;

int CompareStrings(string X, string Y)
{
	string XY = X.append(Y);
	string YX = Y.append(X);
	
	if (XY.compare(YX) > 0)
		return 1;
	else
		return 0;
}

void PrintLargest(vector<string>& arr)
{
	sort(arr.begin(), arr.end(), CompareStrings);
	for (int i = 0; i < arr.size(); i++)
		cout << arr[i];
	cout << endl;
}


int main()
{
	vector<string> ipVect{"54","546","548","60"};
	PrintLargest(ipVect);
	return 0;
}