/*
File Name : LetterCombinationsOfAPhoneNumber.cpp
Author: Jerry DENG (jerrydeng.windfly@gmail.com)
Time: 2014-12-02 22:50:56

Question:

Given a digit string, return all possible letter combinations that the number could represent.

A mapping of digit to letters (just like on the telephone buttons) is given below.



Input:Digit string "23"
Output: ["ad", "ae", "af", "bd", "be", "bf", "cd", "ce", "cf"].
Note:
Although the above answer is in lexicographical order, 
your answer could be in any order you want.

Tags: Backtracking; String


Answer:


*/

#include "Common/Leetcode.h"

class Solution {
public:
    //bfs algorithm
    vector<string> letterCombinations3(string digits) {
        vector<string> res;
        string tmp = "";
        dfsCombination(0,tmp,digits,res);
        return res;
        
    }

    void dfsCombination(int id, string tmp, string& digits, vector<string> &res){
        string numap[] = {" ","","abc","def","ghi","jkl","mno","pqrs","tuv","wxyz"};
        if(id==digits.size()){
            res.push_back(tmp);
            return;
        }
        string p = numap[digits[id]-'0'];
        //for 1
        if(p.size()==0)
            dfsCombination(id+1,tmp,digits,res);

        for(int i=0; i<p.size(); i++){
            tmp.push_back(p[i]);
            dfsCombination(id+1,tmp,digits,res);
            tmp.pop_back();
        }

    }


    //backtracking algorithm
    vector<string> letterCombinations2(string digits) {
        vector<string>res;
        vector<int> ansIndex(digits.size(), 0);
        string numap[] = {" ","","abc","def","ghi","jkl","mno","pqrs","tuv","wxyz"};
        
        while(true)
        {
            string tmp(digits.size(),' ');
            for(int i = 0; i < digits.size(); i++)
                tmp[i] = numap[digits[i]-'0'][ansIndex[i]];
            res.push_back(tmp);
            int k = digits.size() - 1;
            while(k >= 0)
            {
                if(ansIndex[k] < numap[digits[k]-'0'].size() - 1)
                {
                    ansIndex[k]++;
                    break;
                }
                else 
                {
                    ansIndex[k] = 0;
                    k--;
                }
            }
            if(k < 0)break;
        }
        
        return res;
    }

    vector<string> letterCombinations(string digits) {
        vector<string> res(1,"");
        string numap[] = {" ","","abc","def","ghi","jkl","mno","pqrs","tuv","wxyz"};
        for(int i = 0; i < digits.size(); i++)
        {
            vector<string>tmp;
            for(int j = 0; j < res.size(); j++)
                for(int k = 0; k < numap[digits[i] - '0'].size(); k++)
                    tmp.push_back(res[j] + numap[digits[i] - '0'][k]);
            res = tmp;
        }
         
        return res;
    }
};


int main(int argc, char** argv) {
	Solution sol;
	vector<string> res;
	res = sol.letterCombinations3(argv[1]);

	for(auto s: res){
		cout<<s<<endl;
	}
	return 0;
}
