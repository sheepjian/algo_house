/*
File Name : MergeTwoSortedLists.cpp
Author: Jerry DENG (jerrydeng.windfly@gmail.com)
Time: 2014-11-15 14:00:36

Question:
Merge two sorted linked lists and return it as a new list.
The new list should be made by splicing together the nodes of the first two lists.

Tags: Linked List


Answer:

For example if the first linked list a is 5->10->15 and the other linked list b is 2->3->20, 
then function should return a pointer to the head node of the merged list 2->3->5->10->15->20.

*/

#include "Common/Leetcode.h"

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */

class Solution {
public:
	ListNode *mergeTwoLists(ListNode *l1, ListNode *l2) {
		if(l1==NULL) {
			return l2;
		}
		if(l2==NULL) {
			return l1;
        }
        ListNode* head = NULL;
        if(l1->val<l2->val) {
        	head = new ListNode(l1->val);
        	l1 = l1->next;
        } else {
        	head = new ListNode(l2->val);
        	l2 = l2->next;
        }
        ListNode* current = head;
        while(l1!=NULL||l2!=NULL) {
        	if(l1==NULL) {
        		current->next = l2;
        		l2 = l2->next;
        	} else if (l2==NULL){
        		current->next = l1;
        		l1 = l1->next;
        	} else {
        		if(l1->val<l2->val) {
        			current->next = l1;
        			l1 = l1->next;
        		} else {
        			current->next = l2;
        			l2 = l2->next;
        		}
        	}
        	current = current->next;
        }
        return head;
    }
};


int main(int argc, char** argv) {
	Solution sol;
	char list1[] = "1 2 8 23 51 56 67";
	char list2[] = "3 4 5 9 34";
	ListNode* head1 = str2LinkedList(list1);
	ListNode* head2 = str2LinkedList(list2);
	ListNode* t= sol.mergeTwoLists(head1,head2);

	while(t!=NULL){
		cout<<t->val<<endl;
		t = t->next;
	}

	return 0;
}
