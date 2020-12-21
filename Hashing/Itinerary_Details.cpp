/*
Given a list of tickets, find itinerary in order using the given list.

Example:

Input:
"Chennai" -> "Banglore"
"Bombay" -> "Delhi"
"Goa"    -> "Chennai"
"Delhi"  -> "Goa"

Output:
Bombay->Delhi, Delhi->Goa, Goa->Chennai, Chennai->Banglore,
*/

#include<iostream>
#include<map>
#include<string>
using namespace std;

void printItinerary(map<string,string>& dataSet)
{
	map<string, string> reverseDataSet;

	map<string, string>::iterator it;

	//Create a reverse map
	for (it = dataSet.begin(); it != dataSet.end(); it++)
		reverseDataSet[it->second] = it->first;

	//Check the key from fisrt array and search it in reverse array. The element that is not present in the reverse array is the starting element
	string start = "";
	for (it = dataSet.begin(); it != dataSet.end(); it++)
	{
		if (reverseDataSet.find(it->first) == reverseDataSet.end())
		{
			start = it->first;
			break;
		}
	}
	if (start == "")
		return;

	//Get the location of the first element in the dataset
	it = dataSet.find(start);

	//Once we have the start location, we can find the links one by one
	while (it != dataSet.end())
	{
		cout << it->first << " " << it->second << endl;
		it = dataSet.find(it->second);
	}
}

int main()
{
	map<string, string> dataSet;
	dataSet["Chennai"] = "Banglore";
	dataSet["Bombay"] = "Delhi";
	dataSet["Goa"] = "Chennai";
	dataSet["Delhi"] = "Goa";

	printItinerary(dataSet);
	return 0;
}