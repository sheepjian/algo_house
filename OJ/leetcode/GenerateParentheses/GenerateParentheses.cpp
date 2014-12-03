/*
File Name : GenerateParentheses.cpp
Author: Jerry DENG (jerrydeng.windfly@gmail.com)
Time: 2014-12-03 15:13:32

Question:


Tags: 


Answer:


*/

#include "Common/Leetcode.h"

class Solution {
public:
    void completeParenthesis(int id, int size, int left, int right, vector<string>& res, string tmp){
        if(id==2*size){
            res.push_back(tmp);
            return;
        }
        if(left==right){
            tmp[id] = '(';
            completeParenthesis(id+1,size,left+1,right,res,tmp);
        } else {
            if(left<size){
                tmp[id] = '(';
                completeParenthesis(id+1,size,left+1,right,res,tmp);
                tmp[id] = ')';
                completeParenthesis(id+1,size,left,right+1,res,tmp);
            } else{
                tmp[id] = ')';
                completeParenthesis(id+1,size,left,right+1,res,tmp);
            }
        }
    }
    vector<string> generateParenthesis(int n) {
        vector<string> res;
        string tmp(2*n,' ');
        completeParenthesis(0,n,0,0,res, tmp);
        return res;
    }
};


int main(int argc, char** argv) {
	Solution sol;
	vector<string> res = sol.generateParenthesis(atoi(argv[1]));
	for(auto s: res){
		cout<<s<<endl;
	}
	return 0;
}
