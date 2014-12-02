/*
File Name : IntersectionOfTwoLinkedLists.cpp
Author: Jerry DENG (jerrydeng.windfly@gmail.com)
Time: 2014-11-29 12:24:47

Question:

Write a program to find the node at which the intersection of two singly linked lists begins.


For example, the following two linked lists:

A:          a1 → a2
                   ↘
                     c1 → c2 → c3
                   ↗            
B:     b1 → b2 → b3
begin to intersect at node c1.


Notes:

If the two linked lists have no intersection at all, return null.
The linked lists must retain their original structure after the function returns.
You may assume there are no cycles anywhere in the entire linked structure.
Your code should preferably run in O(n) time and use only O(1) memory.


Tags: Linked List;


Answer:

two pointers start to travel from the head of each list until they meet.
The faster one means it is walking on the shorter list. 
So the faster one switches to the longer list when it meets the tail.
The same is for the slower one.



*/

#include "Common/Leetcode.h"

class Solution {
public:
	void appendList(ListNode* a, ListNode* c){
		ListNode* p = a;
		while(p->next!=NULL)
			p = p->next;
		p->next = c;
	}
	ListNode* buildList(vector<int> v){
		ListNode* head;
		if(v.size()>0){
			head = new ListNode(v[0]);
			ListNode* p = head;
			for(int i=1; i<v.size(); i++) {
				p->next = new ListNode(v[i]);
				p = p->next;
			}
		}
		return head;
	}

	ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
		if(headA==NULL||headB==NULL)
    		return NULL;
		ListNode* pA = headA;
		ListNode* pB = headB;
		while(pA!=pB) {
			// the end of the list must be the same if intersect
			if(pA->next==NULL&&pB->next==NULL){
				if(pA!=pB)
					return NULL;
			}
			if(pA->next==NULL){
				pA = headB;
				pB = pB->next;
				continue;
			}
			if(pB->next==NULL){
				pB = headA;
				pA = pA->next;
				continue;
			}
			pB = pB->next;
			pA = pA->next;
		}
		return pA;

	}

};


int main(int argc, char** argv) {
	Solution sol;
	ListNode* headA = sol.buildList({1,2,3});
	ListNode* headB = sol.buildList({5,6,7,8});
	ListNode* headC = sol.buildList({9,10,11});
	sol.appendList(headB,headA);
	//sol.appendList(headB,headC);
	cout<<"the intersection point is "<<sol.getIntersectionNode(headA,headB)->val<<endl;

	return 0;
}
