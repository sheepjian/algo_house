/*
File Name : Anagrams.cpp
Author: Jerry DENG (jerrydeng.windfly@gmail.com)
Time: 2014-11-19 16:20:02

Question:

Given an array of strings, return all groups of strings that are anagrams.

Note: All inputs will be in lower-case.

a word, phrase, or name formed by rearranging the letters of another, 
such as cinema, formed from iceman.

Tags:  Hash Table; String



Answer:


*/

#include "Common/Leetcode.h"

class Solution {
public:
    vector<string> anagrams(vector<string> &strs) {
        vector<string> res;
        if (strs.size() <= 1) return res;
        map<string, int> anagram;
        for (int i = 0; i < strs.size(); ++i)
        {
            string s = strs[i];
            sort(s.begin(), s.end());
            if (anagram.find(s) == anagram.end()) {
                anagram.insert(make_pair(s, i));
            } else {
                if (anagram[s] >= 0) {
                    res.push_back(strs[anagram[s]]);
                    anagram[s] = -1;
                }
                res.push_back(strs[i]);
            }
        }
        return res;
    }
};	

int main(int argc, char** argv) {
	Solution sol;
	std::vector<string> strs{"tea","ate","tae","cce","ecc","bgg","kkk"};
	std::vector<string> v = sol.anagrams(strs);
	for(auto s: v){
		cout<<s<<endl;
	}
	return 0;
}
