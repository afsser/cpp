#ifndef FRAGTRAP_HPP
# define FRAGTRAP_HPP

# include "ClapTrap.hpp"

class FragTrap : public ClapTrap
{
public:
	FragTrap();
	~FragTrap();
	FragTrap &operator=(const FragTrap &copy);
	FragTrap(const FragTrap &copy);
	FragTrap(std::string name);
	void	highFiveGuys(void);
};

#endif