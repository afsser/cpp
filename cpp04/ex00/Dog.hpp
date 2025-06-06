#ifndef DOG_HPP
# define DOG_HPP

# include "Animal.hpp"

class Dog : public Animal
{
public:
	Dog();
	~Dog();
	Dog &operator=(const Dog &copy);
	Dog(const Dog &copy);
	void	makeSound(void) const;
};

#endif