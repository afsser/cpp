#include "HumanB.hpp"

HumanB::HumanB(std::string name) :
	_name(name), _weapon(NULL) {}

HumanB::~HumanB() {}

void HumanB::attack() const
{
	if (this->_weapon == NULL)
	{
		std::cout << CYAN << this->_name << ORANGE <<" has no weapon to attack with." << std::endl;
		return;
	}
	std::cout << CYAN << this->_name << GREEN << " attacks with their " << RED << this->_weapon->getType() << END << std::endl;
}

void HumanB::setWeapon(Weapon* weapon)
{
	this->_weapon = weapon;
}