#ifndef WRONGANIMAL_H
# define WRONGANIMAL_H

# include <iostream>

# define BOLD "\033[1;37m"
# define RED "\033[1;31m"
# define GRN "\033[1;32m"
# define YEL "\033[1;33m"
# define BLU "\033[1;36m"
# define RST "\033[0m"

class WrongAnimal
{
protected:
	std::string 	_type;
public:
	WrongAnimal();
	WrongAnimal(std::string type);
	WrongAnimal &operator=(const WrongAnimal &copy);
	WrongAnimal(const WrongAnimal &copy);
	~WrongAnimal();
	std::string 	getType(void) const;
	void	makeSound(void) const;
};

#endif