/*Given a set of N nuts of different sizes and N bolts of different sizes. 
There is a one-one mapping between nuts and bolts. Match nuts and bolts efficiently.
Comparison of a nut to another nut or a bolt to another bolt is not allowed. 
It means nut can only be compared with bolt and bolt can only be compared with nut to see which one is bigger/smaller.*/
#include<iostream>
#include<vector>
#include<unordered_map>
using namespace std;

void NutBoltMatch(vector<char>& nuts, vector<char>& bolts)
{
	unordered_map<char, int> hashMap;

	//First hash the nuts and indices of the nuts
	for (int i = 0; i < nuts.size(); i++)
		hashMap[nuts[i]] = i;

	//Then loop through the bolts, if we find a nut in the array, change the nut as per in the bolt in the bolt index
	for (int i = 0; i < bolts.size(); i++)
		if (hashMap.find(bolts[i]) != hashMap.end())
			nuts[i] = bolts[i];

	//Print the result
	for (int i = 0; i < nuts.size(); i++)
		cout << nuts[i] << " ";
	cout << endl;
	for (int i = 0; i < nuts.size(); i++)
		cout << bolts[i] << " ";
}

int main()
{
	vector<char> nuts{ '@', '#', '$', '%', '^', '&' };
	vector<char> bolts{ '$', '%', '&', '^', '@', '#' };

	NutBoltMatch(nuts, bolts);
	return 0;
}