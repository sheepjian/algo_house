/*
File Name : LargestNumber.cpp
Author: Jerry DENG (jerrydeng.windfly@gmail.com)
Time: 2015-01-13 21:15:09

Question:

Given a list of non negative integers, arrange them such that they form the largest number.

For example, given [3, 30, 34, 5, 9], the largest formed number is 9534330.

Note: The result may be very large, so you need to return a string instead of an integer.


Tags: 


Answer:


*/

#include "Common/Leetcode.h"

class Solution {
public:
    string largestNumber(vector<int> &num) {
        string res;

        quickSort(num,0,num.size()-1);

        bool flag = false;
        for(auto i: num){
        	res.append(to_string(i));
        	if(!flag&&i==0)
        		break;
        	else
        		flag = true;
        }

        return res;
    }

    bool compare(int i, int j){
    	if(i==0)
    		return false;
    	if(j==0)
    		return true;

    	if(combine(i,j)>combine(j,i))
    		return true;
    	else
    		return false;

	}

	int combine(int i, int j){
		int j_prev = j;
		while(j>0){
			i *= 10;
			j /= 10;
		}
		return i+j_prev;
	}

    void quickSort(vector<int> &v, int start, int end){
    	if(start>=end)
    		return;
    	srand (time(NULL));

    	int pivot = rand()%(end-start+1)+start;

    	iter_swap(v.begin()+start,v.begin()+pivot);

    	int i=start+1;
    	int j=i;
    	for(;i<=end&&j<=end;){
    		if(compare(v[start],v[j]))
    		{
    			j++;
    		} else{
    			iter_swap(v.begin()+i,v.begin()+j);
    			i++;
    			j++;
    		}
    	}

    	iter_swap(v.begin()+start,v.begin()+i-1);

    	quickSort(v,start,i-2);
    	quickSort(v,i,end);
    }
};


int main(int argc, char** argv) {
	Solution sol;

	
	std::vector<int> v= {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0};
	vector<int> w = {20,1};
	cout<<"the largestNumber is "<<sol.largestNumber(w)<<endl;

	return 0;
}
