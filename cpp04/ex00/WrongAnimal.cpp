#include "WrongAnimal.hpp"

WrongAnimal::WrongAnimal() : _type("Unspecified and Wrong Animal") {
	std::cout << BOLD << "Unspecified and" << RED << " wrong" << BOLD << " animal created" << RST << std::endl;
}

WrongAnimal::WrongAnimal(std::string type) : _type(type) {
	std::cout << BOLD "A " << BLU << type << BOLD <<" animal type was created" << std::endl;
}

WrongAnimal::~WrongAnimal() {
	std::cout << BLU << this->_type << BOLD << " animal destroyed" << RST << std::endl;
}

WrongAnimal::WrongAnimal(const WrongAnimal &copy) {
	std::cout << BLU << this->_type << BOLD << " animal copied" << RST << std::endl;
	*this = copy;
}

WrongAnimal &WrongAnimal::operator=(const WrongAnimal &copy) {
	if (this != &copy) {
		this->_type = copy._type;
		std::cout << BLU << this->_type << BOLD << " animal assigned" << RST << std::endl;
	}
	return *this;
}
std::string	WrongAnimal::getType(void) const {
	return (this->_type);
}

void	WrongAnimal::makeSound(void) const {
	std::cout << RED << "SHRIEEEEEEK" << RST << std::endl;
}