/*
File Name : UniquePaths.cpp
Author: Jerry DENG (jerrydeng.windfly@gmail.com)
Time: 2014-11-16 17:10:33

Question:


The robot can only move either down or right at any point in time. 
The robot is trying to reach the bottom-right corner of the grid (marked 'Finish' in the diagram below).

How many possible unique paths are there?

Above is a 3 x 7 grid. How many possible unique paths are there?

Note: m and n will be at most 100.


Tags: Array; Dynamic Programming

Answer:


*/

#include "Common/Leetcode.h"

class Solution {
public:
	int uniquePaths(int m, int n) {
		int** path = new int*[m];
		for(int i=0; i<m; i++){
			path[i] = new int[n];
			path[i][0] = 1;
		}
		for(int j=1; j<n; j++) {
			path[0][j] = 1; 
		}
		for(int i=1; i<m; i++) {
			for(int j=1; j<n; j++) {
				path[i][j] = path[i-1][j]+path[i][j-1];
			}
		}
		return path[m-1][n-1];
    }

    int uniquePathsWithObstacles(vector<vector<int> > &obstacleGrid) {
    	int row = obstacleGrid.size();
        if(row>0){
        	int col = obstacleGrid[0].size();
        	if(col>0) {
        		int** path = new int*[row];
        		bool stuck_flag = false;
        		for(int i=0; i<row; i++){
        			path[i] = new int[col];
        			
        			if(obstacleGrid[i][0]==1||stuck_flag) {
        				path[i][0] = 0;
        				stuck_flag = true;
        			} else {
        				path[i][0] = 1;
        			}
        		}
        		stuck_flag = false;
        		for(int j=0; j<col; j++) {
        			if(obstacleGrid[0][j]==1||stuck_flag) {
        				path[0][j] = 0;
        				stuck_flag = true;
        			} else {
        				path[0][j] = 1;
        			} 
        		}	
        		for(int i=1; i<row; i++) {
        			for(int j=1; j<col; j++) {
        				path[i][j] = (obstacleGrid[i][j]==1)?0:path[i-1][j]+path[i][j-1];
        			}
        		}
        		return path[row-1][col-1];
        	}
        }
        return 0;
    }
};


int main(int argc, char** argv) {
	Solution sol;
	int m = atoi(argv[1]);
	int n = atoi(argv[2]);
	cout<<"there are "<<sol.uniquePaths(m,n)<<" unique Paths"<<endl;

	vector<vector<int> > obstacleGrid{{1,0}};

	cout<<"there are "<<sol.uniquePathsWithObstacles(obstacleGrid)<<" unique Paths"<<endl;



	return 0;
}
