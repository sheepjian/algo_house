/*
 * linkedList.h
 *
 *  Created on: Jun 19, 2014
 *      Author: jerry
 */

#ifndef LINKEDLIST_H_
#define LINKEDLIST_H_

#include <cstddef>
#include <vector>
using namespace std;

struct listNode {
	int val;
	listNode *next;
	listNode(int x) :
			val(x), next(NULL) {
	}
};

class linkedList{
public:
	linkedList(): size(0),head(NULL){}
	int getSize() {return size;}
	listNode *getHead() {return head;}
	void append(int x);
	listNode* search(int x);
	void clear();
	void printList();
	~linkedList(){clear();}
	listNode* getTail();
private:
	int size;
	listNode *head;
	void destroy(listNode* pos);
};

//front-end crossover insert
void reorderList(listNode *head);




//find the start of the single loop in the linked list
listNode *detectCycle(listNode *head);

#endif /* LINKEDLIST_H_ */
