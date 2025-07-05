
#include "MutantStack.hpp"
#include <stdexcept>
#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#include "colors.hpp"

MutantStack::MutantStack(unsigned int n) : _size(n) {}

MutantStack::MutantStack(const MutantStack &other) : _vector(other._vector), _size(other._size) {}

MutantStack &MutantStack::operator=(const MutantStack &other) {
	if (this != &other) {
		_vector = other._vector;
		_size = other._size;
	}
	return *this;
}
MutantStack::~MutantStack() {}

int MutantStack::shortestSpan() {
	int					minSpan;
	int					span;
	std::vector<int>	sorted;

	if (_vector.size() < 2)
		throw std::logic_error("Not enough numbers to get shortest span");
	sorted = _vector;
	std::sort(sorted.begin(), sorted.end());
	minSpan = std::abs(sorted[1] - sorted[0]);
	for (size_t i = 1; i < sorted.size(); ++i)
	{
		span = std::abs(sorted[i] - sorted[i - 1]);
		if (span < minSpan)
			minSpan = span;
	}
	return (minSpan);
}
int MutantStack::longestSpan() {
	std::vector<int> sorted = _vector;

	if (_vector.size() < 2)
		throw std::logic_error("Not enough numbers to get longest span");
	std::sort(sorted.begin(), sorted.end());
	return (sorted.back() - sorted.front());
}

void MutantStack::addNumber(int n) {
	if (_vector.size() >= _size)
		throw std::out_of_range("MutantStack is FULL");
	_vector.push_back(n);
}

void MutantStack::addRange(std::vector<int>::iterator begin, std::vector<int>::iterator end) {
	if (std::distance(begin, end) + _vector.size() > _size)
		throw std::out_of_range("MutantStack is FULL");
	_vector.insert(_vector.end(), begin, end);
}

size_t MutantStack::getSize() const {
	return _vector.size();
}

int MutantStack::getElement(unsigned int index) const {
	if (index >= _vector.size())
		throw std::out_of_range("Index out of range");
	return _vector[index];
}

std::ostream &operator<<(std::ostream &os, const MutantStack &span)
{
	os << YEL "MutantStack vector: " RST;
	for (size_t i = 0; i < span.getSize(); i++) {
		os << BLU << span.getElement(i) << RST;
		if (i < span.getSize() - 1)
			os << YEL ", " RST;
	}
	return os;
}