/*
File Name : MaximumProductSubarray.cpp
Author: Jerry DENG (jerrydeng.windfly@gmail.com)
Time: 2014-11-15 16:04:43

Question:

Find the contiguous subarray within an array (containing at least one number)
which has the largest product.

For example, given the array [2,3,-2,4],
the contiguous subarray [2,3] has the largest product = 6.

Tags: Array; Dynamic Programming

Answer:
We can design a O(n) algorithm to record the local_min and local_max, 
the compare the global_max with the local_max

*/

#include "Common/Leetcode.h"

class Solution {
public:
	int maxSum(int A[], int n){
		int global_max = A[0];
		int local_max = A[0];
		for(int i=1; i<n; i++) {
			local_max = max(local_max+A[i],A[i]);
			global_max = max(local_max,global_max);
		}
		return global_max;
	}
	int maxProduct(int A[], int n) {
		int global_max = A[0];
		int local_max = A[0];
		int local_min = A[0];
		for(int i=1; i<n; i++) {
			int local_copy = local_max;
			local_max = max(max(A[i],local_max*A[i]), local_min*A[i]);
			local_min = min(min(A[i],local_min*A[i]), local_copy*A[i]);
			global_max = max(global_max,local_max);
		} 
		return global_max;
    }
};


int main(int argc, char** argv) {
	Solution sol;
	int A[] = {2,3,-5,9,-8,6};
	cout<<"the max contiguous product is "<<sol.maxSum(A,6)<<endl;
	return 0;
}
