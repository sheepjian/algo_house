/*
File Name : ValidSudoku.cpp
Author: Jerry DENG (jerrydeng.windfly@gmail.com)
Time: 2014-11-24 00:11:01

Question:

Determine if a Sudoku is valid, according to: Sudoku Puzzles - The Rules.

The Sudoku board could be partially filled, 
where empty cells are filled with the character '.'.


A partially filled sudoku which is valid.

Note:
A valid Sudoku board (partially filled) is not necessarily solvable. 
Only the filled cells need to be validated.


Tags: Hash Table;


Answer:


*/

#include "Common/Leetcode.h"

class Solution {
public:
	bool checkValidSudoku(vector<pair<int, int>>& points,pair<int,int> pos) {
		for(auto p: points) {
			if(p.first==pos.first||p.second==pos.second)
				return false;
			int i_p = p.first/3, j_p = p.second/3;
			int i_pos = pos.first/3, j_pos =pos.second/3;
			if(i_p==i_pos&&j_p==j_pos)
				return false;
		}
		return true;
	}
    bool isValidSudoku(vector<vector<char> > &board) {
    	unordered_map<char, vector<pair<int, int>>> table;
    	int row = board.size();
    	int col = board[0].size();
    	for(int i=0; i<row; i++) {
    		for(int j=0; j<col; j++) {
    			char s = board[i][j];
    			if(s!='.') {
    				auto it = table.find(s);
    				pair<int, int> pos = make_pair(i,j);
    				if(it==table.end()){
    					table[s] = vector<pair<int,int>>{pos};
    				} else {
    					if(!checkValidSudoku(table[s],pos))
    						return false;
    					else
    						table[s].push_back(pos);
    				}
    			}
    		}
    	}
    	return true;
    }
    void solveSudoku(vector<vector<char> > &board) {
    	int row = board.size();
    	int col = board[0].size();
    	unordered_map<char, vector<pair<int, int>>> table;
        vector<pair<int, int>> waiting_points;
        vector<pair<int, int>> confirmed_points;
        // build the incomplete table
    	for(int i=0; i<row; i++) {
    		for(int j=0; j<col; j++) {
    			char s = board[i][j];
                pair<int, int> pos = make_pair(i,j);
    			if(s!='.') {
    				auto it = table.find(s);
    				if(it==table.end()){
    					table[s] = vector<pair<int,int>>{pos};
    				} else {
    					table[s].push_back(pos);
    				}
    			} else {
                    waiting_points.push_back(pos);
                } 
    		}
    	}
        bool backtrack = false;
        while(!waiting_points.empty()) {
            auto it = waiting_points.back();
            int i = 1;
            if(board[it.first][it.second] !='.') {
                if(backtrack)
                    i = (board[it.first][it.second]-'0') + 1;
            }
            for(; i<=9; i++) {
                char mark = i+'0';
                if(checkValidSudoku(table[mark],it))
                {
                    board[it.first][it.second] = mark;
                    backtrack = false;
                    auto tt = table.find(mark);
                    if(tt==table.end()){
                        table[mark] = vector<pair<int,int>>{it};
                    } else {
                        table[mark].push_back(it);
                    }
                    confirmed_points.push_back(it);
                    waiting_points.pop_back();
                    break;
                }
            }
            if(i>9){
                if(!confirmed_points.empty()) {
                    backtrack = true;
                    auto ti = confirmed_points.back();
                    waiting_points.push_back(ti);
                    confirmed_points.pop_back();
                    table[board[ti.first][ti.second]].pop_back();
                } else {
                    cout<<"no avaliable solutions"<<endl;
                    return;
                }
            }
        }

    }
};

int main(int argc, char** argv) {
	Solution sol;

	vector<string> t = {
		"..9748...",
		"7........",
		".2.1.9...",
		"..7...24.",
		".64.1.59.",
		".98...3..",
		"...8.3.2.",
		"........6",
		"...2759.."
	};

	vector<vector<char> > board;
	for(auto s:t){
		vector<char> row(s.begin(),s.end());
		board.push_back(row);
	}

	if(sol.isValidSudoku(board))
		cout<<"yes, it is"<<endl;

    sol.solveSudoku(board);
    for(auto s:board){
        for(auto c: s){
            cout<<c<<" ";
        }
        cout<<endl;
    }
	return 0;
}
