#include "../includes/myBinarySearchTree.h"

BinarySearchTree::Node* BinarySearchTree::getRootNode()
{
	return m_root;
}

void BinarySearchTree::addNode(int data)
{
	Node* newNode{ new Node{data} };

	if (!m_root)
	{
		m_root = newNode;
		return;
	}

	Node* curr{ m_root };

	while (true)
	{
		if (data < curr->m_data)
		{
			if (!curr->m_left)
			{
				curr->m_left = newNode;
				return;
			}

			curr = curr->m_left;
		}

		else
		{
			if (!curr->m_right)
			{
				curr->m_right = newNode;
				return;
			}

			curr = curr->m_right;
		}
	}
}

bool BinarySearchTree::search(int value)
{
	Node* curr{ m_root };

	while (curr)
	{
		if (value == curr->m_data)
			return true;

		curr = (value < curr->m_data) ? curr->m_left : curr->m_right;
	}

	return false;
}

BinarySearchTree::Node* BinarySearchTree::deleteValue(BinarySearchTree::Node* root, int value)
{
	if (!root)
		return nullptr;

	if (value < root->m_data)
		root->m_left = deleteValue(root->m_left, value);

	else if (value > root->m_data)
		root->m_right = deleteValue(root->m_right, value);

	else
	{
		if (!root->m_left)
		{
			BinarySearchTree::Node* temp = root->m_right;
			delete root;
			return temp;
		}

		else if (!root->m_right)
		{
			BinarySearchTree::Node* temp = root->m_left;
			delete root;
			return temp;
		}

		BinarySearchTree::Node* successor = getMinNode(root->m_right);
		root->m_data = successor->m_data;
		root->m_right = deleteValue(root->m_right, successor->m_data);
	}

	return root;
}

BinarySearchTree::Node* BinarySearchTree::getMinNode(BinarySearchTree::Node* root)
{
	while (root && root->m_left)
		root = root->m_left;

	return root;
}

void BinarySearchTree::printTreeInOrder(Node* root)
{
	if (!root)
		return;

	printTreeInOrder(root->m_left);

	std::cout << root->m_data << ' ';

	printTreeInOrder(root->m_right);
}
