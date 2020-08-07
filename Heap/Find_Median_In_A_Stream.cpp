/*Given an input stream of N integers. The task is to insert these numbers into a new stream and find the median of 
the stream formed by each insertion of X to the new stream.*/

#include<iostream>
#include<queue>
#include<vector>
#include<functional>
#include<algorithm>
using namespace std;

class FindMedian
{
	vector<int> medianVect;

public:

	void InsertElements(int x)
	{
		medianVect.push_back(x);
		sort(medianVect.begin(), medianVect.end());
		PrintMedian();
	}

	float getMedian()
	{
		//Even elements
		if (medianVect.size() % 2 == 0)
		{
			int x = medianVect.size() / 2 - 1;
			int y = medianVect.size() / 2;
			return (medianVect[x] + medianVect[y]) / 2;
		}
		else
			return medianVect[medianVect.size() / 2];
	}

	void PrintMedian()
	{
		//Even elements
		if (medianVect.size() % 2 == 0)
		{
			int x = medianVect.size() / 2 - 1;
			int y = medianVect.size() / 2;
			cout << "\n" << "Median is " << (medianVect[x] + medianVect[y]) / 2;
		}
		else
			cout << "\n" << "Median is " << medianVect[medianVect.size() / 2];
	}
};

int main()
{
	FindMedian fObj;
	fObj.InsertElements(5);
	fObj.InsertElements(15); 
	fObj.InsertElements(1);
	fObj.InsertElements(3);

	return 0;
}