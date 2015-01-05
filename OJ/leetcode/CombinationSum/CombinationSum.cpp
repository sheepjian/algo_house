/*
File Name : CombinationSum.cpp
Author: Jerry DENG (jerrydeng.windfly@gmail.com)
Time: 2014-12-04 13:11:39

Question:

Given a set of candidate numbers (C) and a target number (T), 
find all unique combinations in C where the candidate numbers sums to T.

The same repeated number may be chosen from C unlimited number of times.

Note:
All numbers (including target) will be positive integers.
Elements in a combination (a1, a2, … , ak) must be in non-descending order. (ie, a1 ≤ a2 ≤ … ≤ ak).
The solution set must not contain duplicate combinations.
For example, given candidate set 2,3,6,7 and target 7, 
A solution set is: 
[7] 
[2, 2, 3] 

Tags:  Array; Backtracking


Answer:


*/

#include "Common/Leetcode.h"

class Solution {
public:
    vector<vector<int> > combinationSum2(vector<int> &candidates, int target) {
        sort(candidates.begin(),candidates.end());
        candidates.erase(
        	remove_if(candidates.begin(), candidates.end(),[target](int n){ return n>target;}),
        	candidates.end()
        );

        vector<vector<int>> res;
        int sum = 0;
        vector<int> item;
        bool duplicate = false;
        combinationSumSub2(candidates,target,0,res,item, duplicate);
        return res;
    }
    void combinationSumSub2(vector<int> &candidates, int target, 
    	int start, vector<vector<int>> &res, vector<int> &item, bool duplicate)
    {
    	if(target<0)
    		return;
    	if(target==0){
    		res.push_back(item);
    		return;
    	} else {
    		for(int i=start; i<candidates.size(); i++){
    			if(i>0&&candidates[i]==candidates[i-1]){
    					if(duplicate)
    			 			continue;
    			}
    			if(i>0&&candidates[i]!=candidates[i-1])
    				duplicate = false;
    			item.push_back(candidates[i]);
    			combinationSumSub2(candidates,target-candidates[i],i+1,res,item,duplicate);
    			item.pop_back();
    			duplicate = true;
    		}
    	}
    }

    vector<vector<int> > combinationSum(vector<int> &candidates, int target) {
        sort(candidates.begin(),candidates.end());
        candidates.erase(
        	remove_if(candidates.begin(), candidates.end(),[target](int n){ return n>target;}),
        	candidates.end()
        );

        vector<vector<int>> res;
        int sum = 0;
        vector<int> item;
        combinationSumSub(candidates,target,0,res,item);
        return res;
    }
    void combinationSumSub(vector<int> &candidates, int target, 
    	int start, vector<vector<int>> &res, vector<int> &item)
    {
    	if(target<0)
    		return;
    	if(target==0){
    		res.push_back(item);
    		return;
    	} else {
    		for(int i=start; i<candidates.size(); i++){
    			if(i>0&&candidates[i]==candidates[i-1])
    				continue;
    			item.push_back(candidates[i]);
    			combinationSumSub(candidates,target-candidates[i],i,res,item);
    			item.pop_back();
    		}
    	}
    }

    int firstMissingPositive(int A[], int n) {
        int max_positive = 0;
        int min_positive = INT_MAX;
        int target = 0;
        for(int i=0; i<n; ){
            if(A[i]>0&&A[i]<n&&A[i]!=i&&A[A[i]]!=A[i]){
                swap(A[A[i]],A[i]);
            } else 
                i++;
        }
        for(int i=1; i<n; i++) {
            if(A[i]!=i)
                return i;
        }
        cout<<"A[0]="<<A[0]<<endl;
        if(n>0&&A[0]!=n)
            return n;
        else
            return n+1;
        
        
    }
};


int main(int argc, char** argv) {
	Solution sol;
	vector<int> s = {2,2,2};
	auto t = sol.combinationSum2(s,4);
	for(auto i: t){
		for(auto j: i){
			cout<<j<<" ";
		}
		cout<<endl;
	}

	int A[] = {2,1};
	cout<<sol.firstMissingPositive(A,2)<<endl;

	return 0;
}
