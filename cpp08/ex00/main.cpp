#include "easyfind.hpp"
#include <iostream>
#include <string>
#include "colors.hpp"
#include <vector>
#include <list>


int main() {
	{
	std::cout << ORG << "=== Testing with integers ===" << RST << std::endl;
	try {
		std::vector<int>::const_iterator it;
		std::vector<int> vec = {23, 1, 2324, 53, 68, 3, 41, 75, 6};

		it = easyfind(vec, 3);
		std::cout << BLU "Found: " GRN << *it << RST << std::endl;
	} catch (const std::exception &e) {
		std::cerr << RED << e.what() << RST << std::endl;
	}
	}

	std::cout << ORG << "=== Testing with strings ===" << RST << std::endl;
	{
		try {
			std::list<std::string>::const_iterator it;
			std::list<std::string> lst = {"apple", "banana", "cherry"};
			
			it = easyfind(lst, std::string("banana"));
			std::cout << "Found: " << *it << std::endl;
		} catch (const std::exception &e) {
			std::cerr << RED << e.what() << RST << std::endl;
		}
	}
	return 0;
}