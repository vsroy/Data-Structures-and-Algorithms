/*Suppose there is a circle. There are N petrol pumps on that circle. You will be given two sets of data.
1. The amount of petrol that every petrol pump has.
2. Distance from that petrol pump to the next petrol pump.
Find a starting point where the truck can start to get through the complete circle without exhausting its petrol in between.
Note :  Assume for 1 litre petrol, the truck can go 1 unit of distance.*/

#include<iostream>
using namespace std;
#include<vector>

class PetrolPump
{
public:
	int petrol;
	int distance;
};

int CircularTour(vector<PetrolPump> ipVect)
{
	//Start from the first element
	int start = 0, end = 1;

	//Calculate if truck will be able to travel from the start element
	int curr_petrol = ipVect[start].petrol - ipVect[start].distance;
	
	/* Run a loop while all petrol pumps are not visited.
	And we have reached first petrol pump again with 0 or more petrol */
	while (end != start || curr_petrol < 0)
	{
		// If curremt amount of petrol in truck becomes less than 0, then  
		// remove the starting petrol pump from tour
		while (curr_petrol < 0 && start != end)
		{
			//Remove starting petrol pump. Change start
			curr_petrol -= ipVect[start].petrol - ipVect[start].distance;
			start = (start + 1) % ipVect.size();

			// If 0 is being considered as start again, then there is no  
			// possible solution 
			if (start == 0)
				return -1;
		}
		//Add a new petrol pump
		curr_petrol += ipVect[end].petrol - ipVect[end].distance;
		end = (end + 1) % ipVect.size();
	}
	//Return starting point
	return start;
}

int main()
{
	vector<PetrolPump> ipVect = { { 6, 4 }, { 3, 6 }, { 7, 3 } };
	return 0;
}