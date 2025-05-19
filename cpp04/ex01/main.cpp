#include "Animal.hpp"
#include "Cat.hpp"
#include "Dog.hpp"

#include <cstdlib>

int	main(int argc, char **argv) {

	if (argc != 2 || std::atoi(argv[1]) <= 0 || std::atoi(argv[1]) % 2 != 0) {
		std::cout << RED << "Please enter a positive and even number" << RST << std::endl;
		return (EXIT_FAILURE);
	}
	int qty = std::atoi(argv[1]);
	Animal	*animals[qty];
	for (int i = 0; i < (qty / 2); i++) {
		animals[i] = new Cat();
		animals[i]->makeSound();
	}
	for (int i = (qty / 2); i < qty; i++) {
		animals[i] = new Dog();
		animals[i]->makeSound();
	}
	for (int i = 0; i < qty; i++) {
		if (animals[i]->getType() == "Cat")
		{
			Cat *cat = dynamic_cast<Cat *>(animals[i]);
			if (!cat)
			{
				std::cout << RED << "Error: dynamic_cast failed" << RST << std::endl;
				return (EXIT_FAILURE);
			}
			std::cout << YEL << "A ";
			std::cout << BLU << animals[i]->getType();
			std::cout << YEL << " had an idea: ";
			std::cout << GRN << cat->getBrain()->getIdeas()[0] << std::endl;
		}
		else if (animals[i]->getType() == "Dog")
		{
			Dog *dog = dynamic_cast<Dog *>(animals[i]);
			if (!dog)
			{
				std::cout << RED << "Error: dynamic_cast failed" << RST << std::endl;
				return (EXIT_FAILURE);
			}
			std::cout << YEL << "A ";
			std::cout << BLU << animals[i]->getType();
			std::cout << YEL << " had an idea: ";
			std::cout << GRN << dog->getBrain()->getIdeas()[0] << std::endl;
		}
	}
	for (int i = 0; i < qty; i++) {
		delete animals[i];
	}
	return (EXIT_SUCCESS);
}
