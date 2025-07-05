#ifndef MUTANTSTACK_HPP
# define MUTANTSTACK_HPP

# include <stdexcept>
# include <iostream>
# include <stack>

template <typename T, typename Container = std::deque<T>>
class MutantStack : public std::stack<T, Container> {

public:
	MutantStack();
	MutantStack(const MutantStack &other);
	MutantStack &operator=(const MutantStack &other);
	~MutantStack();

	void	push(int n);
	void	pop();
	int		top() const;
	bool	empty() const;
	size_t	size() const;

	typedef typename Container::iterator iterator;
	typedef typename Container::const_iterator const_iterator;
	iterator begin() {
		return this->c.begin();
	}
	iterator end() {
		return this->c.end();
	}
	const_iterator begin() const {
		return this->c.begin();
	}
	const_iterator end() const {
		return this->c.end();
	}
};
std::ostream &operator<<(std::ostream &os, const MutantStack &mutantStack);

#endif