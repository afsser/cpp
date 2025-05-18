#include "FragTrap.hpp"

FragTrap::FragTrap() : ClapTrap(){
	std::cout << BOLD << "Unnamed FragTrap created" << RST << std::endl;
	this->_atkDmg = 30;
	this->_hp = 100;
	this->_maxHp = 100;
	this->_ep = 100;
	this->_maxEp = 100;
}
FragTrap::FragTrap(std::string name) : ClapTrap(name){
	std::cout << BOLD << "FragTrap " << BLU << this->getName() << BOLD << " created" << RST << std::endl;
	this->_atkDmg = 30;
	this->_hp = 100;
	this->_maxHp = 100;
	this->_ep = 100;
	this->_maxEp = 100;
}
FragTrap::~FragTrap() {
	std::cout << BOLD << "FragTrap " << BLU << this->getName() << BOLD << " destroyed" << RST << std::endl;
}
FragTrap::FragTrap(const FragTrap &copy) {
	std::cout << BOLD << "FragTrap " << BLU << this->getName() << BOLD << " copied" << RST << std::endl;
	*this = copy;
}
FragTrap &FragTrap::operator=(const FragTrap &copy) {
	std::cout << BOLD << "FragTrap assigned" << RST << std::endl;
	if (this != &copy) {
		this->setName(copy.getName());
		this->setHp(copy.getHp());
		this->setEp(copy.getEp());
		this->setAtkDmg(copy.getAtkDmg());
	}
	return *this;
}
void FragTrap::highFiveGuys(void) {
	std::cout << YEL << "FragTrap " << BLU << this->getName() << YEL << " is asking for a high five guys!" << RST << std::endl;
}