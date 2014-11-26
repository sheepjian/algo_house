/*
File Name : LongestSubstringWithoutRepeatingCharacters.cpp
Author: Jerry DENG (jerrydeng.windfly@gmail.com)
Time: 2014-11-23 22:09:28

Question:

Given a string, 
find the length of the longest substring without repeating characters. 
For example, the longest substring without repeating letters for "abcabcbb" is "abc", 
which the length is 3. 
For "bbbbb" the longest substring is "b", with the length of 1.


Tags: 


Answer:


*/

#include "Common/Leetcode.h"

class Solution {
public:
	int lengthOfLongestSubstring(string s) {
		int res = 0;
		unordered_map<char, int> table;
		int count = 0;
		int lastDup = -1;
		for(int i=0; i<s.size(); i++) {
			auto it = table.find(s[i]);
			if(it==table.end()){
				table[s[i]] = i;
				count++;
			} else {
				if(count>res)
					res = count;
				if(lastDup==-1){
					lastDup = table[s[i]];
					count = i-table[s[i]];
				} 
				else {
					count = i-max(table[s[i]],lastDup); 
					lastDup = max(lastDup,table[s[i]]);
				}
				table[s[i]] = i;
			}
		}
		if(count>res)
			res = count;
		return res;
    }
};


int main(int argc, char** argv) {
	Solution sol;
	cout<<"the longest substring length is "<<sol.lengthOfLongestSubstring(string(argv[1]))<<endl;

	return 0;
}
