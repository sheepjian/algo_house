/*
 * binaryHeap.h
 *
 *  Created on: Jul 6, 2014
 *      Author: jerry
 */

#ifndef BINARYHEAP_H_
#define BINARYHEAP_H_

#include <vector>
#include <cmath>
#include <string>
#include <algorithm>


template <class T>
class binaryHeap {
private:
	std::vector<T> pData;
	void SiftUp(unsigned long id);
	void SiftDown(unsigned long id);
	bool pIsMaxHeap;
	void makeHeap();
	void heapify(int);

	void bubbleUp(int);
	void bubbleDown(int);

public:
	//
	binaryHeap(bool isMaxHeap):pIsMaxHeap(isMaxHeap){}
	binaryHeap(bool,std::vector<T>);
	~binaryHeap(){}

	void insert(T v);
	void pop();
	bool empty();
	T top();
	int size();

	void printHeap();

	void clear();
};



#endif /* BINARYHEAP_H_ */
