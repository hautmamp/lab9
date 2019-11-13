#pragma once

struct item {
	int p;
	int v;
};

class priorityHeap{
	public:
		priorityHeap(int size) {
			heap = new item[size];
		}
		~priorityHeap() {
			delete[] heap;
		}

		void insert(item i);
		void remove(int value);
		void printHeap();
	private:
		int numel;
		item *heap;
};

