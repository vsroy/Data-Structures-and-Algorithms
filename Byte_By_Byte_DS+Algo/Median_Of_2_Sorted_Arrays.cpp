//Given two sorted arrays, a[] and b[], the task is to find the median of these sorted arrays, in O(log n + log m) time complexity, when n is the number of elements in the first array, and m is the number of elements in the second array.

#include<iostream>
#include<vector>
using namespace std;

float FindMedian(vector<int> ar1, vector<int> ar2)
{	
	int n = ar1.size(), m = ar2.size();
	int count = 0;
	int m1 = 0,m2 = 0;
	/* Current index of input array ar1[] */
	/* Current index of input array ar2[] */
	int i = 0, j = 0;

    // Since there are (n+m) elements,  
    // There are following two cases  
    // if n+m is odd then the middle  
    //index is median i.e. (m+n)/2  
	
	//If combined array has odd elements
	if ((m + n) % 2 == 1) {
		for (count = 0; count <= (n + m) / 2; count++) {
			if (i != n && j != m){
				m1 = (ar1[i] > ar2[j]) ? ar2[j++] : ar1[i++];
			}
			else if (i < n){
				m1 = ar1[i++];
			}
			// for case when j<m, 
			else{
				m1 = ar2[j++];
			}
		}
		return m1;
	}
		
	
	// median will be average of elements  
	// at index ((m+n)/2 - 1) and (m+n)/2 
	// in the array obtained after merging ar1 and ar2 
	else {
		for (count = 0; count <= (n + m) / 2; count++) {
			m2 = m1;
			if (i != n && j != m){
				m1 = (ar1[i] > ar2[j]) ? ar2[j++] : ar1[i++];
			}
			else if (i < n){
				m1 = ar1[i++];
			}
			// for case when j<m, 
			else{
				m1 = ar1[j++];
			}
		}
		return (m1 + m2) / 2;
	}
}

int main()
{
	vector<int> arr1{900};
	vector<int> arr2{5,8,10,20};
	cout << FindMedian(arr1,arr2);
	return 0;
}