/*
File Name : LongestPalindromicSubstring.cpp
Author: Jerry DENG (jerrydeng.windfly@gmail.com)
Time: 2014-11-26 21:13:13

Question:

Given a string S, find the longest palindromic substring in S. 
You may assume that the maximum length of S is 1000, 
and there exists one unique longest palindromic substring.


Tags: String;


Answer:

Noted that there is O(N) algorithm mentioned in 
http://leetcode.com/2011/11/longest-palindromic-substring-part-ii.html

*/

#include "Common/Leetcode.h"

class Solution {
public:
    string longestPalindrome(string s) {
        int maxID, maxLen;
        int len = s.size();
        bool table[1000][1000];
        //vector<vector<bool>> table(len,vector<bool>(len,false));
        for(int step=0; step<len; step++) {
	        for(int j=0; j<len-step; j++){
	        	if(step==0) {
	        		table[j][j]=true;
	    			maxID = j;
	    			maxLen = 1;
	        	} else if(step==1){
	        		if(s[j]==s[j+1]){
	        			table[j][j+step]=true;
	        			maxID = j;
	        			maxLen = 2;
	        		}
	        	} else {
	        		if(s[j]==s[j+step]&&table[j+1][j+step-1]){
	        			table[j][j+step]=true;
	        			maxID = j;
	        			maxLen = step+1;
	        		}
	        	}
	        }
    	}
        return s.substr(maxID,maxLen);
    }
};


int main(int argc, char** argv) {
	Solution sol;
	string s = "abcba";
	cout<<"the longest palindromic of the string is "<<sol.longestPalindrome(s)<<endl;

	return 0;
}
