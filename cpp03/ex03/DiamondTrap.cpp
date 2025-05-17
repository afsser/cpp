#include "DiamondTrap.hpp"

DiamondTrap::DiamondTrap() : ClapTrap("Default_clap_name"), ScavTrap(), FragTrap(){
	std::cout << BOLD << "Default DiamondTrap created" << RST << std::endl;
	this->setName("Default");
	this->_ep = ScavTrap::_defaultEp;
	this->_hp = FragTrap::_defaultHp;
	this->_atkDmg = FragTrap::_defaultAtkDmg;
	this->_maxHp = this->_hp;
	this->_maxEp = this->_ep;
}
DiamondTrap::DiamondTrap(std::string name) : ClapTrap(name + "_clap_name"), ScavTrap(name), FragTrap(name), _name(name){
	std::cout << BOLD << "DiamondTrap " << BLU << this->_name << BOLD << " created" << RST << std::endl;
	this->_ep = ScavTrap::_defaultEp;
	this->_hp = FragTrap::_defaultHp;
	this->_atkDmg = FragTrap::_defaultAtkDmg;
	this->_maxHp = this->_hp;
	this->_maxEp = this->_ep;
}
DiamondTrap::~DiamondTrap() {
	std::cout << BOLD << "DiamondTrap " << BLU << this->_name << BOLD << " destroyed" << RST << std::endl;
}
DiamondTrap::DiamondTrap(const DiamondTrap &copy) {
	std::cout << BOLD << "DiamondTrap " << BLU << this->_name << BOLD << " copied" << RST << std::endl;
	*this = copy;
}
DiamondTrap &DiamondTrap::operator=(const DiamondTrap &copy) {
	std::cout << BOLD << "DiamondTrap assigned" << RST << std::endl;
	if (this != &copy) {
		this->_name = copy._name;
		this->_hp = copy._hp;
		this->_ep = copy._ep;
		this->_atkDmg = copy._atkDmg;
		this->_maxHp = copy._maxHp;
		this->_maxEp = copy._maxEp;
		this->ClapTrap::_name = copy.ClapTrap::_name;
	}
	return *this;
}

void DiamondTrap::whoAmI(void) const {
	std::cout << YEL << "DiamondTrap " << BLU << this->_name << YEL << " is also known as " << BLU << this->ClapTrap::_name << RST << std::endl;
}

void DiamondTrap::showStatus(void) const {
	std::cout << YEL << "DiamondTrap " << BLU << this->_name << YEL << " has " ;
	std::cout<< GRN << this->_hp << YEL << " hitpoints, ";
	std::cout << BLU << this->_ep << YEL << " energy points and ";
	std::cout << RED << this->_atkDmg << YEL << " attack damage!" << RST << std::endl;
}

void DiamondTrap::attack(const std::string& target) {
	ScavTrap::attack(target);
}