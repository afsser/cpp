#include "ClapTrap.hpp"
#include "ScavTrap.hpp"
#include "FragTrap.hpp"

#include <cstdlib>

int	main(void) {
	ScavTrap ed = ScavTrap("Ed");
	FragTrap rud = FragTrap("Rud");
	rud.highFiveGuys();
	ed.attack(rud.getName());
	rud.takeDamage(ed.getAtkDmg());
	ed.setAtkDmg(5);
	ed.attack(rud.getName());
	rud.takeDamage(ed.getAtkDmg());
	rud.beRepaired(5);
	rud.beRepaired(5);
	rud.attack(ed.getName());
	ed.takeDamage(rud.getAtkDmg());
	rud.attack(ed.getName());
	ed.takeDamage(rud.getAtkDmg());
	rud.attack(ed.getName());
	ed.takeDamage(rud.getAtkDmg());
	rud.attack(ed.getName());
	ed.takeDamage(rud.getAtkDmg());
	rud.attack(ed.getName());
	ed.takeDamage(rud.getAtkDmg());
	rud.attack(ed.getName());
	ed.takeDamage(rud.getAtkDmg());
	rud.attack(ed.getName());
	ed.takeDamage(rud.getAtkDmg());

	return (EXIT_SUCCESS);
}