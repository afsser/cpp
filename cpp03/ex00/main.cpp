#include "ClapTrap.hpp"

#include <cstdlib>

int	main(void) {
	ClapTrap ed = ClapTrap("Ed");
	ClapTrap rob = ClapTrap("Rob");
	ClapTrap rud = ClapTrap("Rud");
	ed.attack(rud.getName());
	rud.takeDamage(ed.getAtkDmg());
	ed.setAtkDmg(5);
	ed.attack(rud.getName());
	rud.takeDamage(ed.getAtkDmg());
	rud.beRepaired(5);
	rud.beRepaired(5);
	ClapTrap ross = ClapTrap("Ross");
	rud.setAtkDmg(5);
	rud.attack(ross.getName());
	ross.takeDamage(rud.getAtkDmg());
	rud.attack(ross.getName());
	ross.takeDamage(rud.getAtkDmg());
	rud.attack(ross.getName());
	ross.takeDamage(rud.getAtkDmg());


	return (EXIT_SUCCESS);
}