#pragma once

#include <iostream>
#include <vector>
#include <assert.h>

class IntQueue
{
private:
	std::vector<int> m_queue{};

public:
	int size();
	void enqueue(int element);
	int dequeue();
	int peek();
	void print() const;
};

