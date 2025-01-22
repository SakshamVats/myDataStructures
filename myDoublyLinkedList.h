#pragma once

#include <iostream>

struct IntDoubleNode
{
	int data{ 0 };
	IntDoubleNode* next{ nullptr };
	IntDoubleNode* prev{ nullptr };
};

class IntDoublyLinkedList
{
private:
	IntDoubleNode* m_head{};
	int m_size{ 0 };

public:
	~IntDoublyLinkedList() 
	{
		while (m_head) 
		{
			IntDoubleNode* temp = m_head;
			m_head = m_head->next;
			delete temp;
		}
	}

	int size()
	{
		return m_size;
	}

	void insertAtHead(int data)
	{
		IntDoubleNode* head{ new IntDoubleNode{data} };

		if (!m_head)
		{
			m_head = head;
			++m_size;
			return;
		}

		head->next = m_head;
		m_head->prev = head;
		m_head = head;

		++m_size;
	}

	void insertAtTail(int data)
	{
		IntDoubleNode* tail{ new IntDoubleNode{data} };

		if (!m_size)
		{
			m_head = tail;
			++m_size;
			return;
		}

		IntDoubleNode* curr{ m_head };

		for (int index{ 0 }; index < m_size - 1; ++index)
		{
			curr = curr->next;
		}

		curr->next = tail;
		tail->prev = curr;
		++m_size;
	}

	void deleteIndex(int delIndex)
	{
		if (delIndex < 0)
		{
			std::cout << "Delete index must be non-negative!\n";
			return;
		}

		else if (delIndex == 0)
		{
			m_head = m_head->next;
			if (m_head)
				m_head->prev = nullptr;
			--m_size;
			return;
		}

		else if (delIndex >= m_size)
		{
			std::cout << "Delete index is more than linked list size!\n";
			return;
		}

		IntDoubleNode* curr{ m_head };

		for (int index{ 0 }; index < delIndex - 1; ++index)
		{
			curr = curr->next;
		}

		curr->next = curr->next->next;
		if (curr->next)
			curr->next->prev = curr;

		--m_size;
	}

	int search(int element)
	{
		IntDoubleNode* curr = m_head;

		for (int index{ 0 }; index < m_size; ++index)
		{
			if (curr->data == element)
				return index;

			curr = curr->next;
		}

		return -1;
	}

	void print()
	{
		if (!m_size)
		{
			std::cout << "Linked List is empty!\n";
			return;
		}

		IntDoubleNode* curr{ m_head };

		for (int index{ 0 }; index < m_size; ++index)
		{
			std::cout << curr->data << "<->";
			curr = curr->next;
		}
		
		std::cout << "null\n";
	}
};