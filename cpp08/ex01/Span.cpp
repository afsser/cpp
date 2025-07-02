#ifndef SPAN_HPP
# define SPAN_HPP
# include "Span.hpp"

Span::Span(unsigned int n) : _size(n), _count(0) {
	_array = new int[n];
}
Span::Span(const Span &other) : _size(other._size), _count(other._count) {
	_array = new int[_size];
	for (unsigned int i = 0; i < _count; ++i) {
		_array[i] = other._array[i];
	}
}
Span &Span::operator=(const Span &other) {
	if (this != &other) {
		delete[] _array;
		_size = other._size;
		_count = other._count;
		_array = new int[_size];
		for (unsigned int i = 0; i < _count; ++i) {
			_array[i] = other._array[i];
		}
	}
	return *this;
}
Span::~Span() {
	delete[] _array;
}
#endif