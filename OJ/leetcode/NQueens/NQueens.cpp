/*
File Name : NQueens.cpp
Author: Jerry DENG (jerrydeng.windfly@gmail.com)
Time: 2014-11-19 14:53:10

Question:

The n-queens puzzle is the problem of placing n queens on an n×n chessboard 
such that no two queens attack each other.

Given an integer n, return all distinct solutions to the n-queens puzzle.

Each solution contains a distinct board configuration of the n-queens' placement, 
where 'Q' and '.' both indicate a queen and an empty space respectively.

For example,
There exist two distinct solutions to the 4-queens puzzle:

[
 [".Q..",  // Solution 1
  "...Q",
  "Q...",
  "..Q."],

 ["..Q.",  // Solution 2
  "Q...",
  "...Q",
  ".Q.."]
]


Tags: Backtracking

Answer:


*/



#include "Common/Leetcode.h"

class Solution {
public:
	vector<vector<string> > res;
     
    void printres(vector<int> A,int n){
        vector<string> r;
        for(int i=0;i<n;i++){
            string str(n,'.');
            str[A[i]]='Q';
            r.push_back(str);
        }
        res.push_back(r);
    }
     
     
    bool isValid(vector<int> A, int r){
        for (int i=0;i<r;i++){
            if ( (A[i]==A[r])||(abs(A[i]-A[r])==(r-i))){
                return false;
            }
        }
        return true;
    }
     
    void nqueens(vector<int> A, int cur, int n){
        if (cur==n){printres(A,n);}
        else{
            for (int i=0;i<n;i++){
                A[cur]=i;
                if (isValid(A,cur)){
                    nqueens(A,cur+1,n);
                }
            }
        }
    }
      
    vector<vector<string> > solveNQueens(int n) {
        res.clear();
        vector<int> A(n,-1);
        nqueens(A,0,n);
        return res;
    }

};


int main(int argc, char** argv) {
	Solution sol;

	vector<vector<string>> boards = sol.solveNQueens(atoi(argv[1]));

	for(auto board: boards) {
		for(auto row: board) {
			cout<<row<<endl;
		}
		cout<<"======="<<endl;
	}

	return 0;
}
