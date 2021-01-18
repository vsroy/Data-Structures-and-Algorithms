/*Given K sorted linked lists of different sizes. The task is to merge them in such a way 
that after merging they will be a single sorted linked list.*/

#include<iostream>
#include<vector>
using namespace std;

// A Linked List node 
struct Node {
	int data;
	Node* next;
};

Node* SortedMerge(Node* a, Node* b)
{
	Node* resultHead = NULL;

	//Base Cases
	if(a == NULL)
		return b;
	if (b == NULL)
		return a;

	if (a->data <= b->data)
	{
		resultHead = a;
		resultHead->next = SortedMerge(a->next, b);
	}
	else
	{
		resultHead = b;
		resultHead->next = SortedMerge(a, b->next);
	}
	return resultHead;
}

Node* MergeKLists(vector<Node*> ipVect)
{
	int last = ipVect.size() - 1;

	//Until wo do not get a single list
	while (last != 0)
	{
		int i = 0;
		int j = last;
		while (i < j)
		{
			//Merge the 2 lists and store it in a single list
			ipVect[i] = SortedMerge(ipVect[i], ipVect[j]);

			i++; j--;

			//All pairs have been merged, start again
			if (j <= i)
				last = j;
		}
	}
	return ipVect[0];
}

int main()
{
	return 0;
}