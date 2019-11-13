#pragma once

struct item {
	int p;
	int v;
};

class priorityQueue{
public:
	priorityQueue() {
		queue = new item[100];
		numel = 0;
	}
	priorityQueue(int size) {
		queue = new item[size];
		numel = 0;
	}
	~priorityQueue();
	void insert(item newitem);
	bool remove(int value);
	void PrintQueue();

protected:
	bool shift(int index, bool down);
	item* queue;
	int numel;
};

