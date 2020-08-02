/*Given an input stream of N characters consisting only of lower case alphabets. The task is to find the first non repeating character, 
each time a character is inserted to the stream. If no non repeating element is found print -1.*/
#include<iostream>
#include<queue>
#include<vector>
#include<string>
using namespace std;

void FirstNonRepeatingCharacterInStream(string& str)
{
	//Store a hash table of frequency count of elements
	vector<int> countVect(26);

	//We will use this queue to store elements one by one
	queue<char> charQueue;

	//Traverse for every element in the input stream
	for (int i = 0; i < str.length(); i++)
	{
		//Push the element into the queue
		charQueue.push(str[i]);

		//Increase the count in the hash table by one
		countVect[str[i] - 'a']++;
		
		//For current element we have to check the front of the queue and remove all elements from the front whose frequency is > 1
		while (!charQueue.empty() && countVect[charQueue.front() -'a']  > 1)
			charQueue.pop();
		
		//If all elements so far have been repeated, print -1
		if (charQueue.empty())
		{
			cout << "-1";
			continue;
		}

		//We print that element whose frequency is greater than 1
		if (countVect[charQueue.front() - 'a'] == 1)
			cout << charQueue.front() << " ";
	}
}

int main()
{
	string str = "aqizqazpn";
	FirstNonRepeatingCharacterInStream(str);
	return 0;
}