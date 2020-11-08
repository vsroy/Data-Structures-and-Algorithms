#include<iostream>
#include<string>
#include<vector>
using namespace std;

bool IsValid(string ip)
{
	//Splitting by '.'

	vector<string> ips;

	string ex = "";

	for (int i = 0; i < ip.size(); i++)
	{
		if (ip[i] == '.')
		{
			ips.push_back(ex);
			ex = "";
		}
		else
			ex = ex + ip[i];
	}
	ips.push_back(ex);

	// Checking for the corner cases
	// cout << ip << endl; 

	for (int i = 0; i < ips.size(); i++)
	{
		if (ips[i].length() > 3 || stoi(ips[i]) < 0 || stoi(ips[i]) > 255)
			return 0;

		if (ips[i].length() > 1 && stoi(ips[i]) == 0)
			return 0;

		if (ips[i].length() > 1 && stoi(ips[i]) != 0 && ips[i][0] == '0')
			return 0;
	}
	return -1;
}

void Convert(string str)
{
	int l = str.length();

	if (l > 12 || l < 4)
	{
		cout << "Not a valid IP address";
		return;
	}

	vector<string> result;
	string check = str;

	for (int i = 1; i < l - 2; i++)
	{
		for (int j = i + 1; j < l - 1; j++)
		{
			for (int k = j + 1; j < l; j++)
			{
				check = check.substr(0, k) + '.' +check.substr(k, l - k + 2);

				check = check.substr(0, j) + '.' + check.substr(j, l - j + 3);

				check = check.substr(0, i) + '.' + check.substr(i, l - i + 4);

				if (IsValid(check))
				{
					cout << check;
					result.push_back(check);
				}
				check = str;
			}
		}
	}
}


int main()
{
	Convert("25525511135");
	return 0;
}