/*
File Name : FactorialTrailingZeroes.cpp
Author: Jerry DENG (jerrydeng.windfly@gmail.com)
Time: 2014-12-31 00:48:48

Question:

Given an integer n, return the number of trailing zeroes in n!.

Note: Your solution should be in logarithmic time complexity.


Tags: 


Answer:


*/

#include "Common/Leetcode.h"

class Solution {
public:
    int trailingZeroes(int n) {
        int sum = 0;
        int m = 5;
        int l = n/m;
        while(l>=1){
        	sum += l;
        	m *= 5;
        	l = n/m;
        }
        return sum;
    }
};


int main(int argc, char** argv) {
	Solution sol;
	cout<<"the trailing zeroes is "<<sol.trailingZeroes(atoi(argv[1]))<<endl;
	return 0;
}
