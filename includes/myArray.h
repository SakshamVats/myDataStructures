#pragma once

#include <vector>
#include <iostream>
#include <assert.h>

class IntArray
{
private:
	std::vector<int> m_array{};

public:
	int size()
	{
		return static_cast<int>(m_array.size());
	}

	int getAt(int index)
	{
		assert(index < size() && index >= 0 && "Enter a valid index");
		return m_array[index];
	}

	void insert(int element)
	{
		m_array.push_back(element);
	}

	int search(int element)
	{
		for (int index{0}; index < size(); ++index)
		{
			if (getAt(index) == element)
				return index;
		}

		return -1;
	}

	void deleteAt(int index)
	{
		assert(index < size() && index >= 0 && "Enter a valid index");
		m_array.erase(m_array.begin() + index);
	}

	void printAll()
	{
		std::cout << '[';
		for (int element : m_array)
			std::cout << element << ' ';
		std::cout << "]\n";
	}
};
