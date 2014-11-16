/*
File Name : FindMinimumInRotatedSortedArray.cpp
Author: Jerry DENG (jerrydeng.windfly@gmail.com)
Time: 2014-11-15 19:06:37

Question:

Suppose a sorted array is rotated at some pivot unknown to you beforehand.

(i.e., 0 1 2 4 5 6 7 might become 4 5 6 7 0 1 2).

Find the minimum element.

The array may contain duplicates.

Tags: Array; Binary Search



Answer:


*/

#include "Common/Leetcode.h"

class Solution {
public:
	int findMin_clear(vector<int> &num) {
        int len = num.size();
        int L=0, R=len-1;
        while(L<R&&num[L]>=num[R]) {
            int mid = (L+R)/2;
            if(num[mid]>num[R])
                L = mid+1;
            else if(num[mid]<num[L])
                R = mid;
            else
                L = L+1;
        }
        return num[L];
    }

    int findMin(vector<int> &num) {
        int len = num.size();
        if(len==0)
            return -1;
        vector<int> newNum;
        int start = num[0];
        newNum.push_back(start);
        for(int i=1; i<len; i++) {
            if(num[i]!=start) {
                start = num[i];
                newNum.push_back(start);
            }
        }
        if(newNum.back() == newNum.front()&&newNum.size()!=1) newNum.pop_back();
        return findMin2(newNum);
    }

    int findMin2(vector<int> &num) {
        int len = num.size();
        if(len>0){
            int front = 0;
            int back = len-1;
            while(front!=back){
                int mid = (front+back)/2;
                if(num[mid]>num[back])
                {
                	if(mid==front)
                		return num[back];
                    front = mid;
                }
                else {
                	if(mid==front)
                		return num[front];
                    back = mid;
                }
            }
            return num[front];
        }
        return -1;
    }
};

int main(int argc, char** argv) {
	Solution sol;
	std::vector<int> v{4,4,3,3,1,1,2};
	cout<<"the min is "<<sol.findMin(v)<<endl;
	return 0;
}
