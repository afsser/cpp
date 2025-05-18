#ifndef FRAGTRAP_HPP
# define FRAGTRAP_HPP

# include "ClapTrap.hpp"

class FragTrap : virtual public ClapTrap
{
public:
	FragTrap();
	~FragTrap();
	FragTrap &operator=(const FragTrap &copy);
	FragTrap(const FragTrap &copy);
	FragTrap(std::string name);
	void	highFiveGuys(void);
	static const unsigned int	_defaultHp = 100;
	static const unsigned int	_defaultEp = 100;
	static const unsigned int	_defaultAtkDmg = 30;
};

#endif