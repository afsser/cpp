#include "Dog.hpp"

Dog::Dog() : Animal("Dog"){
	std::cout << BLU << "Dog" << YEL <<" created" << RST << std::endl;
}
Dog::~Dog() {
	std::cout << BLU << this->_type << YEL << " destroyed" << RST << std::endl;
}
Dog::Dog(const Dog &copy) : Animal(copy) {
	std::cout << BLU << copy._type << BOLD << " copied" << RST << std::endl;
	*this = copy;
}
Dog &Dog::operator=(const Dog &copy) {
	if (this != &copy) {
		this->_type = copy._type;
		std::cout << BLU << this->_type << BOLD << " assigned" << RST << std::endl;
	}
	return *this;
}
void	Dog::makeSound(void) const {
	std::cout << RED << "Bark bark bark" << RST << std::endl;
}
