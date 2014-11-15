/*
File Name : min.cpp
Author: Jerry DENG (jerrydeng.windfly@gmail.com)
Time: 2014-11-15 14:52:25

Question:

Design a stack that supports push, pop, top, and retrieving the minimum element in constant time.

push(x) -- Push element x onto stack.
pop() -- Removes the element on top of the stack.
top() -- Get the top element.
getMin() -- Retrieve the minimum element in the stack.

Tags: 


Answer:

Spcace -> Time

*/

#include "Common/Leetcode.h"

class MinStack {
public:
    void push(int x) {
    	ValStack.push(x);
    	if(x<=getMin())
    		min.push(x);
    }

    void pop() {
        if(ValStack.empty()) return;
    	if(ValStack.top()==min.top())
    		min.pop();
    	ValStack.pop();
    }

    int top() {
        if(!ValStack.empty())
        	return ValStack.top();
        else 
        	return numeric_limits<int>::min();;
    }

    int getMin() {
        if(!min.empty())
        	return min.top();
        else 
        	return numeric_limits<int>::max();;
    }
    stack<int> ValStack;
    stack<int> min;
};


int main(int argc, char** argv) {
	MinStack minStack;
	minStack.push(-2);
	minStack.push(0);
	minStack.push(-1);
	cout<<"the min is "<<minStack.getMin()<<endl;
	cout<<"top is "<<minStack.top()<<endl;
	minStack.pop();
	cout<<"the min is "<<minStack.getMin()<<endl;


	return 0;
}
