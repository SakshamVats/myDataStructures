#pragma once

#include <iostream>

class BinarySearchTree
{
private:
	struct Node
	{
		int m_data{ 0 };
		Node* m_left{ nullptr };
		Node* m_right{ nullptr };
	};

	Node* m_root{ nullptr };
	Node* getMinNode(Node* root);


public:
	Node* getRootNode();
	void addNode(int data);
	bool search(int value);
	void printTreeInOrder(Node* root);
	Node* deleteValue(Node* root, int value);
	void remove(int value) { m_root = deleteValue(m_root, value); }
};