#ifndef SPAN_HPP
# define SPAN_HPP

# include <stdexcept>
# include <iostream>

class Span {
private:
	std::vector<int>	_vector;
	unsigned int		_size;
	unsigned int		_count;
public:
	Span(unsigned int n);
	Span(const Span &other);
	Span &operator=(const Span &other);
	~Span();
	void addNumber(int n);
	int shortestSpan() const;
	int longestSpan() const;
};

#endif