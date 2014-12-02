/*
File Name : RegularExpressionMatching.cpp
Author: Jerry DENG (jerrydeng.windfly@gmail.com)
Time: 2014-11-29 18:33:29

Question:

mplement regular expression matching with support for '.' and '*'.

'.' Matches any single character.
'*' Matches zero or more of the preceding element.

The matching should cover the entire input string (not partial).

The function prototype should be:
bool isMatch(const char *s, const char *p)

Some examples:
isMatch("aa","a") → false
isMatch("aa","aa") → true
isMatch("aaa","aa") → false
isMatch("aa", "a*") → true
isMatch("aa", ".*") → true
isMatch("ab", ".*") → true
isMatch("aab", "c*a*b") → true


Tags: Dynamic Programming; Backtracking; String


Answer:


*/

#include "Common/Leetcode.h"

class Solution {
public:
	bool isMatch(const char *s, const char *p) {   
		if( 0 == *p) return 0 == *s;

		if(*(p+1) != '*')
		{
			if(*p == *s || ((*p) == '.' && (*s) != 0))
			{
				return isMatch(s+1, p+1);
			}
			return false;
		}
		else
		{
			while(*p == *s || ((*p) == '.' && (*s) != 0))
			{
				if(isMatch(s, p + 2))
				{
					return true;
				}
				s++;
			}
			return isMatch(s, p + 2);
		}
		
	}
};




int main(int argc, char** argv) {
	Solution sol;
	if(sol.isMatch(argv[1],argv[2]))
		cout<<"matched"<<endl;
	else
		cout<<"unmatched"<<endl;

	return 0;
}
