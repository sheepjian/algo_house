/*
Question:

Implement int sqrt(int x).

Compute and return the square root of x.

Tags: Math; Binary Search

Answer:

Newton method to solve the nonlinear equation
x_{n+1} = x_n - f(x_n)/f^'(x_n)

Thus,
f(x) = x^2 - m   // find the sqrt(m)
f^'(x) = 2*x;
x_{n+1} = x_n/2 + m/(2*x_n)
*/

#include "Common/Leetcode.h"

class Solution {
public:
    int sqrt(int x) {
        assert(x>=0);
        int max_iter = 100;
        double y = double(x);
        double tol = 10e-6;
       	double guess = 1;
       	int iter = 0;
       	while(abs(y-guess*guess)>tol&&iter<max_iter){
       		guess = guess/2+y/(2*guess);
       		iter++;
       	}
       	return guess;
    }
};


int main(int argc, char** argv) {
	Solution sol;
	int x = stoi(argv[1]);
	cout<<"the sqrt root of "<<x<<" is "<<sol.sqrt(x)<<"\n";
	return 0;
}