#ifndef PMERGEME_HPP
# define PMERGEME_HPP

#include <iostream>
#include <vector>
#include <list>
#include <algorithm>
#include <string>

class PmergeMe {
private:
	std::vector<int>	_vector;
	std::list<int>		_list;
	int					_size;
	char 				**_args;
	PmergeMe(const PmergeMe &other);
	PmergeMe &operator=(const PmergeMe &other);
public:
	PmergeMe(int argc, char **argv);
	~PmergeMe();

	bool	parseInput();

	template <typename T>
	void fordJohnsonSort(T &container, std::string type);

	template <typename T>
	double	sortContainer(T &container, std::string type);

	template <typename T>
	void	printContainer(const T &container) const;

	template <typename T>
	void	printTime(const T &container, double time, const std::string &type) const;

	std::vector<int>& getVector();

	std::list<int>& getList();
};

#include "PmergeMe.tpp"

#endif