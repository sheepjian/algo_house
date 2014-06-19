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
	linkedList(): head(0),size(0){}
	int getSize() {return size;}
	listNode *getHead() {return head;}
	void append(int x);
	listNode* search(int x);
	void clear();
	void printList();
	~linkedList(){clear();}
private:
	int size;
	listNode *head;
	void insert(int x, listNode* pos);
	void destroy(listNode* pos);
};

void reorderList(listNode *head);

#endif /* LINKEDLIST_H_ */
