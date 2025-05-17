#include "ClapTrap.hpp"

ClapTrap::ClapTrap() {
	std::cout << BOLD << "Unnamed ClapTrap created" << RST << std::endl;
}

ClapTrap::~ClapTrap() {
	std::cout << BOLD << "ClapTrap " << BLU << this->_name << BOLD << " destroyed" << RST << std::endl;
}

ClapTrap::ClapTrap(const ClapTrap &copy) {
	std::cout << BOLD << "ClapTrap " << BLU << this->_name << BOLD << " copied" << RST << std::endl;
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

void	ClapTrap::setAtkDmg(unsigned int atkDmg) {
	this->_atkDmg = atkDmg;
	std::cout << YEL << "ClapTrap " << BLU << this->_name << YEL << "'s attack damage set to " << RED << this->_atkDmg << YEL << "!" << RST << std::endl;
}

void	ClapTrap::attack(const std::string& target) {
	if (this->_ep > 0) {
		this->_ep--;
		std::cout << YEL << "ClapTrap " << BLU << this->_name << YEL << " attacks " << target << " with " << RED << this->_atkDmg << YEL << " damage!" << RST << std::endl;
	}
	else if (this->_ep == 0) {
		std::cout << YEL << this->_name << " don't have enough energy to attack " << target << " !" << RST << std::endl;
	}
}

void	ClapTrap::takeDamage(unsigned int amount) {
	if (this->_hp > 0) {
		this->_hp -= amount;
		std::cout << YEL << "ClapTrap " << BLU << this->_name << YEL << " takes " << RED << amount << YEL << " damage!" << RST << std::endl;
		std::cout << YEL << "ClapTrap " << BLU << this->_name << YEL << " now have " << RED << this->_hp << YEL << " hitpoints!" << RST << std::endl;
	}
	else if (this->_hp == 0) {
		std::cout << YEL << "ClapTrap " << BLU << this->_name << RED << " is already fainted!" << RST << std::endl;
	}
}

void	ClapTrap::beRepaired(unsigned int amount) {
	if (this->_ep > 0 && this->_hp < 10) {
		this->_ep--;
		this->_hp += amount;
		std::cout << YEL << "ClapTrap " << BLU << this->_name << YEL << " got repaired by " << GRN << amount << YEL << " points!" << RST << std::endl;
	}
	else if (this->_hp == 10) {
		std::cout << YEL << "ClapTrap " << BLU << this->_name << GRN << " is already at full health!" << RST << std::endl;
	}
	else if (this->_ep == 0) {
		std::cout << YEL << "ClapTrap " << BLU << this->_name << YEL << " don't have enough energy to repair!" << RST << std::endl;
	}
}

ClapTrap::ClapTrap(std::string name) : _name(name), _hp(10), _ep(10), _atkDmg(0) {
	std::cout << BOLD << "ClapTrap " << BLU << name << BOLD <<" created" << std::endl;
}
