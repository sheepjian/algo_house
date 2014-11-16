/*
File Name : MinimumPathSum.cpp
Author: Jerry DENG (jerrydeng.windfly@gmail.com)
Time: 2014-11-16 14:49:26

Question:

Given a m x n grid filled with non-negative numbers, 
find a path from top left to bottom right which minimizes the sum of all numbers along its path.
Note: You can only move either down or right at any point in time.

Tags: Array； Dynamic Programming

Answer:
cost[i][j] = min(cost[i-1][j],cost[i][j-1])+grid[i][j];

*/

#include "Common/Leetcode.h"

class Solution {
public:
	int minPathSum(vector<vector<int> > &grid) {
        int row = grid.size();
        if(row>0){
        	int col = grid[0].size();
        	if(col>0) {
        		int** cost = new int*[row];
        		int sum = 0;
        		for(int i=0; i<row; i++){
        			cost[i] = new int[col];
        			sum += grid[i][0];
        			cost[i][0] = sum;
        		}
        		sum = grid[0][0];
        		for(int j=1; j<col; j++) {
        			sum += grid[0][j];
        			cost[0][j] = sum; 
        		}
        		for(int i=1; i<row; i++) {
        			for(int j=1; j<col; j++) {
        				cost[i][j] = min(cost[i-1][j],cost[i][j-1])+grid[i][j];
        			}
        		}
        		return cost[row-1][col-1];
        	}
        }
        return 0;
    }
};


int main(int argc, char** argv) {
	Solution sol;
	srand (time(NULL));
	std::vector<std::vector<int> > v;
	int row = 5, col = 4;
	for(int i=0; i <row; i++) {
		std::vector<int> z(col);
		for(int j=0; j<col; j++) {
			z[j] = rand()%10;
			cout<<z[j]<<" ";
		}
		cout<<endl;
		v.push_back(z);
	}

	cout<<"the min path sum is "<<sol.minPathSum(v)<<endl;


	return 0;
}
