/*
File Name : MedianOfTwoSortedArrays.cpp
Author: Jerry DENG (jerrydeng.windfly@gmail.com)
Time: 2014-11-22 22:19:41

Question:

There are two sorted arrays A and B of size m and n respectively. 
Find the median of the two sorted arrays. 
The overall run time complexity should be O(log (m+n)).


Tags: Divide and Conquer; Array; Binary Search

Answer:

find the kth min/max value algorithm of two sorted arrays



*/

#include "Common/Leetcode.h"

class Solution {
public:
    double findMedianSortedArrays(int A[], int m, int B[], int n) {
    	if((m+n)%2)
    		return findKth(A,m,B,n,(m+n)/2+1);
    	else
    		return (findKth(A,m,B,n,(m+n)/2)+findKth(A,m,B,n,(m+n)/2+1))/2;
    }
    double findKth(int a[], int m, int b[], int n, int k)
    {
		//always assume that m is equal or smaller than n
    	if (m > n)
    		return findKth(b, n, a, m, k);
    	if (m == 0)
    		return b[k - 1];
    	if (k == 1)
    		return min(a[0], b[0]);
		//divide k into two parts
    	int pa = min(k / 2, m), pb = k - pa;
    	if (a[pa - 1] < b[pb - 1])
    		return findKth(a + pa, m - pa, b, n, k - pa);
    	else if (a[pa - 1] > b[pb - 1])
    		return findKth(a, m, b + pb, n - pb, k - pb);
    	else
    		return a[pa - 1];
    }

};


int main(int argc, char** argv) {
	Solution sol;

	int A[] = {1,2,3,4,5};
	int B[] = {3,4,5,6,7};
	cout<<sol.findMedianSortedArrays(A,5,B,5)<<endl;

	return 0;
}
