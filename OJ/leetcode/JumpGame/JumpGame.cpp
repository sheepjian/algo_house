/*
File Name : JumpGame.cpp
Author: Jerry DENG (jerrydeng.windfly@gmail.com)
Time: 2014-11-17 15:26:46

Question:

Given an array of non-negative integers, 
you are initially positioned at the first index of the array.

Each element in the array represents your maximum jump length at that position.

Determine if you are able to reach the last index.

For example:
A = [2,3,1,1,4], return true.

A = [3,2,1,0,4], return false.


Tags: Array; Greedy

Answer:


*/

#include "Common/Leetcode.h"

class Solution {
public:
	bool canJump(int A[], int n) {
		if(n==0)
			return false;
		if(n==1)
			return true;

		int current_id = 0;
		int end = n-1;
		int max_jump = A[current_id];
		while(max_jump!=0) {
			if(current_id+A[current_id]>=end)
				return true;
			int largest_jump = max_jump; 
			for(int i=current_id+1;i<=current_id+largest_jump;i++){
				if(i+A[i]>=end)
					return true;
				if((i-current_id+A[i])>max_jump) {
					max_jump = i-current_id+A[i];
				}
			}
			max_jump = max_jump-largest_jump;
			current_id = largest_jump+current_id;
		}
		return false;
    }
};


int main(int argc, char** argv) {
	Solution sol;
	int A[] ={2,0,1,1,2,1,0,0,0};
	if(sol.canJump(A,9))
		cout<<"reached"<<endl;
	else
		cout<<"failed"<<endl;


	return 0;
}
