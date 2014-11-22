/*
File Name : 3Sum.cpp
Author: Jerry DENG (jerrydeng.windfly@gmail.com)
Time: 2014-11-22 23:40:22

Question:

Given an array S of n integers, are there elements a, b, c in S such that a + b + c = 0? 
Find all unique triplets in the array which gives the sum of zero.

Note:
Elements in a triplet (a,b,c) must be in non-descending order. (ie, a ≤ b ≤ c)
The solution set must not contain duplicate triplets.
    For example, given array S = {-1 0 1 2 -1 -4},

    A solution set is:
    (-1, 0, 1)
    (-1, -1, 2)


Tags:  Array; Two Pointers

Answer:


*/

#include "Common/Leetcode.h"

class Solution {
public:
    vector<vector<int> > threeSum(vector<int> &num) {
        int len = num.size();
        vector<vector<int>> v;
        sort(num.begin(),num.end());

        for(int i=0; i<len-2; i++) {
        	int target = -num[i];
        	int start_id = i+1;
        	int rear_id = len-1;
        	while(start_id<rear_id) {
        		if(num[start_id]+num[rear_id]==target){
        			vector<int> sub{num[i],num[start_id],num[rear_id]};
        			v.push_back(sub);
        			start_id++;
        			rear_id--;
        			//avoid duplicate answer
        			while(start_id<rear_id&&num[start_id-1]==num[start_id]) start_id++;
        			while(start_id<rear_id&&num[rear_id+1]==num[rear_id]) rear_id--;
        		}else if(num[start_id]+num[rear_id]<target)
        			start_id++;
        		else
        			rear_id--;
        	}
        	//avoid duplicate answer
        	if(i<len-2) {
        		while(num[i]==num[i+1]) i++;
        	}
        }
        return v;
    }
};


int main(int argc, char** argv) {
	Solution sol;
	vector<int> S{-1, 0, 1, 2, -1, -4,5,0};
	vector<vector<int>> v = sol.threeSum(S);

	for(auto sub: v) {
		for(auto i:sub) {
			cout<<i<<" ";
		}
		cout<<endl;
	}

	return 0;
}
