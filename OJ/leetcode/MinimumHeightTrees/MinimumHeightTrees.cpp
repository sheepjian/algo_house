/*
File Name : MinimumHeightTrees.cpp
Author: Jerry DENG (jerrydeng.windfly@gmail.com)
Time: 2015-11-29 00:22:56

Question:
For a undirected graph with tree characteristics, we can choose any node as the root. 
The result graph is then a rooted tree. 
Among all possible rooted trees, those with minimum height are called minimum height trees (MHTs). 
Given such a graph, write a function to find all the MHTs and return a list of their root labels.

Format
The graph contains n nodes which are labeled from 0 to n - 1. 
You will be given the number n and a list of undirected edges (each edge is a pair of labels).

You can assume that no duplicate edges will appear in edges.
Since all edges are undirected, [0, 1] is the same as [1, 0] and thus will not appear together in edges.

Example 1:

Given n = 4, edges = [[1, 0], [1, 2], [1, 3]]

        0
        |
        1
       / \
      2   3
return [1]

Example 2:

Given n = 6, edges = [[0, 3], [1, 3], [2, 3], [4, 3], [5, 4]]

     0  1  2
      \ | /
        3
        |
        4
        |
        5
return [3, 4]



Tags: 


Answer:

Remove all the leaf nodes (degree<=1) in each iteration until there is no parent node (degree>1) exist

*/

#include "Common/Leetcode.h"

class Solution {
public:
    vector<int> findMinHeightTrees(int n, vector<pair<int, int>>& edges) {
        vector<int> results;

        if(n>0 && edges.size()==(n-1)) {
            // build adjacent node map
            vector<set<int>> map(n);
            for(auto edge: edges) {
                int a = edge.first;
                int b = edge.second;
                map[a].insert(b);
                map[b].insert(a);
            } 
            cout<<"i am here"<<endl;

            for(int i=0; i<n; i++)
                results.push_back(i);

            vector<int> leafs;
            vector<int> parents;
            while(results.size()>0) {
                leafs.clear();
                parents.clear();
                for(auto i: results) {
                    if(map[i].size()<=1) {
                        cout<<"the leaf node is "<<i<<endl;
                        leafs.push_back(i);
                    }
                    else
                        parents.push_back(i);
                }

                if(parents.size()>0) {
                    for(auto j: leafs) {
                        int parentId = *(map[j].begin());
                        map[parentId].erase(j);
                    }
                }
                cout<<"done"<<endl;

                results = parents;
            }
            results = leafs;
        }
        return results;
    }
};


int main(int argc, char const *argv[])
{
    Solution sol;
    vector<pair<int, int>> edges{{3, 0}, {1, 3}, {2, 3}, {4, 3}, {5, 4}};
    vector<pair<int, int>> edges2{{0,1}};
    vector<pair<int, int>> edges3{{0,1},{1,2},{2,3},{0,4},{4,5},{4,6},{6,7}};
    vector<int> results = sol.findMinHeightTrees(6,edges);
    cout<<"the root is "<<endl;
    for(auto i: results)
        cout<<i<<endl;
    cout<<"done"<<endl; 
    return 0;
}
