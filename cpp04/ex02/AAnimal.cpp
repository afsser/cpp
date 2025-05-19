#include "AAnimal.hpp"

AAnimal::AAnimal() : _type("Unspecified") {
	std::cout << BOLD << "Unspecified animal created" << RST << std::endl;
}

AAnimal::AAnimal(std::string type) : _type(type) {
	std::cout << BOLD "A " << BLU << type << BOLD <<" animal type was created" << std::endl;
}

AAnimal::~AAnimal() {
	std::cout << BLU << this->_type << BOLD << " animal destroyed" << RST << std::endl;
}

AAnimal::AAnimal(const AAnimal &copy) {
	std::cout << BLU << this->_type << BOLD << " animal copied" << RST << std::endl;
	*this = copy;
}

AAnimal &AAnimal::operator=(const AAnimal &copy) {
	if (this != &copy) {
		this->_type = copy._type;
		std::cout << BLU << this->_type << BOLD << " animal assigned" << RST << std::endl;
	}
	return *this;
}
std::string	AAnimal::getType(void) const {
	return (this->_type);
}
