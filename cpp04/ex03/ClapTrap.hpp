#ifndef CLAPTRAP_H
# define CLAPTRAP_H

# include <iostream>

# define BOLD "\033[1;37m"
# define RED "\033[1;31m"
# define GRN "\033[1;32m"
# define YEL "\033[1;33m"
# define BLU "\033[1;36m"
# define RST "\033[0m"

class ClapTrap
{
protected:
	std::string 	_name;
	unsigned int	_hp;
	unsigned int	_ep;
	unsigned int	_atkDmg;
	unsigned int	_maxHp;
	unsigned int	_maxEp;

public:
	ClapTrap();
	~ClapTrap();
	ClapTrap &operator=(const ClapTrap &copy);
	ClapTrap(const ClapTrap &copy);
	ClapTrap(std::string name);
	std::string 	getName(void) const;
	unsigned int	getAtkDmg(void) const;
	unsigned int	getHp(void) const;
	unsigned int	getEp(void) const;
	void			setName(std::string name);
	void			setHp(unsigned int hp);
	void			setEp(unsigned int ep);
	void			setAtkDmg(unsigned int atkDmg);
	void			attack(const std::string& target);
	void			takeDamage(unsigned int amount);
	void			beRepaired(unsigned int amount);
};


#endif