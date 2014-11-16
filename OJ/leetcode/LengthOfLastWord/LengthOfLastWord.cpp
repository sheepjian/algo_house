/*
File Name : LengthOfLastWord.cpp
Author: Jerry DENG (jerrydeng.windfly@gmail.com)
Time: 2014-11-16 23:08:45

Question:

Given a string s consists of upper/lower-case alphabets and empty space characters ' ', return the length of last word in the string.

If the last word does not exist, return 0.

Note: A word is defined as a character sequence consists of non-space characters only.

For example, 
Given s = "Hello World",
return 5.

Tags: string;


Answer:


*/

#include "Common/Leetcode.h"

class Solution {
public:
	int lengthOfLastWord(const char *s) {
		int res = 0;
		int i = 0;
		while(s[i]) {
			if(s[i]!=' ') {
				if(res!=0) res = 0;
				while(s[i]!='\0'&&s[i]!=' '){
					res++;
					i++;
				}
			}
			if(s[i]=='\0') break;
			i++;
		}
		return res;
    }
};


int main(int argc, char** argv) {
	Solution sol;
	const char* s = "Hello World 	";
	cout<<"the length of the last word is "<<sol.lengthOfLastWord(s)<<endl;

	return 0;
}
