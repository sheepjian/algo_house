/*
File Name : CompareVersionNumbers.cpp
Author: Jerry DENG (jerrydeng.windfly@gmail.com)
Time: 2014-12-21 21:57:24

Question:


Tags: 


Answer:


*/

#include "Common/Leetcode.h"
#include "Common/Cppfun.h"

class Solution {
public:
	int compareVersion(string version1, string version2) {
        char delimiter[] = ".";
		vector<char*> v1 = cppFunction::split(version1,delimiter);
		vector<char*> v2 = cppFunction::split(version2,delimiter);
		
		if(v1.size()==0||v2.size()==0){
		    if(v1.size()!=0)
		        return 1;
		    if(v2.size()!=0)
		        return -1;
		    else
		        return 0;
		}
		int p = 0;
		while(true){
		    int i1 = atoi(v1[p]);
		    int i2 = atoi(v2[p]);
		    if(i1>i2)
		        return 1;
		    else if(i1<i2)
		        return -1;
		    else{
		        if(p<v1.size()-1&&p<v2.size()-1)
		            p++;
		        else if(p==(v1.size()-1)&&p==(v2.size()-1))
		            return 0;
		        else
		            break;
		    }
		}
		int q = ++p;
		if(v1.size()-1>=q){
		    while(q<v1.size()){
		        int i1 = atoi(v1[q]);
		        if(i1>0)
		            return 1;
		        q++;
		    }
		}
		if(v2.size()-1>=p){
		    while(p<v2.size()){
		        int i1 = atoi(v2[p]);
		        if(i1>0)
		            return -1;
		        p++;
		    }
		    
		}
		return 0;
    }
};


int main(int argc, char** argv) {
	Solution sol;
	cout<<atof(argv[1])<<endl;
	cout<<atof(argv[2])<<endl;
	int res =  sol.compareVersion(argv[1],argv[2]);
	if(res==1)
		cout<<"the first version is newer"<<endl;
	else if(res==-1)
		cout<<"the second version is newer"<<endl;
	else
		cout<<"they are the same version"<<endl;

	return 0;
}
