/*
File Name : AddTwoNumbers.cpp
Author: Jerry DENG (jerrydeng.windfly@gmail.com)
Time: 2014-11-26 20:31:42

Question:

You are given two linked lists representing two non-negative numbers. 
The digits are stored in reverse order and each of their nodes contain a single digit. 
Add the two numbers and return it as a linked list.

Input: (2 -> 4 -> 3) + (5 -> 6 -> 4)
Output: 7 -> 0 -> 8


Tags: 


Answer:


*/

#include "Common/Leetcode.h"

class Solution {
public:
	ListNode *buildList(vector<int> s){
		ListNode* head;
		if(s.size()>0){
			auto it = s.begin();
			ListNode* p = new ListNode(*it);
			head = p;
			while((++it)!=s.end()){
				ListNode* t = new ListNode(*it);
				p->next = t;
				p = t;
			}
		}
		return head;
	}
    ListNode *addTwoNumbers(ListNode *l1, ListNode *l2) {
        int carry = 0;
        if(l1==NULL&&l2==NULL)
        	return NULL;
        vector<int> s;
        while(l1!=NULL&l2!=NULL) {
        	int sum = (l1->val+l2->val+carry);
        	if(sum>=10){
        		carry = 1;
        		sum %= 10;
        	} else
        		carry = 0;
        	s.push_back(sum);
        	l1 = l1->next;
        	l2 = l2->next;
        } 
        ListNode* l3 = l1==NULL?l2:l1;
        while(l3!=NULL) {
        	int sum = (l3->val+carry);
        	if(sum>=10){
        		carry = 1;
        		sum %= 10;
        	} else
        		carry = 0;
        	s.push_back(sum);
        	l3 = l3->next;
        }
        if(carry)
        	s.push_back(1);
        ListNode* head = buildList(s);
        return head;
    }
};


int main(int argc, char** argv) {
	Solution sol;
	ListNode* head1 = sol.buildList({2,4,3});
	ListNode* head2 = sol.buildList({5,6,4});
	ListNode* head = sol.addTwoNumbers(head1,head2);
	cout<<"the sum is ";
	while(head!=NULL){
		if(head->next!=NULL)
			cout<<head->val<<"->";
		else
			cout<<head->val<<endl;
		head = head->next;
	}

	return 0;
}
