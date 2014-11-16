/*
File Name : PermutationSequence.cpp
Author: Jerry DENG (jerrydeng.windfly@gmail.com)
Time: 2014-11-16 17:42:41

Question:

The set [1,2,3,…,n] contains a total of n! unique permutations.

By listing and labeling all of the permutations in order,
We get the following sequence (ie, for n = 3):

"123"
"132"
"213"
"231"
"312"
"321"
Given n and k, return the kth permutation sequence.

Note: Given n will be between 1 and 9 inclusive.


Tags: Backtracking; Math

Answer:


Note: All permutations start from ascending to descending

Goal: find the k-th combination 
Procedure: 
1. determine first digit (1...i...n)  i*(n-1)!<=k<=(i+1)*(n-1)!
2. determind second digit  k -= i*(n-1)! 
.
.
.
until k = 0



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
				while(*k<*it){
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



	string getPermutation(int n, int k) {
		string res = "";
		if(n<=0 || k<=0) return res;
		int* factorial = new int[n];
		std::vector<int> v;
		std::vector<int> s;
		int start = 1;
		for(int i=1; i<=n; i++) {
			v.push_back(i);
			if(i==1)
				factorial[i-1] = 1;
			else
				factorial[i-1] = factorial[i-2]*i;
		}
		if(k>factorial[n-1])
			return res;

		for(int i=n-2; i>=0&&k!=0; i--) {
			int id = (k-1)/factorial[i];
			s.push_back(v[id]);
			v.erase(v.begin()+id); 
			k -= factorial[i]*id;
		}
		for(auto i:v){
			s.push_back(i);
		}
		for(auto j: s) {
			res.push_back('0'+j);
		}
		return res;
    }
};


int main(int argc, char** argv) {
	Solution sol;
	cout<<sol.getPermutation(atoi(argv[1]),atoi(argv[2]))<<endl;

	return 0;
}
