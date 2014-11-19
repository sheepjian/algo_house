/*
File Name : MaximumSubarray.cpp
Author: Jerry DENG (jerrydeng.windfly@gmail.com)
Time: 2014-11-18 13:49:40

Question:

Find the contiguous subarray within an array (containing at least one number)
 which has the largest sum.

For example, given the array [−2,1,−3,4,−1,2,1,−5,4],
the contiguous subarray [4,−1,2,1] has the largest sum = 6.


More practice:
If you have figured out the O(n) solution, 
try coding another solution using the divide and conquer approach, 
which is more subtle.


Tags: Divide and Conquer; Array; Dynamic Programming

Answer:


*/

#include "Common/Leetcode.h"

class Solution {
public:
	int maxSubArray(int A[], int n) {
		int global_max = A[0];
		int local_max = A[0];

		for(int i=1; i<n; i++){
			local_max = max(A[i],A[i]+local_max);
			global_max = max(global_max,local_max);
		}
		return global_max;
    }

    int maxSubArray_DAC(int A[], int n) {
		return subDAC(A,0,n-1);
    }

    int subCross(int* A, int left, int mid, int right) {
    	int left_sum = numeric_limits<int>::min();
    	int sum = 0;
    	for(int i=mid; i>=left; i--){
    		sum = sum+A[i];
    		if(sum>left_sum)
    			left_sum = sum;
    	}
    	sum = 0;
    	int right_sum = numeric_limits<int>::min();
    	for(int i=mid+1; i<=right; i++){
    		sum = sum+A[i];
    		if(sum>right_sum)
    			right_sum = sum;
    	}
    	return left_sum+right_sum;
    }

    int subDAC(int* A, int left, int right) {
    	if(left<right){
    		int mid = (left+right)/2;
    		return max(max(subDAC(A,left,mid),
						subDAC(A,mid+1,right)),
					subCross(A,left,mid,right));
    	} else 
    		return A[left];
    }
};


int main(int argc, char** argv) {
	Solution sol;
	int A[] = {-2,1,-3,4,-1,2,1,-5,4};
	cout<<"the largest subarray sum is "<<sol.maxSubArray_DAC(A,9)<<endl;
	return 0;
}
