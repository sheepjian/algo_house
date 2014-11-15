/*
File Name : AddBinary.cpp
Author: Jerry DENG (jerrydeng.windfly@gmail.com)
Time: 2014-11-14 23:29:05

Question:

Given two binary strings, return their sum (also a binary string).

For example,
a = "11"
b = "1"
Return "100".

Tags: Math; String

Answer:


*/

#include "Common/Leetcode.h"

class Solution {
public:
	string addBinary(string a, string b) {
        string& max = a.size()>b.size()?a:b;
        string& min = a.size()<=b.size()?a:b;

        if(max.size()>0&&min.size()>0) {
        	int carry = 0;
        	int i = max.size()-1;
        	int j = min.size()-1;
        	while(j>=0) {
        		if((min[j]=='1'&&max[i]=='1') || (min[j]=='0'&&max[i]=='0') ) {
        			char str = max[i];
        			max[i] = carry?'1':'0';
        			carry = str=='1'?1:0;
        		} 
        		if ((min[j]=='0'&&max[i]=='1') || (min[j]=='1'&&max[i]=='0') ) {
        			max[i] = carry?'0':'1';
        			carry = carry?1:0;
        		} 
        		j--;
        		i--;
        	}
        	while(i>=0) {
        		char str = max[i];
        		max[i] = (str=='1'&&carry)||(str=='0'&&!carry)?'0':'1';
        		carry = (str=='1'&&carry)?1:0;
        		i--;
        	}
        	if(carry) max.insert(max.begin(),'1');
        }
        return max;
    }
};


int main(int argc, char** argv) {
	Solution sol;
	string a(argv[1]);
	string b(argv[2]);
	cout<<sol.addBinary(a,b)<<endl;

	return 0;
}
