/*
File Name : q0329.h
Author: Jerry DENG (jerrydeng.windfly@gmail.com)
Time: 2016-01-23 11:14:58
*/

class Solution {
public:
    int longestIncreasingPath(vector<vector<int>>& matrix) {
        int result = 0;
        int n = matrix.size();
        if(n>0){
            int m = matrix[0].size();
            if(m>0) {
                vector<vector<int>> records(n,vector<int>(m));
                for(int i=0; i<n; i++) {
                    for(int j=0; j<m; j++) {
                        int depth = DFS(i,j,n,m,records, matrix);
                        if(depth>result)
                            result = depth;
                    }
                }
            }
        }
        return result;
    }
    
    int DFS(int r, int c, int row, int col, vector<vector<int>>& records, vector<vector<int>>& matrix) {
        if(records[r][c]==0) {
            records[r][c] = 1;
            if(r+1<row&&matrix[r+1][c]>matrix[r][c]) {
                int d1 = DFS(r+1,c,row,col,records,matrix);
                if(d1+1>records[r][c])
                    records[r][c] = d1+1;
            }
            if(c+1<col&&matrix[r][c+1]>matrix[r][c]) {
                int d2 = DFS(r,c+1,row,col,records,matrix);
                if(d2+1>records[r][c])
                    records[r][c] = d2+1;
            }

            if(r-1>=0&&matrix[r-1][c]>matrix[r][c]) {
                int d3 = DFS(r-1,c,row,col,records,matrix);
                if(d3+1>records[r][c])
                    records[r][c] = d3+1;
            }
            if(c-1>=0&&matrix[r][c-1]>matrix[r][c]) {
                int d4 = DFS(r,c-1,row,col,records,matrix);
                if(d4+1>records[r][c])
                    records[r][c] = d4+1;
            }
        }
        return records[r][c];
    }
};