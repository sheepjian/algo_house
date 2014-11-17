/*
File Name : InsertInterval.cpp
Author: Jerry DENG (jerrydeng.windfly@gmail.com)
Time: 2014-11-17 12:55:39

Question:

Given a set of non-overlapping intervals, 
insert a new interval into the intervals (merge if necessary).

You may assume that the intervals were initially sorted according to their start times.

Example 1:
Given intervals [1,3],[6,9], insert and merge [2,5] in as [1,5],[6,9].

Example 2:
Given [1,2],[3,5],[6,7],[8,10],[12,16], insert and merge [4,9] in as [1,2],[3,10],[12,16].

This is because the new interval [4,9] overlaps with [3,5],[6,7],[8,10].

Tags: Array; Sort

Answer:


*/

#include "Common/Leetcode.h"

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
	vector<Interval> insert(vector<Interval> &intervals, Interval newInterval) {
        int newStart = newInterval.start;
        int newEnd = newInterval.end;
        vector<Interval> v;
        v.push_back(newInterval);
        if(intervals.size()==0)
        	return v;
        if(newStart<=newEnd){
        	int i_pos = 0;
        	for(auto it=intervals.begin(); it!=intervals.end(); it++){
        		if((*it).end<newStart){
        			v.insert(v.begin()+i_pos,*it);
        			i_pos++;
        		} else if ((*it).start>newEnd) {
        			v.insert(v.begin()+i_pos+1,it,intervals.end());
        			break;
        		} else {
        			v[i_pos] = combineInterval(v[i_pos],*it);
        			newEnd = v[i_pos].end;
        			newStart = v[i_pos].start;
        		}
        	}
        }
        return v;
    }
};


int main(int argc, char** argv) {
	Solution sol;
	Interval i1(1,3);
	Interval i2(6,9);
	Interval i3(2,5);
	vector<Interval> g{i1,i2};
	vector<Interval> h = sol.insert(g,i3);
	for(auto i:h){
		cout<<i.start<<","<<i.end<<endl;
	}


	return 0;
}
