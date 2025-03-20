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
	~IntDoublyLinkedList();
	int size();
	void insertAtHead(int data);
	void insertAtTail(int data);
	void deleteIndex(int delIndex);
	int search(int element);
	void print();
};