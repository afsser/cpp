#ifndef CAT_HPP
# define CAT_HPP

# include "Animal.hpp"
# include "Brain.hpp"

class Cat : public Animal
{
private:
	Brain *_brain;
public:
	Cat();
	~Cat();
	Cat &operator=(const Cat &copy);
	Cat(const Cat &copy);
	void	makeSound(void) const;
	Brain	*getBrain(void) const;
};

#endif