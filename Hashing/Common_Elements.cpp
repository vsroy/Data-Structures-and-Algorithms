/*Given three increasingly sorted arrays A, B, C of sizes N1, N2, and N3 respectively, you need to print all common elements in these arrays.*/
#include<iostream>
#include<vector>
using namespace std;

void PrintCommonElements(vector<int> vect1, vector<int> vect2, vector<int> vect3)
{
	int size1 = vect1.size(), size2 = vect2.size(), size3 = vect3.size();
	
	int i = 0, j = 0, k = 0;
	
	while (i < size1 && j < size2 && k < size3)
	{
		if (vect1[i] == vect2[j] && vect2[j] == vect3[k])
		{
			cout << vect1[i] << " ";
			i++; j++; k++;
		}
		else if (vect1[i] < vect2[j])
			i++;
		else if (vect2[j] < vect3[k])
			j++;
		else
			k++;
	}
}

int main()
{
	vector<int> vect1{ 1, 5, 10, 20, 40, 80 };
	vector<int> vect2{ 6, 7, 20, 80, 100 };
	vector<int> vect3{ 3, 4, 15, 20, 30, 70, 80, 120 };

	PrintCommonElements(vect1, vect2, vect3);

	return 0;
}