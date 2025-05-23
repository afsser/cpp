#ifndef ANIMAL_H
# define ANIMAL_H

# include <iostream>

# define BOLD "\033[1;37m"
# define RED "\033[1;31m"
# define GRN "\033[1;32m"
# define YEL "\033[1;33m"
# define BLU "\033[1;36m"
# define RST "\033[0m"

class Brain;

class Animal
{
protected:
	std::string 	_type;
public:
	Animal();
	Animal(std::string type);
	Animal &operator=(const Animal &copy);
	Animal(const Animal &copy);
	virtual ~Animal();
	std::string 	getType(void) const;
	virtual void	makeSound(void) const;
	virtual Brain	*getBrain(void) const = 0;
};

#endif