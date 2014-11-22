/*
File Name : TwoSum.cpp
Author: Jerry DENG (jerrydeng.windfly@gmail.com)
Time: 2014-11-22 21:29:12

Question:

Given an array of integers, find two numbers such that they add up to a specific target number.

The function twoSum should return indices of the two numbers such that they add up to the target, 
where index1 must be less than index2. 
Please note that your returned answers (both index1 and index2) are not zero-based.

You may assume that each input would have exactly one solution.

Input: numbers={2, 7, 11, 15}, target=9
Output: index1=1, index2=2


Tags: Array; Hash Table

Answer:


*/

#include "Common/Leetcode.h"

class Solution {
public:
	vector<int> twoSum(vector<int> &numbers, int target) {
        unordered_map<int,int> table;
        vector<int> index;
        int size = numbers.size();
        //build the table
        for(int i=0; i<size; i++) {
        	auto it = table.find(target-numbers[i]);
        	if(it==table.end()) {
        		table[numbers[i]] = i+1;
        	} else {
        		index.push_back(it->second);
        		index.push_back(i+1);
        		break;
        	}
        }
        return index;
    }
};


int main(int argc, char** argv) {
	Solution sol;

	vector<int> numbers = {2, 7, 11, 15};
	int target = 9;
	vector<int> index = sol.twoSum(numbers,target);
	for(auto i: index) {
		cout<<"index: "<<i<<endl;
	}

	return 0;
}
