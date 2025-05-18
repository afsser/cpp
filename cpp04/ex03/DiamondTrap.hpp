#ifndef DIAMONDTRAP_HPP
# define DIAMONDTRAP_HPP

# include "ClapTrap.hpp"
# include "FragTrap.hpp"
# include "ScavTrap.hpp"

class DiamondTrap : public ScavTrap, public FragTrap
{
private:
	std::string	_name;
public:
	DiamondTrap();
	~DiamondTrap();
	DiamondTrap &operator=(const DiamondTrap &copy);
	DiamondTrap(const DiamondTrap &copy);
	DiamondTrap(std::string name);
	void	whoAmI(void) const;
	void	showStatus(void) const;
	void	attack(const std::string& target);
};

#endif