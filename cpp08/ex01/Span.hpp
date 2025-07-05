#ifndef SPAN_HPP
# define SPAN_HPP

# include <stdexcept>
# include <iostream>
# include <vector>

class Span {
private:
	std::vector<int>	_vector;
	unsigned int		_size;
public:
	Span(unsigned int n);
	Span(const Span &other);
	Span &operator=(const Span &other);
	~Span();

	void	addNumber(int n);
	void	addRange(std::vector<int>::iterator begin, std::vector<int>::iterator end);
	int		shortestSpan();
	int		longestSpan();
	int		getElement(unsigned int index) const;
	size_t	getSize() const;
};
std::ostream &operator<<(std::ostream &os, const Span &span);

#endif