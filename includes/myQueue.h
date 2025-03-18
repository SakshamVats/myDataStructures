#pragma once

#include <iostream>
#include <vector>
#include <assert.h>

class IntQueue
{
private:
	std::vector<int> m_queue{};

public:
	int size()
	{
		return static_cast<int>(m_queue.size());
	}

	void enqueue(int element)
	{
		m_queue.push_back(element);
	}

	int dequeue()
	{
		assert(size() != 0 && "Cannot dequeue from empty list!\n");

		int element = m_queue.front();
		m_queue.erase(m_queue.begin());
		return element;
	}

	int peek()
	{
		return m_queue.front();
	}

	void print()
	{
		std::cout << "-\n";
		for (int element : m_queue)
			std::cout << element << '\n';
		std::cout << "-\n";
	}
};

