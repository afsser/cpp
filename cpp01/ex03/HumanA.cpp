#include "HumanA.hpp"

HumanA::HumanA(std::string name, Weapon& weapon) :
	_name(name), _weapon(weapon) {}

HumanA::~HumanA() {}

void HumanA::attack() const
{
	std::cout << CYAN << this->_name << GREEN << " attacks with their " << RED << this->_weapon.getType() << END << std::endl;
}

