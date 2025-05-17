#ifndef SCAVTRAP_HPP
# define SCAVTRAP_HPP

# include "ClapTrap.hpp"

class ScavTrap : public ClapTrap
{
public:
	ScavTrap();
	~ScavTrap();
	ScavTrap &operator=(const ScavTrap &copy);
	ScavTrap(const ScavTrap &copy);
	ScavTrap(std::string name);
	void	attack(const std::string& target);
	void	guardGate(void);
};

#endif