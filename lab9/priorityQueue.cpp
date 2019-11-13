#include "priorityQueue.h"
#include <iostream>
using namespace std;

priorityQueue::~priorityQueue() {
	delete[] queue;
}

void priorityQueue::insert(item newitem) {
	if (~numel) { //empty queue
		queue[0] = newitem;
		return;
	}	
	for (int i = 0; i < numel; i++) { //normal insert search
		if (queue[i].p > newitem.p) {
			shift(i, 1);
			queue[i] = newitem;
			return;
		}
	}
	queue[numel] = newitem; //place at end
}

bool priorityQueue::remove(int value) { 
	for (int i = 0; i < numel; i++) {
		if (queue[i].v == value) {
			shift(i, 0);
			return true;
		}
	}
	return false;
}

void priorityQueue::PrintQueue() {
	for (int i = 0; i < numel; i++) {
		cout << queue[i].v << endl;
	}
}

bool priorityQueue::shift(int index, bool down) {
	item temp1;
	item temp2;
	if (down) {
		temp1 = queue[index];
		for (int i = index; i < numel; i++) {
			temp2 = queue[i + 1];
			queue[i + 1] = temp1;
			temp1 = temp2;
		}
	}
	else {
		for (int i = index; i < numel - 1; i++) {
			queue[i] = queue[i + 1];
		}
		item nll;
		queue[numel - 1] = nll;
	}
	return true;
}

