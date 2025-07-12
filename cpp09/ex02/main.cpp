#include "PmergeMe.hpp"
#include "colors.hpp"
#include <iostream>

int main(int argc, char **argv) {
	if (argc < 2) {
		std::cerr << RED "Usage: " YEL << argv[0] << " <numbers...>" RST << std::endl;
		return (1);
	}
	PmergeMe pmerge(argc - 1, argv + 1);
	if (!pmerge.parseInput())
		return (1);

	std::cout << YEL "Before: " RST;
	pmerge.printContainer<std::vector<int> >(pmerge.getVector());
	double timeVector = pmerge.sortContainer<std::vector<int> >(pmerge.getVector(), "vector");
	std::cout << GRN "After:  " RST;
	pmerge.printContainer<std::vector<int> >(pmerge.getVector());
	
	double timeList = pmerge.sortContainer<std::list<int> >(pmerge.getList(), "list");

	pmerge.printTime<std::vector<int> >(pmerge.getVector(), timeVector, "vector");
	pmerge.printTime<std::list<int> >(pmerge.getList(), timeList, "list");

	return (0);
}