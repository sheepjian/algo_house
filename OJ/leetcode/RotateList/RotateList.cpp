/*
File Name : RotateList.cpp
Author: Jerry DENG (jerrydeng.windfly@gmail.com)
Time: 2014-11-16 15:45:22

Question:

Given a list, rotate the list to the right by k places, where k is non-negative.
For example:
Given 1->2->3->4->5->NULL and k = 2,
return 4->5->1->2->3->NULL.

Tags: Linked List; Two Pointers

Answer:
The distance between the new head node and old head node is (1) when k%len ==0, 0  (2) otherwise, len - k%len

*/

#include "Common/Leetcode.h"

class Solution {
public:
	ListNode *rotateRight(ListNode *head, int k) {
		if(head) {
        	ListNode* p = head;
        	int len = 1;
        	while(p->next!=NULL) {
        		len++;
        		p = p->next;
        	}
        	p->next = head;
        	ListNode* tail = p;
        	p = head;
        	int p_shift = len - k%len;
        	while(p_shift!=len&&p_shift>0) {
        		p = p->next;
        		tail = tail->next;
        		p_shift--;
        	}
        	head = p;
        	tail->next = NULL;
        	
		}
		return head;
    }
};


int main(int argc, char** argv) {
	Solution sol;
	ListNode* head  = new ListNode(1);
    ListNode* node1 = new ListNode(2);
    ListNode* node2 = new ListNode(3);
    ListNode* node3 = new ListNode(4);
    ListNode* node4 = new ListNode(5);
 
    head->next = node1;
    node1->next = node2;
    node2->next = node3;
    node3->next = node4;

	ListNode* node = sol.rotateRight(head,13);
	if(node) {
		cout<<node->val<<endl;
	} else {
		cout<<"it is null"<<endl;
	} 
	return 0;
}
