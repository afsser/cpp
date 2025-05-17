#include "ScavTrap.hpp"

ScavTrap::ScavTrap() : ClapTrap(){
	std::cout << BOLD << "Unnamed ScavTrap created" << RST << std::endl;
	this->setAtkDmg(20);
	this->setHp(100);
	this->_maxHp = 100;
	this->setEp(50);
	this->_maxEp = 50;
}
ScavTrap::ScavTrap(std::string name) : ClapTrap(name){
	this->setName(name);
	std::cout << BOLD << "ScavTrap " << BLU << this->getName() << BOLD << " created" << RST << std::endl;
	this->setAtkDmg(20);
	this->setHp(100);
	this->_maxHp = 100;
	this->setEp(50);
	this->_maxEp = 50;
}
ScavTrap::~ScavTrap() {
	std::cout << BOLD << "ScavTrap " << BLU << this->getName() << BOLD << " destroyed" << RST << std::endl;
}
ScavTrap::ScavTrap(const ScavTrap &copy) {
	std::cout << BOLD << "ScavTrap " << BLU << this->getName() << BOLD << " copied" << RST << std::endl;
	*this = copy;
}
ScavTrap &ScavTrap::operator=(const ScavTrap &copy) {
	std::cout << BOLD << "ScavTrap assigned" << RST << std::endl;
	if (this != &copy) {
		this->setName(copy.getName());
		this->setHp(copy.getHp());
		this->setEp(copy.getEp());
		this->setAtkDmg(copy.getAtkDmg());
	}
	return *this;
}
void	ScavTrap::attack(const std::string& target) {
	if (this->_ep > 0) {
		this->_ep--;
		std::cout << YEL << "The relentless " << BLU << this->_name << YEL << " hits " << target << " with " << RED << this->_atkDmg << YEL << " damage!" << RST << std::endl;
	}
	else if (this->_ep == 0) {
		std::cout << YEL << this->_name << " have no energy to attack " << target << " !" << RST << std::endl;
	}
}
void ScavTrap::guardGate(void) {
	if (this->getEp() > 0) {
		this->setEp(this->getEp() - 5);
		std::cout << YEL << "ScavTrap " << BLU << this->getName() << YEL << " is now in Gate Keeper mode!" << RST << std::endl;
	}
	else if (this->getEp() == 0) {
		std::cout << YEL << this->getName() << " don't have enough energy to enter Gate Keeper mode!" << RST << std::endl;
	}
}