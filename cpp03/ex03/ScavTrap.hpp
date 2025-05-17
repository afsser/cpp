#ifndef SCAVTRAP_HPP
# define SCAVTRAP_HPP

# include "ClapTrap.hpp"

class ScavTrap : virtual public ClapTrap
{
public:
	ScavTrap();
	~ScavTrap();
	ScavTrap &operator=(const ScavTrap &copy);
	ScavTrap(const ScavTrap &copy);
	ScavTrap(std::string name);
	void	guardGate(void);
	static const unsigned int	_defaultHp = 100;
	static const unsigned int	_defaultEp = 50;
	static const unsigned int	_defaultAtkDmg = 20;
};

#endif