
#include "Span.hpp"
#include <stdexcept>
#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#include "colors.hpp"

Span::Span(unsigned int n) : _size(n) {}

Span::Span(const Span &other) : _vector(other._vector), _size(other._size) {}

Span &Span::operator=(const Span &other) {
	if (this != &other) {
		_vector = other._vector;
		_size = other._size;
	}
	return *this;
}
Span::~Span() {}

int Span::shortestSpan() {
	int					minSpan;
	int					span;
	size_t				minIndex = 0;
	std::vector<int>	sorted;
	std::vector<int>::iterator it_a;
	std::vector<int>::iterator it_b;

	if (_vector.size() < 2)
		throw std::logic_error("Not enough numbers to get shortest span");
	sorted = _vector;
	std::sort(sorted.begin(), sorted.end());
	minSpan = std::abs(sorted[1] - sorted[0]);
	for (size_t i = 1; i < sorted.size(); ++i)
	{
		span = std::abs(sorted[i] - sorted[i - 1]);
		if (span < minSpan)
		{
			minSpan = span;
			minIndex = i;	
		}
	}
	std::cout << GRN "From " BLU << sorted[minIndex - 1] << GRN " to " BLU << sorted[minIndex] << RST << std::endl;
	return (minSpan);
}
int Span::longestSpan() {
	std::vector<int> sorted = _vector;

	if (_vector.size() < 2)
		throw std::logic_error("Not enough numbers to get longest span");
	std::sort(sorted.begin(), sorted.end());
	std::cout << GRN "From " BLU << sorted.front() << GRN " to " BLU << sorted.back() << RST << std::endl;
	return (sorted.back() - sorted.front());
}

void Span::addNumber(int n) {
	if (_vector.size() >= _size)
		throw std::out_of_range("Span is FULL");
	_vector.push_back(n);
}

void Span::addRange(std::vector<int>::iterator begin, std::vector<int>::iterator end) {
	if (std::distance(begin, end) + _vector.size() > _size)
		throw std::out_of_range("Span is FULL");
	_vector.insert(_vector.end(), begin, end);
}

size_t Span::getSize() const {
	return _vector.size();
}

int Span::getElement(unsigned int index) const {
	if (index >= _vector.size())
		throw std::out_of_range("Index out of range");
	return _vector[index];
}

std::ostream &operator<<(std::ostream &os, const Span &span)
{
	os << YEL "Span vector: " RST;
	for (size_t i = 0; i < span.getSize(); i++) {
		os << BLU << span.getElement(i) << RST;
		if (i < span.getSize() - 1)
			os << YEL ", " RST;
	}
	return os;
}