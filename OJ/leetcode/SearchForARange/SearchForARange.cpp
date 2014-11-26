/*
File Name : SearchForARange.cpp
Author: Jerry DENG (jerrydeng.windfly@gmail.com)
Time: 2014-11-23 23:19:47

Question:

Given a sorted array of integers, find the starting and ending position of a given target value.

Your algorithm's runtime complexity must be in the order of O(log n).

If the target is not found in the array, return [-1, -1].

For example,
Given [5, 7, 7, 8, 8, 10] and target value 8,
return [3, 4].


Tags:  Array; Binary Search

Answer:


*/

#include "Common/Leetcode.h"

class Solution {
public:
	int searchStart(int* A, int start, int end, int target) {
		if(start<end) {
    		int mid = (start+end)/2;
    		if(A[mid]==target){
    			return searchStart(A,start,mid,target);
    		} else {
    			return searchStart(A,mid+1,end,target);
    		}
    	}
    	return end;
	}
	int searchEnd(int* A, int start, int end, int target) {
		if(start<end) {
    		int mid = (start+end)/2+1;
    		if(A[mid]==target){
    			return searchEnd(A,mid,end,target);
    		} else {
    			return searchEnd(A,start,mid-1,target);
    		}
    	}
    	return start;
	}
	vector<int> searchRange(int* A, int start, int end, int target) {
    	if(start<=end) {
    		int mid = (start+end)/2;
    		if(A[mid]==target){
    			int begin = searchStart(A,start,mid,target);
    			int stop = searchEnd(A,mid,end,target);
    			return {begin,stop};
    		} else if (A[mid]<target) {
    			return searchRange(A,mid+1,end,target);
    		} else {
    			return searchRange(A,start,mid-1,target);
    		}
    	}
    	return {-1,-1}; 
	}
    vector<int> searchRange(int A[], int n, int target) {
    	return searchRange(A,0,n-1,target);
    }
};


int main(int argc, char** argv) {
	Solution sol;
	int s[] = {5, 7, 7, 8, 8, 10};
	vector<int> res = sol.searchRange(s,6,8);
	cout<<"the range is from "<<res[0]<<" to "<<res[1]<<endl;
	return 0;
}
