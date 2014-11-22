/*
File Name : 3SumClosest.cpp
Author: Jerry DENG (jerrydeng.windfly@gmail.com)
Time: 2014-11-22 21:18:00

Question:

Given an array S of n integers, 
find three integers in S such that the sum is closest to a given number, target. 
Return the sum of the three integers. 
You may assume that each input would have exactly one solution.

For example, given array S = {-1 2 1 -4}, and target = 1.

The sum that is closest to the target is 2. (-1 + 2 + 1 = 2).


Tags: Array; Two Pointers		 


Answer:


*/

#include "Common/Leetcode.h"

class Solution {
public:
    int threeSumClosest(vector<int> &num, int target) {
        int len = num.size();
        int diff=INT_MAX;
        int res = 0;
        sort(num.begin(),num.end());

        for(int i=0; i<len-2; i++) {	
        	int start_id = i+1;
        	int rear_id = len-1;
        	while(start_id<rear_id) {
        		int obj = num[i]+num[start_id]+num[rear_id];
        		if(obj==target){
        			return target;
        		}else if(obj<target) {
        			start_id++;
        			if(target-obj<diff){
        				res = obj;
        				diff = target-obj;
        			}
        		}
        		else {
        			rear_id--;
        			if(obj-target<diff){
        				res = obj;
        				diff = obj-target;
        			}
        		}
        	}
        	//avoid duplicate answer
        	if(i<len-2) {
        		while(num[i]==num[i+1]) i++;
        	}
        }
        return res;
    }
};


int main(int argc, char** argv) {
	Solution sol;
	vector<int> s = {1,1,-1,-1,3};
	cout<<"the closest target is "<<sol.threeSumClosest(s,-1)<<endl;

	return 0;
}
