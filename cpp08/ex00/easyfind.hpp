#ifndef EASYFIND_HPP
# define EASYFIND_HPP

# include <algorithm>
# include <stdexcept>

template <typename T>
typename T::const_iterator easyfind(T const &hay, int needle) {
	typename T::const_iterator it;

	it = std::find(hay.begin(), hay.end(), needle);
	if (it == hay.end())
		throw std::runtime_error("Element not found");
	return it;
}


#endif