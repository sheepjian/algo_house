/*
File Name : ExcelSheetColumnTitle.cpp
Author: Jerry DENG (jerrydeng.windfly@gmail.com)
Time: 2014-12-21 21:16:37

Question:

Given a positive integer, return its corresponding column title as appear in an Excel sheet.

For example:

    1 -> A
    2 -> B
    3 -> C
    ...
    26 -> Z
    27 -> AA
    28 -> AB 



Tags: Math;


Answer:


*/

#include "Common/Leetcode.h"

class Solution {
public:
    string convertToTitle(int n) {
        if(n<1)
            return string();
        
        string res;
        while((n--)>0){
             res.push_back('A'+(n%26));
             n /= 26;
        }
        reverse(res.begin(),res.end());
        return res;
    }
};


int main(int argc, char** argv) {
	Solution sol;
	cout<<sol.convertToTitle(atoi(argv[1]))<<endl;

	return 0;
}
