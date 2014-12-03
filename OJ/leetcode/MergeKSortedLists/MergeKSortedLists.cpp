/*
File Name : MergeKSortedLists.cpp
Author: Jerry DENG (jerrydeng.windfly@gmail.com)
Time: 2014-12-03 15:20:10

Question:

Merge k sorted linked lists and return it as one sorted list. Analyze and describe its complexity.

Tags: Divide and Conquer; Linked List; Heap


Answer:
Sorting algorithm test via linkedlist
You can use eigther mergesort or heapsort

*/

#include "Common/Leetcode.h"


struct cmp
{
    bool operator ()(const ListNode *a, const ListNode *b)
    {
            return a->val > b->val;
    }
};

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
        		break;
        	} else if (l2==NULL){
        		current->next = l1;
        		l1 = l1->next;
        		break;
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

    ListNode *mergeSubLists(vector<ListNode*> &lists, int start, int end){
    	if(start>end)
    		return NULL;
    	else if(start==end)
    		return lists[start];
    	else {
    		int mid = (start+end)/2;
    		ListNode* leftHead = mergeSubLists(lists,start,mid);
    		ListNode* rightHead = mergeSubLists(lists,mid+1,end);
    		ListNode* head =  mergeTwoLists(leftHead,rightHead);
    		return head;
    	}	
    }
	ListNode *mergeKLists(vector<ListNode *> &lists) {
		return mergeSubLists(lists,0, lists.size()-1);
    }

    ListNode *mergeKLists2(vector<ListNode *> &lists) {
        int n = lists.size();
        if(n == 0)return NULL;
        ListNode node(0), *res = &node;
        priority_queue<ListNode*, vector<ListNode*>, cmp> que;
        for(int i = 0; i < n; i++)
            if(lists[i])
                que.push(lists[i]);
        while(!que.empty())
        {
            ListNode * p = que.top();
            que.pop();
            res->next = p;
            res = p;
             
            if(p->next)
                que.push(p->next);
        }
        return node.next;
    }
};


int main(int argc, char** argv) {
	Solution sol;

	char list1[] = "1 2 8 23 51 56 67";
	char list2[] = "3 4 5 9 34";
	char list3[] = "4 5 6 7 8 10";
	ListNode* head1 = str2LinkedList(list1);
	ListNode* head2 = str2LinkedList(list2);
	ListNode* head3 = str2LinkedList(list3);
	vector<ListNode*> lists = {head1,head2,head3};
	ListNode* t= sol.mergeKLists(lists);

	while(t!=NULL){
		cout<<t->val<<endl;
		t = t->next;
	}

	return 0;
}
