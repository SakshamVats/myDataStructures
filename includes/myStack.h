#pragma once

#include <iostream>
#include <vector>
#include <assert.h>

class IntStack
{
private:
	std::vector<int> m_stack{};

public:
	int size();
	bool isEmpty();
	void push(int element);
	int pop();
	void print();
};
