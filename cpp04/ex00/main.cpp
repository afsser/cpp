#include "Animal.hpp"
#include "Cat.hpp"
#include "Dog.hpp"
#include "WrongAnimal.hpp"
#include "WrongCat.hpp"

#include <cstdlib>

int	main(void) {
	Animal		*meta = new Animal();
	Animal		*zaza = new Cat();
	Animal		*cora = new Dog();

	std::cout  << std::endl;
	std::cout << BLU << "meta sound:" << RST << std::endl;
	meta->makeSound();
	std::cout  << std::endl;
	std::cout << BLU << "zaza sound:" << RST << std::endl;
	zaza->makeSound();
	std::cout  << std::endl;
	std::cout << BLU << "cora sound:" << RST << std::endl;
	cora->makeSound();
	std::cout  << std::endl;
	std::cout << BLU << "zaza" << GRN << " is a " << zaza->getType() << RST << std::endl;
	std::cout << BLU << "cora" << GRN << " is a " << cora->getType() << RST << std::endl;
	std::cout  << std::endl;
	delete zaza;
	delete cora;
	delete meta;

	std::cout << std::endl << GRN << "-------------------------------------" << RST << std::endl << std::endl;

	WrongAnimal	*wrongMeta = new WrongAnimal();
	WrongAnimal	*wrongZaza = new WrongCat();

	std::cout  << std::endl;
	std::cout << BLU << "wrongMeta sound:" << RST << std::endl;
	wrongMeta->makeSound();
	std::cout  << std::endl;
	std::cout << BLU << "wrongZaza sound:" << RST << std::endl;
	wrongZaza->makeSound();
	std::cout  << std::endl;
	std::cout << BLU << "wrongZaza" << GRN << " is a " << wrongZaza->getType() << RST << std::endl;
	std::cout << BLU << "wrongMeta" << GRN << " is a " << wrongMeta->getType() << RST << std::endl;
	std::cout  << std::endl;
	delete wrongZaza;
	delete wrongMeta;

	return (EXIT_SUCCESS);
}
