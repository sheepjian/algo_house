/*
File Name : DivideTwoIntegers.cpp
Author: Jerry DENG (jerrydeng.windfly@gmail.com)
Time: 2014-11-23 16:07:40

Question:

Divide two integers without using multiplication, division and mod operator.


Tags: 


Answer:

using bit operation instead of multiplication


*/

#include "Common/Leetcode.h"

class Solution {
public:
	int divide(int dividend, int divisor) 
	{
		long long a = dividend;
		long long b = divisor;
		a = abs(a); b = abs(b);
		int res = 0;
		while (a>=b)
		{
			long long t = b;
			for (int i = 1; a >= t; i <<= 1, t <<= 1)
			{
				a -= t;
				res += i;
			}
		}
		return ((dividend<0)^(divisor<0))? -res:res;
	}
};


int main(int argc, char** argv) {
	Solution sol;

	int dividend = atoi(argv[1]);
	int divisor = atoi(argv[2]);

	cout<<"the quotient is "<<sol.divide(dividend,divisor)<<endl;


	return 0;
}
