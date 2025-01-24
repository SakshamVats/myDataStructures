#include "myArray.h"
#include "myStack.h"
#include "myQueue.h"
#include "myLinkedList.h"
#include "myDoublyLinkedList.h"
#include "myBinarySearchTree.h"

void testArray();
void testStack();
void testQueue();
void testLinkedList();
void testDoublyLinkedList();
void testBinarySearchTree();

int main()
{
	testBinarySearchTree();

	return 0;
}

void testArray()
{
	IntArray sakshamsArray{};

	sakshamsArray.insert(15);
	sakshamsArray.insert(11);
	sakshamsArray.insert(2003);
	sakshamsArray.insert(2050);

	sakshamsArray.printAll();

	std::cout << "The size of the array is: " << sakshamsArray.size() << '\n';

	std::cout << "First element: " << sakshamsArray.getAt(0) << "\nSecond Element: " << sakshamsArray.getAt(1) << '\n';

	std::cout << "Element '2003' is at index: " << sakshamsArray.search(2003) << '\n';

	std::cout << "The size of the array is: " << sakshamsArray.size() << '\n';

	sakshamsArray.deleteAt(sakshamsArray.search(2050));

	std::cout << "The size of the array is: " << sakshamsArray.size() << '\n';

	sakshamsArray.printAll();
}

void testStack()
{
	IntStack sakshamsStack{};

	sakshamsStack.push(15);
	sakshamsStack.push(11);
	sakshamsStack.push(2003);
	sakshamsStack.push(2050);

	sakshamsStack.print();

	std::cout << "The size of the stack is: " << sakshamsStack.size() << '\n';

	std::cout << "Popping element: " << sakshamsStack.pop() << '\n';

	std::cout << "The size of the stack is: " << sakshamsStack.size() << '\n';

	sakshamsStack.print();
}

void testQueue()
{
	IntQueue sakshamsQueue{};

	sakshamsQueue.enqueue(2050);
	sakshamsQueue.enqueue(2003);
	sakshamsQueue.enqueue(11);
	sakshamsQueue.enqueue(15);

	sakshamsQueue.print();

	std::cout << "The size of the queue is: " << sakshamsQueue.size() << '\n';

	std::cout << "Dequeuing element: " << sakshamsQueue.dequeue() << '\n';

	std::cout << "The size of the queue is: " << sakshamsQueue.size() << '\n';

	sakshamsQueue.print();
}

void testLinkedList()
{
	IntLinkedList sakshamsLL{};

	sakshamsLL.print();

	sakshamsLL.insertAtHead(2003);
	sakshamsLL.insertAtHead(11);
	sakshamsLL.insertAtHead(15);

	std::cout << "The size of the linked list is: " << sakshamsLL.size() << '\n';
	sakshamsLL.print();

	sakshamsLL.insertAtTail(2050);

	std::cout << "The size of the linked list is: " << sakshamsLL.size() << '\n';
	sakshamsLL.print();

	std::cout << "Searching for 15: Found at index " << sakshamsLL.search(15) << '\n';

	sakshamsLL.deleteIndex(sakshamsLL.search(15));
	std::cout << "The size of the linked list is: " << sakshamsLL.size() << '\n';
	sakshamsLL.print();
}

void testDoublyLinkedList()
{
	IntDoublyLinkedList sakshamsDLL{};

	sakshamsDLL.print();

	sakshamsDLL.insertAtHead(2003);
	sakshamsDLL.insertAtHead(11);
	sakshamsDLL.insertAtHead(15);

	std::cout << "The size of the linked list is: " << sakshamsDLL.size() << '\n';
	sakshamsDLL.print();

	sakshamsDLL.insertAtTail(2050);

	std::cout << "The size of the linked list is: " << sakshamsDLL.size() << '\n';
	sakshamsDLL.print();

	std::cout << "Searching for 15: Found at index " << sakshamsDLL.search(15) << '\n';

	sakshamsDLL.deleteIndex(sakshamsDLL.search(15));
	std::cout << "The size of the linked list is: " << sakshamsDLL.size() << '\n';
	sakshamsDLL.print();
}

void testBinarySearchTree()
{
	BinarySearchTree sakshamsBST{};

	sakshamsBST.addNode(15);
	sakshamsBST.addNode(11);
	sakshamsBST.addNode(2003);
	sakshamsBST.addNode(2050);

	sakshamsBST.printTreeInOrder(sakshamsBST.getRootNode());
	std::cout << '\n';

	sakshamsBST.deleteValue(sakshamsBST.getRootNode(), 2050);

	sakshamsBST.printTreeInOrder(sakshamsBST.getRootNode());
	std::cout << '\n';

	std::cout << sakshamsBST.search(15);
}