#include "../includes/myStack.h"

int IntStack::size()
{
	return static_cast<int>(m_stack.size());
}

bool IntStack::isEmpty()
{
	return static_cast<bool>(!m_stack.size());
}

void IntStack::push(int element)
{
	m_stack.push_back(element);
}

int IntStack::pop()
{
	assert(!isEmpty() && "Cannot remove from empty stack!\n");

	int element = m_stack.back();
	m_stack.pop_back();
	return element;
}

void IntStack::print()
{
	std::cout << "-\n";
	for (int element : m_stack)
		std::cout << element << '\n';
	std::cout << "-\n";
}
