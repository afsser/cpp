#ifndef WRONGCAT_HPP
# define WRONGCAT_HPP

# include "WrongAnimal.hpp"

class WrongCat : public WrongAnimal
{
public:
	WrongCat();
	~WrongCat();
	WrongCat &operator=(const WrongCat &copy);
	WrongCat(const WrongCat &copy);
	void	makeSound(void) const;
};

#endif