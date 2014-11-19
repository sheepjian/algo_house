/*
File Name : Pow.cpp
Author: Jerry DENG (jerrydeng.windfly@gmail.com)
Time: 2014-11-19 14:04:39

Question:

Implement pow(x, n).

Tags: Math; Binary Search

Answer:


*/

#include "Common/Leetcode.h"

class Solution {
public:
	double pow(double x, int n) {
        if(n==0)
            return 1;
        if(n<0)
        {
            x = 1/x;
            n = -n;
        }

        double res = 1;

        if(n==1)
        	return x;
       	else
       	{
       		double t = pow(x,n/2);
       		res = t*t;
       		if(n%2)
       			res *= x;
       		return res;
       	}
    }
};


int main(int argc, char** argv) {
	Solution sol;  

	cout<<sol.pow(atof(argv[1]),atoi(argv[2]))<<endl;

	return 0;
}
