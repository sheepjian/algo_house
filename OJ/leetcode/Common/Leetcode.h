#include <iostream>
#include <vector>
#include <stack>
#include <map>
#include <unordered_map>
#include <unordered_set>
#include <algorithm>
#include <string>
#include <cmath> 
#include <limits>
#include <assert.h> 
#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <utility>
using namespace std;


//Definition for singly-linked list.
struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};


//Definition for an interval.
struct Interval {
	int start;
    int end;
    Interval() : start(0), end(0) {}
    Interval(int s, int e) : start(s), end(e) {}
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
