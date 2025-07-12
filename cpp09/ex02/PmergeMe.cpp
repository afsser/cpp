#include "PmergeMe.hpp"
#include "colors.hpp"
#include <iostream>
#include <sys/time.h>

PmergeMe::PmergeMe(int size, char **argv) : _size(size), _args(argv) {}

PmergeMe::~PmergeMe() {}

std::vector<int>& PmergeMe::getVector() {
	return _vector;
}
std::list<int>& PmergeMe::getList() {
	return _list;
}

bool PmergeMe::parseInput() {
	for (int i = 0; i < _size; ++i) {
		for (int j = 0; _args[i][j] != '\0'; ++j) {
			if (!std::isdigit(_args[i][j])) {
				std::cerr << RED "Error: Invalid input. Only numbers are allowed." RST << std::endl;
				return false;
			}
		}
		long num = std::atol(_args[i]);
		std::cout << "Input: " << ORG << _args[i] << RST;
		if (num > 2147483647) {
			std::cerr << RED "Error: Numbers greater than maximum int (>2147483647) are not allowed." RST << std::endl;
			return false;
		}
		if (num < 0) {
			std::cerr << RED "Error: Negative numbers are not allowed." RST << std::endl;
			return false;
		}
		_vector.push_back(num);
		_list.push_back(num);
	}
	return true;
}

