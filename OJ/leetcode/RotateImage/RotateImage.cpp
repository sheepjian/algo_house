/*
File Name : RotateImage.cpp
Author: Jerry DENG (jerrydeng.windfly@gmail.com)
Time: 2014-11-19 15:34:27

Question:

You are given an n x n 2D matrix representing an image.

Rotate the image by 90 degrees (clockwise).

Follow up:
Could you do this in-place?


Tags: Array;


Answer:


*/

#include "Common/Leetcode.h"

class Solution {
public:
	void clockwiseSwap(vector<vector<int> > &matrix,int top_left, int right_down, int j){
		int temp = matrix[top_left][top_left+j];
		matrix[top_left][top_left+j] = matrix[right_down-j][top_left];
		matrix[right_down-j][top_left] = matrix[right_down][right_down-j];
		matrix[right_down][right_down-j] = matrix[top_left+j][right_down];
		matrix[top_left+j][right_down] = temp; 
	}
	void rotate(vector<vector<int> > &matrix) {
        int N = matrix.size();
        int top_left = 0, right_down = N-1;
        //circle swap
        for(; top_left<N/2; top_left++) {
        	for(int j=0; j<right_down - top_left; j++){
        		clockwiseSwap(matrix,top_left,right_down,j);
        	}
        	right_down--;
        }
    }
};


int main(int argc, char** argv) {
	Solution sol;
	vector<vector<int> > matrix{{1,2,3,4},{5,6,7,8},{9,10,11,12},{13,14,15,16}};
	sol.rotate(matrix);

	for(auto board: matrix) {
		for(auto row: board) {
			cout<<row<<" ";
		}
		cout<<endl;
	}

	return 0;
}
