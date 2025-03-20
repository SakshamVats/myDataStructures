#include "../includes/myArray.h"

int IntArray::size()
{
	return static_cast<int>(m_array.size());
}

int IntArray::getAt(int index)
{
	assert(index < size() && index >= 0 && "Enter a valid index");
	return m_array[index];
}

void IntArray::insert(int element)
{
	m_array.push_back(element);
}

int IntArray::search(int element)
{
	for (int index{ 0 }; index < size(); ++index)
	{
		if (getAt(index) == element)
			return index;
	}

	return -1;
}

void IntArray::deleteAt(int index)
{
	assert(index < size() && index >= 0 && "Enter a valid index");
	m_array.erase(m_array.begin() + index);
}

void IntArray::printAll()
{
	std::cout << '[';
	for (int element : m_array)
	std::cout << element << ' ';
	std::cout << "]\n";
}