#include "WrongCat.hpp"

WrongCat::WrongCat() : WrongAnimal("WrongCat") {
	std::cout << BLU << "WrongCat" << YEL <<" created" << RST << std::endl;
}
WrongCat::~WrongCat() {
	std::cout << BLU << this->_type << YEL << " destroyed" << RST << std::endl;
}
WrongCat::WrongCat(const WrongCat &copy) : WrongAnimal(copy) {
	std::cout << BLU << copy._type << BOLD << " copied" << RST << std::endl;
	*this = copy;
}
WrongCat &WrongCat::operator=(const WrongCat &copy) {
	if (this != &copy) {
		this->_type = copy._type;
		std::cout << BLU << this->_type << BOLD << " assigned" << RST << std::endl;
	}
	return *this;
}
void	WrongCat::makeSound(void) const {
	std::cout << RED << "YEEEEEEEEEEEEEEEEEEEEEEEEEEHAAA" << RST << std::endl;
}
