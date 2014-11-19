/*
 * binaryHeap.cpp
 *
 *  Created on: Jul 21, 2014
 *      Author: jerry
 */

#include "binaryHeap.h"

template<class T>
binaryHeap<T>::binaryHeap(bool isMaxHeap, std::vector<T> vec) {
	pIsMaxHeap = isMaxHeap;
	pData = vec;
	makeHeap();
}

template<class T>
void binaryHeap<T>::makeHeap() {
	int n = pData.size();
	if (n > 0) {
		for (int i = n / 2; i >= 1; i--) {
			heapify(i);
		}
	}
}

template<class T>
void binaryHeap<T>::heapify(int id) {
	int l = 2 * id;
	int r = 2 * id + 1;
	int largest = id;
	if (pIsMaxHeap) {
		if (l <= pData.size() && pData[l - 1] > pData[id - 1])
			largest = l;
		if (r <= pData.size() && pData[r - 1] > pData[largest - 1])
			largest = r;
		if (largest != id) {
			std::swap(pData[id - 1], pData[largest - 1]);
			heapify(largest);
		}
	} else {
		if (l <= pData.size() && pData[l - 1] < pData[id - 1])
			largest = l;
		if (r <= pData.size() && pData[r - 1] < pData[largest - 1])
			largest = r;
		if (largest != id) {
			std::swap(pData[id - 1], pData[largest - 1]);
			heapify(largest);
		}
	}
}

template<class T>
T binaryHeap<T>::top() {
	if (!pData.empty())
		return pData.front();
	else
		return NULL;
}

template<class T>
bool binaryHeap<T>::empty() {
	return pData.empty();
}

template<class T>
int binaryHeap<T>::size() {
	return pData.size();
}

template<class T>
void binaryHeap<T>::pop() {
	if (!pData.empty()) {
		std::swap(pData.front(), pData.back());
		pData.pop_back();
		if (!pData.empty())
			bubbleDown(1);
	}
}

template<class T>
void binaryHeap<T>::insert(T v) {
	pData.push_back(v);
	bubbleUp(pData.size());
}

template<class T>
void binaryHeap<T>::bubbleUp(int id) {
	if (id < 1 || id > pData.size()) {
		printf("out of the heap\n");
		return;
	}

	if (pIsMaxHeap) {
		while (id > 1) {
			if (pData[id / 2] < pData[id]) {
				std::swap(pData[id - 1], pData[id / 2 - 1]);
				id = id / 2;
			}
		}
	} else {
		while (id > 1) {
			if (pData[id / 2] > pData[id]) {
				std::swap(pData[id - 1], pData[id / 2 - 1]);
				id = id / 2;
			}
		}
	}
}

template<class T>
void binaryHeap<T>::bubbleDown(int id) {
	if (id < 1 || id > pData.size()) {
		printf("out of the heap\n");
		return;
	}

	if (pIsMaxHeap) {
		while (id * 2 <= pData.size()) {
			int j = 2 * id;
			if (j < pData.size() && pData[j] > pData[j - 1])
				j++;
			if (pData[id - 1] > pData[j - 1])
				break;
			std::swap(pData[id - 1], pData[j - 1]);
			id = j;
		}
	} else {
		while (id * 2 <= pData.size()) {
			int j = 2 * id;
			if (j < pData.size() && pData[j] < pData[j - 1])
				j++;
			if (pData[id - 1] > pData[j - 1])
				break;
			std::swap(pData[id - 1], pData[j - 1]);
			id = j;
		}
	}
}

template<class T>
void binaryHeap<T>::printHeap() {
	if (!pData.empty()) {
		int n = pData.size();
		int i = 0;
		int stage = 1;
		int count = 0;
		while (count < n) {
			printf("%d\t", pData[count]);
			count++;
			i++;
			if (i == stage) {
				printf("\n");
				stage = stage + stage;
				i = 0;
			}
		}
	}
}

template class binaryHeap<int> ;
template class binaryHeap<float> ;
template class binaryHeap<double> ;
