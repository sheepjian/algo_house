/*
File Name : MergeIntervals.cpp
Author: Jerry DENG (jerrydeng.windfly@gmail.com)
Time: 2014-11-17 14:55:34

Question:

Given a collection of intervals, merge all overlapping intervals.

For example,
Given [1,3],[2,6],[8,10],[15,18],
return [1,6],[8,10],[15,18].


Tags: Array; Sort


Answer:


*/

#include "Common/Leetcode.h"

bool intervalCompare(Interval i,Interval j) { return (i.start<j.start); }

class Solution {
public:
	Interval combineInterval(Interval i1, Interval i2) {
		Interval cbi;
		if(i1.end>=i2.start||i1.start<=i2.end) {
			cbi.start = min(i1.start,i2.start);
			cbi.end = max(i1.end,i2.end); 
		}
		return cbi;
	} 

	vector<Interval> merge(vector<Interval> &intervals) {
		int len = intervals.size();
		vector<Interval> v;
		if(len>0){
			sort(intervals.begin(),intervals.end(),intervalCompare);
			v.push_back(intervals[0]);
			int i_pos = 0;
			for(int i=1;i<len;i++) {
				if(v[i_pos].end>=intervals[i].start){
					v[i_pos] = combineInterval(v[i_pos],intervals[i]);
				} else {
					v.push_back(intervals[i]);
					i_pos++;
				}
			}
		}
		return v;
    }
};


int main(int argc, char** argv) {
	Solution sol;
	Interval i1(1,3);
    Interval i2(2,6);
    Interval i3(8,10);
    Interval i4(15,18);
    vector<Interval> g{i1,i2,i3,i4};
    vector<Interval> h = sol.merge(g);
	for(auto i:h){
		cout<<i.start<<","<<i.end<<endl;
	}

	return 0;
}
