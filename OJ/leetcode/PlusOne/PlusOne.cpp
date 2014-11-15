/*
Question:

Given a non-negative number represented as an array of digits, plus one to the number.

The digits are stored such that the most significant digit is at the head of the list.

Tags: Array; Math


Answer:

*/

#include "Common/Leetcode.h"

class Solution {
public:
    vector<int> plusOne(vector<int> &digits) {
        if(digits.size()==0)
        	digits.push_back(1);
        else {
        	int carry = 1;
        	for(int i=digits.size()-1; i>=0; i--){
        		if(digits[i]+carry==10) {
        			digits[i] =0;
        			carry=1;
        		}
        		else {
        			digits[i] += carry;
        			carry=0;
        		}
        	}
        	if(carry==1)
        		digits.insert(digits.begin(),1);
        }
        return digits;
    }
};


int main(int argc, char** argv) {
	Solution sol;
	vector<int> s{1,0,2,1};
	for(int i: s){
		cout<<i<<endl;
	}
	vector<int> g = sol.plusOne(s);
	for(auto i: g){
		cout<<i<<endl;
	}
	return 0;
}