#pragma once

#include <vector>
#include <iostream>
#include <assert.h>

class IntArray
{
private:
	std::vector<int> m_array{};

public:
	int size();
	int getAt(int index);
	void insert(int element);
	int search(int element);
	void deleteAt(int index);
	void printAll();
};
