#include "myArray.h"
#include "myStack.h"

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

int main()
{
	testStack();

	return 0;
}