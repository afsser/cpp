#include "Dog.hpp"

Dog::Dog() : AAnimal("Dog"), _brain(new Brain()) {
	std::cout << BLU << "Dog" << YEL <<" created" << RST << std::endl;
}
Dog::~Dog() {
	delete this->_brain;
	std::cout << BLU << this->_type << YEL << " destroyed" << RST << std::endl;
}
Dog::Dog(const Dog &copy) : AAnimal(copy) {
	this->_brain = new Brain(*copy._brain);
	std::cout << BLU << copy._type << BOLD << " copied" << RST << std::endl;
}
Dog &Dog::operator=(const Dog &copy) {
	if (this != &copy) {
		AAnimal::operator=(copy);
		if (this->_brain)
			delete this->_brain;
		this->_brain = new Brain(*copy._brain);
		std::cout << BLU << this->_type << BOLD << " assigned" << RST << std::endl;
	}
	return *this;
}
void	Dog::makeSound(void) const {
	std::cout << RED << "Bark bark bark" << RST << std::endl;
}
Brain	*Dog::getBrain(void) const {
	return (this->_brain);
}
