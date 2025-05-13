#include "ClapTrap.hpp"

ClapTrap::ClapTrap() {
	std::cout << BOLD << "Unnamed ClapTrap created" << RST << std::endl;
}

ClapTrap::~ClapTrap() {
	std::cout << BOLD << "ClapTrap" << this->_name << "destroyed" << RST << std::endl;
}

ClapTrap::ClapTrap(const ClapTrap &copy) {
	std::cout << BOLD << "ClapTrap " << this->_name << " copied" << RST << std::endl;
	*this = copy;
}

ClapTrap &ClapTrap::operator=(const ClapTrap &copy) {
	std::cout << BOLD << "ClapTrap assigned" << RST << std::endl;
	if (this != &copy) {
		this->_name = copy._name;
		this->_hp = copy._hp;
		this->_ep = copy._ep;
		this->_atkDmg = copy._atkDmg;
	}
	return *this;
}

std::string	ClapTrap::getName(void) const {
	return (this->_name);
}

unsigned int	ClapTrap::getAtkDmg(void) const {
	return (this->_atkDmg);
}

void	ClapTrap::attack(const std::string& target) {
	if (this->_ep > 0) {
		this->_ep--;
		std::cout << YEL << "ClapTrap " << this->_name << " attacks " << target << ", causing " << RED << this->_atkDmg << YEL << " points of damage!" << RST << std::endl;
	}
	else if (this->_ep == 0) {
		std::cout << YEL << this->_name << " don't have enough energy to attack " << target << " !" << RST << std::endl;
	}
}

void	ClapTrap::takeDamage(unsigned int amount) {
	if (this->_hp > 0) {
		this->_hp -= amount;
		std::cout << YEL << "ClapTrap " << this->_name << " takes " << RED << amount << YEL << " damage!" << RST << std::endl;
		std::cout << YEL << "ClapTrap " << this->_name << " now have " << RED << this->_hp << YEL << " hitpoints!" << RST << std::endl;
	}
	else if (this->_hp == 0) {
		std::cout << YEL << this->_name << " is already fainted!" << RST << std::endl;
	}
}

void	ClapTrap::beRepaired(unsigned int amount) {
	if (this->_ep > 0) {
		this->_ep--;
		this->_hp += amount;
		std::cout << YEL << "ClapTrap " << this->_name << " got repaired by " << GRN << amount << YEL << " points!" << RST << std::endl;
	}
	else if (this->_ep == 0) {
		std::cout << YEL << this->_name << " don't have enough energy to repair!" << RST << std::endl;
	}
}

ClapTrap::ClapTrap(std::string name) : _name(name), _hp(10), _ep(10), _atkDmg(0) {
	std::cout << "ClapTrap " << name << " created" << std::endl;
}
