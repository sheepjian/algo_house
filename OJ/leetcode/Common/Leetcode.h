#include <iostream>
#include <vector>
#include <stack>
#include <algorithm>
#include <string>
#include <cmath> 
#include <limits>
#include <assert.h> 
#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
using namespace std;


//Definition for singly-linked list.
struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};


// Transform string to LinkedList
ListNode* str2LinkedList(char* str, const char sep[]=" ") {
	char* pch = strtok(str,sep);
	ListNode* head = new ListNode(atoi(pch));
	ListNode* current = head;
	while(pch!=NULL) {
		pch = strtok(NULL, sep);
		if(pch!=NULL) {
			current->next = new ListNode(atoi(pch));
			current = current->next;
		}
	}
	return head;
}