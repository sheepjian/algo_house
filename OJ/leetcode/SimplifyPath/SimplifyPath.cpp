/*
Question:

Given an absolute path for a file (Unix-style), simplify it.

For example,
path = "/home/", => "/home"
path = "/a/./b/../../c/", => "/c"
click to show corner cases.

Corner Cases:
Did you consider the case where path = "/../"?
In this case, you should return "/".
Another corner case is the path might contain multiple slashes '/' together, such as "/home//foo/".
In this case, you should ignore redundant slashes and return "/home/foo".


*/

#include "Common/Leetcode.h"


class Solution {
public:
    string simplifyPath(string path) {
    	vector<string>  history;
    	assert(path[0]=='/');
    	int i = 0;   
    	while(i!=path.size()) {
    		while(i<path.size() && path[i]=='/')
    			i++;
    		if(i==path.size())
    			break;
    		int start = i;
    		while(i<path.size() && path[i]!='/') 
    			i++;
    		int end = i-1;
    		auto p = path.substr(start,end-start+1);
    		if(p=="..") {
    			if(!history.empty())
    				history.pop_back();
    		} else {
    			if(p!=".")
    				history.push_back(p);
    		}
    	}
    	if(history.size()==0) return "/";

    	string res = "";
    	for(auto p: history) {
    		res += ("/"+p);
		}
        return res;
    }
};

int main(int argc, char** argv){
	Solution Sol;
	string s(argv[1]);
	cout<<Sol.simplifyPath(s)<<endl;
}


