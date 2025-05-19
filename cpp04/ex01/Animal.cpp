#include "Animal.hpp"

Animal::Animal() : _type("Unspecified") {
	std::cout << BOLD << "Unspecified animal created" << RST << std::endl;
}

Animal::Animal(std::string type) : _type(type) {
	std::cout << BOLD "A " << BLU << type << BOLD <<" animal type was created" << std::endl;
}

Animal::~Animal() {
	std::cout << BLU << this->_type << BOLD << " animal destroyed" << RST << std::endl;
}

Animal::Animal(const Animal &copy) {
	std::cout << BLU << this->_type << BOLD << " animal copied" << RST << std::endl;
	*this = copy;
}

Animal &Animal::operator=(const Animal &copy) {
	if (this != &copy) {
		this->_type = copy._type;
		std::cout << BLU << this->_type << BOLD << " animal assigned" << RST << std::endl;
	}
	return *this;
}
std::string	Animal::getType(void) const {
	return (this->_type);
}

void	Animal::makeSound(void) const {
	std::cout << RED << "Abstract class shouldn't have a sound" << RST << std::endl;
}