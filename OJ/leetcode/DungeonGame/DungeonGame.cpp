/*
File Name : DungeonGame.cpp
Author: Jerry DENG (jerrydeng.windfly@gmail.com)
Time: 2015-01-06 20:48:48

Question:

he demons had captured the princess (P) and imprisoned her in the bottom-right corner of a dungeon. 
The dungeon consists of M x N rooms laid out in a 2D grid. 
Our valiant knight (K) was initially positioned in the top-left room 
and must fight his way through the dungeon to rescue the princess.

The knight has an initial health point represented by a positive integer. 
If at any point his health point drops to 0 or below, he dies immediately.

Some of the rooms are guarded by demons, so the knight loses health (negative integers) 
upon entering these rooms; other rooms are either empty (0's) or contain magic orbs 
that increase the knight's health (positive integers).

In order to reach the princess as quickly as possible, the knight decides to move only rightward 
or downward in each step.


Write a function to determine the knight's minimum initial health 
so that he is able to rescue the princess.

For example, given the dungeon below, the initial health of the knight must be at least 7 
if he follows the optimal path RIGHT-> RIGHT -> DOWN -> DOWN.

-2 (K)	-3	3
-5	-10	1
10	30	-5 (P)

Notes:

The knight's health has no upper bound.
Any room can contain threats or power-ups, 
even the first room the knight enters and the bottom-right room where the princess is imprisoned.


Tags:  Dynamic Programming; Binary Search

Answer:

reverse the process of finding the minimum need

this provides a solution to find the path has the max minimum value 

similar question: the gas a car needs before the start of the trip

for the dynamic programming, try to find the deterministic f(0) or f(1), or define it first

*/

#include "Common/Leetcode.h"

class Solution {
public:
    int calculateMinimumHP(vector<vector<int> > &dungeon) {
        int row = dungeon.size();
	    int col = dungeon[0].size();
	    int A[row][col];

	    // 1. when the knight reached the bottom right corner
	    A[row-1][col-1] = (dungeon[row-1][col-1] > 0) ? 1 : (1 - dungeon[row-1][col-1]);

	    // 2. in the last column, bottom-up;
	    for(int i = row - 2; i >= 0; --i) {
	        int aboveValue = A[i+1][col-1] - dungeon[i][col-1];
	        A[i][col-1]  = aboveValue > 0 ? aboveValue : 1;
	    }

	    // 3. in the last row, from right to left
	    for(int j = col - 2; j >= 0; --j) {
	        int leftValue = A[row-1][j+1] - dungeon[row-1][j];
	        A[row-1][j]  = leftValue > 0 ? leftValue : 1;
	    }

	    // 4. in other areas, from bottom-right to upper-left
	    for(int i = row - 2; i >=0; --i) {
	        for(int j = col - 2; j >= 0; --j) {
	            int rightValue = (A[i][j+1]-dungeon[i][j] > 0) ? A[i][j+1]-dungeon[i][j] : 1;
	            int belowValue = (A[i+1][j]-dungeon[i][j] > 0) ? A[i+1][j]-dungeon[i][j] : 1;
	            A[i][j] = min(rightValue, belowValue);
	        }
	    }
	    return A[0][0];
    }
};


int main(int argc, char** argv) {
	Solution sol;

	//vector<vector<int> > dungeon{{-2,-3,3},{-5,-10,1},{10,30,-5}};
	vector<vector<int> > dungeon{{0,-74,-47,-20,-23,-39,-48},{37,-30,37,-65,-82,28,-27},{-76,-33,7,42,3,49,-93},{37,-41,35,-16,-96,-56,38},{-52,19,-37,14,-65,-42,9},{5,-26,-30,-65,11,5,16},{-60,9,36,-36,41,-47,-86},{-22,19,-5,-41,-8,-96,-95}};

	cout<<sol.calculateMinimumHP(dungeon)<<endl;


	return 0;
}
