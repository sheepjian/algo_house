/*
File Name : ReverseNodesInKGroup.cpp
Author: Jerry DENG (jerrydeng.windfly@gmail.com)
Time: 2014-12-03 16:56:06

Question:

Given a linked list, reverse the nodes of a linked list k at a time and return its modified list.

If the number of nodes is not a multiple of k then left-out nodes in the end should remain as it is.

You may not alter the values in the nodes, only nodes itself may be changed.

Only constant memory is allowed.

For example,
Given this linked list: 1->2->3->4->5

For k = 2, you should return: 2->1->4->3->5

For k = 3, you should return: 3->2->1->4->5


Tags: Linked List;


Answer:


*/

#include "Common/Leetcode.h"

class Solution {
public:
	void reverseSubList(ListNode* start, ListNode* end) {
		ListNode* prev = NULL;
		ListNode* cur = start;
		ListNode* tail;

		while(cur!=end){
			tail = cur->next;
			cur->next = prev;
			prev = cur;
			cur = tail;
		}
		cur->next = prev;
	}
	ListNode *reverseKGroup(ListNode *head, int k)  {
        if(k<=1||head==NULL||head->next==NULL)
            return head;
            
        ListNode* front = head;
        ListNode* tail = head;
        ListNode* lastGroupTail = NULL;
        while(tail!=NULL){
        	int count = 1;
        	while(tail!=NULL&&count!=k){
        		tail = tail->next;
        		count++;
        	}
        	if(tail==NULL)
        		break;
        	else {
        		ListNode* tail_next = tail->next;
        		cout<<front->val<<" * "<<tail->val<<endl;
        		reverseSubList(front,tail);
        		if(head==front){
        			head = tail;
        		} 
        		if(lastGroupTail!=NULL)
        			lastGroupTail->next = tail;
        		lastGroupTail = front;
        		front->next = tail_next;
        		front = tail_next;
        		tail = tail_next;
        	}
        }
        return head;
    }


};


int main(int argc, char** argv) {
	Solution sol;
	ListNode* head = new ListNode(1);
	ListNode* p1 = new ListNode(2);
	ListNode* p2 = new ListNode(3);
	ListNode* p3 = new ListNode(4);
	head->next = p1;
	p1->next = p2;
	p2->next = p3;


	ListNode* p = sol.reverseKGroup(head,2);
	while(p!=NULL) {
		cout<<p->val<<" ";
		p = p->next;
	}
	cout<<endl;

	return 0;
}
