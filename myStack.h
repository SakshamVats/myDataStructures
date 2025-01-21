#pragma once

#include <iostream>
#include <vector>
#include <assert.h>

class IntStack
{
private:
	std::vector<int> m_stack{};

public:
	int size()
	{
		return static_cast<int>(m_stack.size());
	}

	bool isEmpty()
	{
		return static_cast<bool>(!m_stack.size());
	}

	void push(int element)
	{
		m_stack.push_back(element);
	}

	int pop()
	{
		assert(!isEmpty() && "Cannot remove from empty stack!");

		int element = m_stack.back();
		m_stack.pop_back();
		return element;
	}

	void print()
	{
		std::cout << "-\n";
		for (int element : m_stack)
			std::cout << element << '\n';
		std::cout << "-\n";
	}
};
