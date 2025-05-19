#include "Cat.hpp"

Cat::Cat() : Animal("Cat") {
	std::cout << BLU << "Cat" << YEL <<" created" << RST << std::endl;
}
Cat::~Cat() {
	std::cout << BLU << this->_type << YEL << " destroyed" << RST << std::endl;
}
Cat::Cat(const Cat &copy) : Animal(copy) {
	std::cout << BLU << copy._type << BOLD << " copied" << RST << std::endl;
	*this = copy;
}
Cat &Cat::operator=(const Cat &copy) {
	if (this != &copy) {
		this->_type = copy._type;
		std::cout << BLU << this->_type << BOLD << " assigned" << RST << std::endl;
	}
	return *this;
}
void	Cat::makeSound(void) const {
	std::cout << RED << "Prrrrrrrrrrrrrrrrrrrrrrrr" << RST << std::endl;
}
