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
	if (head == NULL)
		head = new listNode(x);
	else {
		insert(x, head);
	}
}

void linkedList::insert(int x, listNode* pos) {
	while (pos->next != NULL)
		pos = pos->next;

	cout<<"insert here "<<pos->val<<endl;

	pos->next = new listNode(x);
}

listNode* linkedList::search(int x) {
	listNode* pos = head;
	while (pos != NULL && pos->val != x)
		pos = pos->next;

	return pos;
}

void linkedList::printList() {
	listNode* pos = head;
	while (pos != NULL)
	{
		cout<<pos->val<<" "<<endl;
		pos = pos->next;
	}

	cout<<endl;
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
	cout<<"the list is clear now"<<endl;
}

void reorderList(listNode *head) {
	if (head == NULL || head->next == NULL)
		return;

	listNode* slowNode = head;
	listNode* fastNode = head->next;

	while(fastNode!=NULL)
	{
		fastNode = fastNode->next;
		if(fastNode!=NULL)
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
	while(pos!=NULL)
	{
		listNode* tmp = pos->next;
		pos->next = lastNode;
		lastNode = pos;
		pos = tmp;
	}
	anotherHead = lastNode;

	listNode* p = head;
	listNode* q = anotherHead;

	while(q!=NULL)
	{
		listNode* nextNode1 = p->next;
		listNode* nextNode2 = q->next;

		p->next = q;
		q->next = nextNode1;

		p = nextNode1;
		q = nextNode2;
	}
}

