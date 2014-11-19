/*
 * linkedList.cpp
 *
 *  Created on: Jun 19, 2014
 *      Author: jerry
 */

#include "linkedList.h"
#include <iostream>
using namespace std;

void linkedList::append(int x) {
	if (head == NULL) {
		head = new listNode(x);
		return;
	}

	listNode* p = head;
	while (p->next != NULL) {
		p = p->next;
	}
	p->next = new listNode(x);
}

listNode* linkedList::getTail() {
	listNode* p = head;
	while (p->next != NULL) {
		p = p->next;
	}
	return p;

}

listNode* linkedList::search(int x) {
	int index = 0;
	listNode* p = head;
	while (p->val != x && p != NULL) {
		p = p->next;
		index++;
	}
	cout << "find the node in index: " << index << endl;
	return p;
}

void linkedList::printList() {
	listNode* pos = head;
	while (pos != NULL) {
		cout << pos->val << " ";
		pos = pos->next;
	}

	cout << endl;
}

void linkedList::destroy(listNode* pos) {
	if (pos->next != NULL)
		destroy(pos->next);

	delete pos;
}

void linkedList::clear() {
	if (head == NULL)
		return;
	destroy(head);
	cout << "the list is clear now" << endl;
}

void reorderList(listNode *head) {
	if (head == NULL || head->next == NULL)
		return;

	listNode* slowNode = head;
	listNode* fastNode = head->next;

	while (fastNode != NULL) {
		fastNode = fastNode->next;
		if (fastNode != NULL)
			fastNode = fastNode->next;
		else
			break;

		slowNode = slowNode->next;
	}

	listNode* anotherHead = slowNode->next;
	slowNode->next = NULL;

	listNode* pos = anotherHead->next;
	listNode* lastNode = anotherHead;
	anotherHead->next = NULL;
	while (pos != NULL) {
		listNode* tmp = pos->next;
		pos->next = lastNode;
		lastNode = pos;
		pos = tmp;
	}
	anotherHead = lastNode;

	listNode* p = head;
	listNode* q = anotherHead;

	while (q != NULL) {
		listNode* nextNode1 = p->next;
		listNode* nextNode2 = q->next;

		p->next = q;
		q->next = nextNode1;

		p = nextNode1;
		q = nextNode2;
	}
}

int node_distance(listNode* begin, listNode* end) {
	int count = 0;
	listNode* p = begin;
	while (p != end) {
		count++;
		p = p->next;
	}
	return count;
}

listNode *detectCycle(listNode *head) {
	if (head == NULL || head->next == NULL)
		return NULL;

	listNode* slow = head;
	listNode* fast = head->next;

	while (fast != NULL) {
		fast = fast->next;
		if (fast != NULL) {
			if (fast == slow)
				break;
			else {
				slow = slow->next;
				fast = fast->next;
			}
		}
	}

	if (fast == NULL)
		return NULL;

	listNode *pos = fast;

	int lastCount = 0;
	int curCount = 0;

	while (pos != NULL) {
		curCount = node_distance(head, pos);
		if (curCount <= lastCount) {
			break;
		} else {
			lastCount = curCount;
			pos = pos->next;
		}
	}

	return pos;
}

