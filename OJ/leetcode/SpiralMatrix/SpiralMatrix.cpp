/*
File Name : SpiralMatrix.cpp
Author: Jerry DENG (jerrydeng.windfly@gmail.com)
Time: 2014-11-16 23:16:13

Question:

Given a matrix of m x n elements (m rows, n columns), return all elements of the matrix in spiral order.

For example,
Given the following matrix:

[
 [ 1, 2, 3 ],
 [ 4, 5, 6 ],
 [ 7, 8, 9 ]
]
You should return [1,2,3,6,9,8,7,4,5].

Tags: Array;

Answer:


*/

#include "Common/Leetcode.h"

class Solution {
public:
	vector<int> spiralOrder(vector<vector<int> > &matrix) {
        vector<int> res;
        int row = matrix.size();
        if(row>0) {
        	int col = matrix[0].size();
        	if(col>0) {
        		int row_up=0, row_down = row-1;
        		int col_left=0, col_right = col-1;
        		while(row_up<=row_down||col_left<=col_right){
        			//first row
        			for(int i=col_left;i<=col_right;i++){
        				res.push_back(matrix[row_up][i]);
        			}
        			row_up++;
        			if(row_up>row_down)
        				break;
        			// rightest col
        			for(int i=row_up;i<=row_down; i++){
        				res.push_back(matrix[i][col_right]);
        			}
        			col_right--;
        			if(col_right<col_left)
        				break;
        			// last row
        			for(int i=col_right;i>=col_left;i--){
        				res.push_back(matrix[row_down][i]);
        			}
					row_down--;
        			//leftest col
        			for(int i=row_down;i>=row_up; i--){
        				res.push_back(matrix[i][col_left]);
        			}
        			col_left++;
        			if(row_down<row_up||col_left>col_right)
        				break;
        		}
        	}
        }
        return res;
    }
    vector<vector<int> > generateMatrix(int n) {
    	vector<vector<int>> matrix(n, vector<int>(n));
    	if(n>0) {
    		int row_up=0, row_down = n-1;
    		int col_left=0, col_right = n-1;
    		int start = 1;
    		while(row_up<=row_down||col_left<=col_right){
        			//first row
    			for(int i=col_left;i<=col_right;i++){
    				matrix[row_up][i] = start++;
    			}
    			row_up++;
    			if(row_up>row_down)
    				break;
        			// rightest col
    			for(int i=row_up;i<=row_down; i++){
    				matrix[i][col_right]=start++;
    			}
    			col_right--;
    			if(col_right<col_left)
    				break;
        			// last row
    			for(int i=col_right;i>=col_left;i--){
    				matrix[row_down][i]=start++;
    			}
    			row_down--;
        			//leftest col
    			for(int i=row_down;i>=row_up; i--){
    				matrix[i][col_left]=start++;
    			}
    			col_left++;
    			if(row_down<row_up||col_left>col_right)
    				break;
    		}
    	}
    	return matrix;
    }
};


int main(int argc, char** argv) {
	Solution sol;
	vector<vector<int> > matrix = {{ 1, 2, 3 },{4, 5, 6},{7, 8, 9}};
	std::vector<std::vector<int>> matrix1={{1,2,3,4,5,6,7,8,9,10}};
	std::vector<std::vector<int>> matrix2={{1,2,3,4,5,6,7,8,9,10},{11,12,13,14,15,16,17,18,19,20}};
	vector<int> v = sol.spiralOrder(matrix);
	for(int i: v)
		cout<<i<<" "<<endl;
	cout<<endl;
	vector<vector<int> > mat = sol.generateMatrix(3);
	for(auto i: mat) {
		for(auto j: i){
			cout<<j<<" ";
		}
		cout<<endl;
	}
	return 0;
}
