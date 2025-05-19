#include "Cat.hpp"
#include "Brain.hpp"

Cat::Cat() : AAnimal("Cat"), _brain(new Brain()) {
	std::cout << BLU << "Cat" << YEL <<" created" << RST << std::endl;
}
Cat::~Cat() {
	delete this->_brain;
	std::cout << BLU << this->_type << YEL << " destroyed" << RST << std::endl;
}
Cat::Cat(const Cat &copy) : AAnimal(copy) {
	this->_brain = new Brain(*copy._brain);
	std::cout << BLU << copy._type << BOLD << " copied" << RST << std::endl;
}
Cat &Cat::operator=(const Cat &copy) {
	if (this != &copy) {
		AAnimal::operator=(copy);
		if (this->_brain)
			delete this->_brain;
		this->_brain = new Brain(*copy._brain);
		std::cout << BLU << this->_type << BOLD << " assigned" << RST << std::endl;
	}
	return *this;
}
void	Cat::makeSound(void) const {
	std::cout << RED << "Prrrrrrrrrrrrrrrrrrrrrrrr" << RST << std::endl;
}
Brain	*Cat::getBrain(void) const {
	return (this->_brain);
}
