/*
File Name : 4Sum.cpp
Author: Jerry DENG (jerrydeng.windfly@gmail.com)
Time: 2014-11-23 01:09:44

Question:

Given an array S of n integers, 
are there elements a, b, c, and d in S such that a + b + c + d = target? 
Find all unique quadruplets in the array which gives the sum of target.

Note:
Elements in a quadruplet (a,b,c,d) must be in non-descending order. (ie, a ≤ b ≤ c ≤ d)
The solution set must not contain duplicate quadruplets.
    For example, given array S = {1 0 -1 0 -2 2}, and target = 0.

    A solution set is:
    (-1,  0, 0, 1)
    (-2, -1, 1, 2)
    (-2,  0, 0, 2)


Tags: 


Answer:


*/

#include "Common/Leetcode.h"

class Solution {
public:
	vector<vector<int> > fourSum(vector<int> &num, int target) {
        int n = num.size();
        vector<vector<int> > res;
        unordered_map<int, vector<pair<int, int> > >pairs;
        pairs.reserve(n*n);
        sort(num.begin(), num.end());
        
        for(int i = 0; i < n; i++)
            for(int j = i+1 ; j < n; j++)
                pairs[num[i]+num[j]].push_back(make_pair(i,j));
        
        for(int i = 0; i < n - 3; i++)
        {
            if(i != 0 && num[i] == num[i-1])continue;
            for(int j = i+1; j < n - 2; j++)
            {
                if(j != i+1 && num[j] == num[j-1])continue;
                if(pairs.find(target - num[i] - num[j]) != pairs.end())
                {
                    vector<pair<int, int>> &sum2 = pairs[target - num[i] - num[j]];
                    bool isFirstPush = true;
                    for(int k = 0; k < sum2.size(); k++)
                    {
                        if(sum2[k].first <= j)continue;
                        if(isFirstPush || (res.back())[2] != num[sum2[k].first])
                        {
                            res.push_back(vector<int>{num[i], num[j], num[sum2[k].first], num[sum2[k].second]});
                            isFirstPush = false;
                        }
                    }
                }
            }
        }
        
        return res;
    }
};


int main(int argc, char** argv) {
	Solution sol;

	return 0;
}
