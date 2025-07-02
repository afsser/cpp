#include "easyfind.hpp"
#include <iostream>
#include <string>
#include "colors.hpp"
#include <vector>
#include <list>


int main() {
	{
	std::cout << ORG << "=== Testing with Vector ===" << RST << std::endl;
	try {
		std::vector<int>::const_iterator it;
		std::vector<int> vec;

		for (int i = 12; i < 20; ++i) {
			vec.push_back(i);
			std::cout << i << " ";
		}
		std::cout << std::endl;
		std::cout << std::endl;

		std::cout << YEL "Searching for 15 in the vector..." RST << std::endl;
		it = easyfind(vec, 15);
		std::cout << BLU "Found: " GRN << *it << RST << std::endl;

		std::cout << YEL "Searching for 3 in the vector..." RST << std::endl;
		it = easyfind(vec, 3);
	} catch (const std::exception &e) {
		std::cerr << RED << e.what() << RST << std::endl;
	}
	}
	std::cout << std::endl;
	std::cout << ORG << "=== Testing with List ===" << RST << std::endl;
	{
		try {
			std::list<int>::const_iterator it;
			std::list<int> lst;

			for (int i = 2; i < 11; ++i) {
				lst.push_back(i);
				std::cout << i << " ";
			}
			std::cout << std::endl;
			std::cout << std::endl;

			std::cout << YEL "Searching for 3 in the list..." RST << std::endl;
			it = easyfind(lst, 3);
			std::cout << BLU "Found: " GRN << *it << RST << std::endl;

			std::cout << YEL "Searching for 15 in the list..." RST << std::endl;
			it = easyfind(lst, 15);
		} catch (const std::exception &e) {
			std::cerr << RED << e.what() << RST << std::endl;
		}
	}
	return 0;
}