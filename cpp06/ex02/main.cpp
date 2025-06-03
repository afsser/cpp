#include "Base.hpp"
#include "../colors.hpp"
#include <iostream>

int main() {
	srand(time(NULL));

	Base *basePtr = generate();
	std::cout << std::endl;
	
	std::cout << YEL "Identifying using pointer:" RST << std::endl;
	identify(basePtr);
	std::cout << std::endl;

	std::cout << YEL "Identifying using reference:" RST << std::endl;
	identify(*basePtr);
	std::cout << std::endl;

	std::cout << YEL "Trying to identify a null pointer:" RST << std::endl;
	identify(NULL);

	delete basePtr;
	return 0;
}