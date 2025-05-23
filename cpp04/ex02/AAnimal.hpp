#ifndef AANIMAL_H
# define AANIMAL_H

# include <iostream>

# define BOLD "\033[1;37m"
# define RED "\033[1;31m"
# define GRN "\033[1;32m"
# define YEL "\033[1;33m"
# define BLU "\033[1;36m"
# define RST "\033[0m"

class Brain;

class AAnimal
{
protected:
	std::string 	_type;
public:
	AAnimal();
	AAnimal(std::string type);
	AAnimal &operator=(const AAnimal &copy);
	AAnimal(const AAnimal &copy);
	virtual ~AAnimal();
	std::string 	getType(void) const;
	virtual void	makeSound(void) const = 0;
	virtual Brain	*getBrain(void) const = 0;
};

#endif