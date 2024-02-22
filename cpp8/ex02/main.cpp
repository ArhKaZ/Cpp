#include "incs/MutantStack.hpp"

int main()
{
	MutantStack<int> msstack;

	msstack.push(42);
	msstack.push(43);
	msstack.push(44);
	std::cout << msstack.top() << std::endl;
	std::cout << msstack.top() << std::endl;
	std::cout << msstack.top() << std::endl;
	std::cout << msstack.top() << std::endl;
	(void)msstack;
}