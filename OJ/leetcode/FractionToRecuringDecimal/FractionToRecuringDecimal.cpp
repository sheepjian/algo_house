/*
File Name : FractionToRecuringDecimal.cpp
Author: Jerry DENG (jerrydeng.windfly@gmail.com)
Time: 2014-12-22 20:38:26

Question:

Given two integers representing the numerator and denominator of a fraction, 
return the fraction in string format.

If the fractional part is repeating, enclose the repeating part in parentheses.

For example,

Given numerator = 1, denominator = 2, return "0.5".
Given numerator = 2, denominator = 1, return "2".
Given numerator = 2, denominator = 3, return "0.(6)".


Tags: Hash Table; Math

Answer:

p/q = t...s (0=<s<q)
find the position when s repeats


*/

#include "Common/Leetcode.h"

class Solution {
public:
	string fractionToDecimal(int numerator, int denominator) {
		string s;
		if(denominator==0)
			return s;
		long long n=numerator,d=denominator;
		if(n*d<0)
			s.push_back('-');
		
		n = abs(n);
		d = abs(d);

		unordered_map<long long,int> table;
        long long dig = n/d;
        n %= d;

        for(auto k:to_string(dig))
        	s.push_back(k);
        if(n==0)
        	return s;
       	s.push_back('.');
       	int base = 10;
       	int count = s.size();
       	table[n] =count;
        while(n!=0) {
            n *= base;
            count++;
            if(n>=d){
            	s.push_back(n/d+'0');
            	n %=d;
            } else {
            	s.push_back('0');
            }
            if(n==0)
            	break;
            auto it = table.find(n);
            if(it==table.end()){
            	table[n] = count;
            }else {
            	s.insert(s.begin()+table[n],'(');
            	s.push_back(')');
            	break;
            }
        }
    	return s;
    }
};


int main(int argc, char** argv) {
	Solution sol;
	cout<<sol.fractionToDecimal(atoi(argv[1]),atoi(argv[2]))<<endl;

	return 0;
}
