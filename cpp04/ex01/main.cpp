#include "Animal.hpp"
#include "Cat.hpp"
#include "Dog.hpp"

#include <cstdlib>

class Brain;

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
		std::cout << YEL << "A ";
		std::cout << BLU << animals[i]->getType();
		std::cout << YEL << " had an idea: ";
		std::cout << GRN << animals[i]->getBrain()->getIdeas()[0] << std::endl;
	}
	for (int i = 0; i < qty; i++) {
		delete animals[i];
	}

	std::cout << std::endl;
	std::cout << GRN << "------------------------------" << RST << std::endl;
	std::cout << std::endl;
	
	std::cout << BLU << "Deep copy test:" << RST << std::endl;

	Dog basic;
	{
		Dog tmp = basic;
	}
	
	std::cout << std::endl;
	std::cout << GRN << "------------------------------" << RST << std::endl;
	std::cout << std::endl;
	
	std::cout << BLU << "Deep copy test:" << RST << std::endl;
	Animal *OG = new Cat();
	Animal *bootleg = new Cat(*(Cat *)OG);
	
	OG->getBrain()->getIdeas()[0] = "I am the original";
	bootleg->getBrain()->getIdeas()[0] = "I am the copy";
	
	std::cout << BLU << "OG" << YEL << " had an idea: ";
	std::cout << GRN << OG->getBrain()->getIdeas()[0] << std::endl;
	std::cout << BLU << "bootleg" << YEL << " had an idea: ";
	std::cout << GRN << bootleg->getBrain()->getIdeas()[0] << std::endl;
	delete OG;
	delete bootleg;
	return (EXIT_SUCCESS);
}
