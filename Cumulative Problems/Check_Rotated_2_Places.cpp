/*Given two strings a and b. The task is to find if a string 'a' can be obtained by rotating another string 'b' by 2 places.*/

#include<iostream>
#include<string>
using namespace std;

bool isRotated(string str1, string str2)
{
	string anticlock = "";
	string clock = "";

	string anticlock1 = str1.substr(2,str1.length()-2);
	string anticlock2 = str1.substr(0,2);

	anticlock = anticlock1 + anticlock2;
	if (anticlock.compare(str2) == 0)
	{
		cout << "Anticlockwise";
		return true;
	}

	string clock1 = str1.substr(0, str1.length() - 2);
	string clock2 = str1.substr(str1.length() - 2, 2);

	clock = clock2 + clock1;
	if (clock.compare(str2) == 0)
	{
		cout << "Clockwise";
		return true;
	}

	return false;
}

int main()
{
	cout << endl << isRotated("geeks","eksge");
	return 0;
}