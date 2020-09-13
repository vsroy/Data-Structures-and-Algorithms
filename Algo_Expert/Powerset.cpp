/*Power Set Power set P(S) of a set S is the set of all subsets of S. 
For example S = {a, b, c} then P(s) = {{}, {a}, {b}, {c}, {a,b}, {a, c}, {b, c}, {a, b, c}}.
If S has n elements in it then P(s) will have 2^n elements*/
#include<iostream>
#include<vector>
using namespace std;

void PrintPowerSet(vector<int> arr)
{
	int set_size = arr.size();
	
	//Get the size of the powerset
	int pow_set_size = pow(2,set_size);

	/*Loop for every combination. Run from counter 000..0 to 111..1*/
	for (int counter = 0; counter < pow_set_size; counter++)
	{
		for (int j = 0; j < set_size; j++)
		{
			if (counter & (1 << j))
				cout << arr[j] << "";
		}
		//One combinations printed
		cout << endl;
	}
}

int main()
{
	vector<int> arr{1,2,3};
	PrintPowerSet(arr);
	return 0;
}