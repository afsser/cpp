#include "iter.hpp"
#include <iostream>
#include <string>
#include "colors.hpp"

template <typename T>
void printElement(const T &element) {
	std::cout << ORG << element << GRN ", " RST;
}

template <typename T>
void increment(T &element) {
	element += 2;
}

template <typename T>
void printArray(T *array, size_t length) {
	std::cout << BLU "Array: " RST;
	for (size_t i = 0; i < length; ++i) {
		printElement(array[i]);
	}
	std::cout << std::endl;
}


int main() {
	int sequence[] = {1, 2, 3, 4, 5};
	size_t length = sizeof(sequence) / sizeof(sequence[0]);
	printArray(sequence, length);
	iter(sequence, length, increment<int>);
	std::cout << YEL "After incrementing each element by 2:" RST << std::endl;
	printArray(sequence, length);
	std::cout << std::endl;

	char str[] = {'a', 'b', 'c', 'd', 'e'};
	length = sizeof(str) / sizeof(str[0]);
	printArray(str, length);
	iter(str, length, increment<char>);
	std::cout << YEL "After incrementing each element by 2:" RST << std::endl;
	printArray(str, length);
	std::cout << std::endl;

	return 0;
}