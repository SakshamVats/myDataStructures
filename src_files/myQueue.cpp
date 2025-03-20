#include "../includes/myQueue.h"

int IntQueue::size()
{
	return static_cast<int>(m_queue.size());
}

void IntQueue::enqueue(int element)
{
	m_queue.push_back(element);
}

int IntQueue::dequeue()
{
	assert(size() != 0 && "Cannot dequeue from empty list!\n");

	int element = m_queue.front();
	m_queue.erase(m_queue.begin());
	return element;
}

int IntQueue::peek()
{
	return m_queue.front();
}

void IntQueue::print() const
{
	std::cout << "-\n";
	for (int element : m_queue)
		std::cout << element << '\n';
	std::cout << "-\n";
}
