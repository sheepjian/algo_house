/*
File Name : MaxPointsOnALine.cpp
Author: Jerry DENG (jerrydeng.windfly@gmail.com)
Time: 2014-12-08 00:38:42

Question:

Given n points on a 2D plane, find the maximum number of points that lie on the same straight line.


Tags: Hash Table; Math

Answer:


*/

#include "Common/Leetcode.h"

/**
 * Definition for a point.
 * struct Point {
 *     int x;
 *     int y;
 *     Point() : x(0), y(0) {}
 *     Point(int a, int b) : x(a), y(b) {}
 * };
 */

 struct Point
 {
 	int x;
 	int y;
 };
class Solution {
public:
    int maxPoints(vector<Point> &points) {
		unordered_map<float,int> mp;
		int maxNum = 0;
		for(int i = 0; i < points.size(); i++)
		{
			mp.clear();
			mp[INT_MIN] = 0;
			int duplicate = 1;
			for(int j = 0; j < points.size(); j++)
			{
				if(j == i) continue;
				if(points[i].x == points[j].x && points[i].y == points[j].y)
				{
					duplicate++;
					continue;
				}
				float k = points[i].x == points[j].x ? INT_MAX : (float)(points[j].y - points[i].y)/(points[j].x - points[i].x);
				mp[k]++;
			}
			unordered_map<float, int>::iterator it = mp.begin();
			for(; it != mp.end(); it++)
				if(it->second + duplicate > maxNum)
					maxNum = it->second + duplicate;
		}
		return maxNum;
    }
};


int main(int argc, char** argv) {
	Solution sol;

	return 0;
}
