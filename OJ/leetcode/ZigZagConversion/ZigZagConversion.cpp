/*
File Name : ZigZagConversion.cpp
Author: Jerry DENG (jerrydeng.windfly@gmail.com)
Time: 2014-11-26 23:17:18

Question:

The string "PAYPALISHIRING" is written in a zigzag pattern on a given number of rows like this: (you may want to display this pattern in a fixed font for better legibility)

P   A   H   N
A P L S I I G
Y   I   R
And then read line by line: "PAHNAPLSIIGYIR"
Write the code that will take a string and make this conversion given a number of rows:

string convert(string text, int nRows);
convert("PAYPALISHIRING", 3) should return "PAHNAPLSIIGYIR".

Tags: String;

Answer:


*/

#include "Common/Leetcode.h"

class Solution {
public:
    string convert(string s, int nRows) {
    	vector<string> v(nRows);
    	string res;
    	if(nRows<2){
    		if(nRows==0)
    			return res;
    		else
    			return s;
    	}
    	int loop_num = nRows+(nRows-2);
        int len = s.size();
 		for(int i=0; i<len; i++){
 			int row_num = i%loop_num;
 			if(row_num<nRows)
 				v[row_num].push_back(s[i]);
 			else
 				v[nRows-2-(row_num-nRows)].push_back(s[i]);
        }
        
        for(auto tmp: v){
        	res.append(tmp);
        }
        return res;
    }
};


int main(int argc, char** argv) {
	Solution sol;
	string s = "PAYPALISHIRING";
	cout<<"the converted string is "<<sol.convert(s,3)<<endl;

	return 0;
}
