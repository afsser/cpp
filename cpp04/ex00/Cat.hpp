#ifndef CAT_HPP
# define CAT_HPP

# include "Animal.hpp"

class Cat : public Animal
{
public:
	Cat();
	~Cat();
	Cat &operator=(const Cat &copy);
	Cat(const Cat &copy);
	void	makeSound(void) const;
};

#endif