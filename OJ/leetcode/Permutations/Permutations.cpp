/*
File Name : Permutations.cpp
Author: Jerry DENG (jerrydeng.windfly@gmail.com)
Time: 2014-11-20 11:07:03

Question:

Given a collection of numbers, return all possible permutations.

For example,
[1,2,3] have the following permutations:
[1,2,3], [1,3,2], [2,1,3], [2,3,1], [3,1,2], and [3,2,1].


Tags: Backtracking;


Answer:


*/

#include "Common/Leetcode.h"

class Solution {
public:
	bool nextPermutation(vector<int>& v) {
		if(v.size()<=1)
			return false;
		vector<int>::iterator it = v.end()-1;

		while(true) {
			auto j = it;
			it--;
			if(*it<*j) {
				auto k = v.end()-1;
				while(*k<=*it){
					k--;
				}
				iter_swap(k,it);
				reverse(j,v.end());
				return true;
			}
			if(it==v.begin())
				return false;
		}
	}

	vector<vector<int> > permuteUnique(vector<int> &num) {
    	vector<vector<int>> v;

		if(num.size()>0) {
			sort(num.begin(),num.end());
			v.push_back(num);
			while(nextPermutation(num)){
				v.push_back(num);
			}
		}
		return v;  
    }

	vector<vector<int> > permute(vector<int> &num) {
		vector<vector<int>> v;
		if(num.size()>0) {
			sort(num.begin(),num.end());
			v.push_back(num);
			while(nextPermutation(num)){
				v.push_back(num);
			}
		}
		return v;
        
    }

};


int main(int argc, char** argv) {
	Solution sol;
	std::vector<int> num;
	for(int i=1; i<argc; i++) {
		num.push_back(atoi(argv[i]));
	}
	vector<vector<int>> res;
	res = sol.permuteUnique(num);

	for(auto t: res){
		for(auto i: t){
			cout<<i<<" ";
		}
		cout<<endl;
	}

	return 0;
}
