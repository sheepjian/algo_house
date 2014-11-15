/*
Question:

You are climbing a stair case. It takes n steps to reach to the top.

Each time you can either climb 1 or 2 steps. In how many distinct ways can you climb to the top?

Tags: Dynamic Programming

Answer:
stair[1] = 1
stait[2] = 2
stair[n] = stair[n-1]+stair[n-2] (n>2)
0, others
*/

#include "Common/Leetcode.h"

class Solution {
public:
    int climbStairs(int n) {
    	if(n<1)
    		return 0;
        int* stair = new int[n];
        for(int i=0; i<n; i++) {
        	if(i==0||i==1)
        		stair[i] = i+1;
        	else
        		stair[i] = stair[i-1]+stair[i-2];
        }
        return stair[n-1];
    }
};


int main(int argc, char** argv) {
	Solution sol;
	cout<<"there are "<<sol.climbStairs(stoi(argv[1]))<<" ways\n";
	return 0;
}