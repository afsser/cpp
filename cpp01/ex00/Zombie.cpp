#include "Zombie.hpp"

Zombie::Zombie(void)
{
	this->_name = "Unnamed";
}

Zombie::~Zombie(void)
{
	std::cout << this->_name << " has been destroyed." << std::endl;
}

std::string Zombie::getName(void) const
{
	return (this->_name);
}
void Zombie::setName(const std::string &name)
{
	this->_name = name;
}
void Zombie::announce(void) const
{
	std::cout << this->_name << ": BraiiiiiiinnnzzzZ..." << std::endl;
}
