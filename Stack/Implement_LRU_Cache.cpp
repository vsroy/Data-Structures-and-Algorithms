#include<iostream>
#include<list>
#include<unordered_map>
using namespace std;

class LRUCache
{
	list<int> lruList;
	unordered_map<int, list<int>::iterator> lruMap;

	//Max capacity of cache
	int cSize;

public:
	LRUCache(int x)
	{
		this->cSize = x;
	}

	//Function to refer element x of the cache
	void refer(int x)
	{
		//if item is not present in the array
		if (lruMap.find(x) == lruMap.end())
		{
			//If cache is full
			if (lruList.size() == cSize)
			{
				int back = lruList.back();
				lruList.pop_back();
				lruMap.erase(back);
				lruList.push_front(x);
				lruMap[x] = lruList.begin();
			}
			else
			{
				lruList.push_front(x);
				lruMap[x] = lruList.begin();
			}
		}
		//If item is present in the array
		else
		{
			lruList.erase(lruMap[x]);
			lruList.push_front(x);
			lruMap[x] = lruList.begin();
		}
	}

	//Function to display the contents of the cache
	void display()
	{
		list<int>::iterator it;
		for (it = lruList.begin(); it != lruList.end(); it++)
			cout << *it << " ";
	}
};

int main()
{
	LRUCache ca(4);

	ca.refer(1);
	ca.refer(2);
	ca.refer(3);
	ca.refer(1);
	ca.refer(4);
	ca.refer(5);
	ca.display();

	return 0;
}