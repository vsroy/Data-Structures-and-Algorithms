/*Given a string S. The task is to find the first repeated character in it. We need to find the character that occurs 
more than once and whose index of second occurrence is smallest. S contains only lowercase letters.*/
#include<iostream>
#include<unordered_set>
#include<string>
using namespace std;

void FirstRepeatedCharacter(string ipString)
{
	unordered_set<char> hashSet;
	
	for (int i = 0; i < ipString.length(); i++)
	{
		if (hashSet.find(ipString[i]) != hashSet.end())
		{
			cout << ipString[i];
			return;
		}
		hashSet.insert(ipString[i]);
	}
	cout << "All distinct characters in the array";
}

int main()
{
	string str = "hellogeeks";
	FirstRepeatedCharacter(str);
	return 0;
}